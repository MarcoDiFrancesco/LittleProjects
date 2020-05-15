import json
import os
import uuid

import jicson
import matplotlib.pyplot as plt
import pandas as pd
import requests
import streamlit as st

st.title("Calendar data")
DATA_URL = "/home/marco/projects/LittleProjects/Stramlit/test.json"
CAL_LINK = "https://calendar.google.com/calendar/ical/gglu2jqt34qputlgj37fi6d9p8%40group.calendar.google.com/private-f6841660bb6f830eea31bb2d8d2215cf/basic.ics"


def get_data(link):
    """
    Download ics from Google Calendar, write it to a temp file
    and return data in json form
    """
    ics = requests.get(CAL_LINK).text
    file_path = f"/tmp/{uuid.uuid4()}-calendar.ics"
    with open(file_path, "w") as f:
        f.write(str(ics))
    json = jicson.fromFile(file_path)
    os.remove(file_path)
    return json["VCALENDAR"][0]["VEVENT"]


def date_edit(data):
    """
    Make dates in python date library format
    """
    for d in data:
        for col_name in ["DTSTART", "DTEND", "DTSTAMP", "CREATED", "LAST-MODIFIED"]:
            d[col_name] = pd.to_datetime(d[col_name])
    return data


data = get_data(CAL_LINK)
data = date_edit(data)


df = pd.DataFrame(data, columns=["DTSTART", "SUMMARY"])
df = df[df["SUMMARY"] == "Breakfast"]
hour = df["DTSTART"].dt.hour
minute = df["DTSTART"].dt.minute
minute = hour * 60 + minute
df["value"] = minute
df.set_index("DTSTART")
print(df)
df
st.line_chart(df)

import numpy as np
import pandas as pd
import streamlit as st

st.title("Calendar data")
DATA_URL = "/home/marco/Downloads/eat-calendar.csv"


@st.cache
def load_data(nrows):
    data = pd.read_csv(DATA_URL, nrows=nrows)
    # data.rename(lambda x: str(x).lower(), axis="columns", inplace=True)
    # data[DATE_COLUMN] = pd.to_datetime(data[DATE_COLUMN])
    return data


data_load_state = st.text("Loading data...")
data = load_data(10000)
data_load_state.text("")

print(data)
df = pd.DataFrame(data)
df

import time

import numpy as np
import pandas as pd
import streamlit as st

st.subheader("Underline text in data frame")

dataframe = pd.DataFrame(
    np.random.randn(10, 20), columns=("col %d" % i for i in range(20))
)

st.dataframe(dataframe.style.highlight_max(axis=0))

st.subheader("Add slot to the application")

st.text("This will appear first")

# Appends an empty slot to the app. We'll use this later.
my_slot1 = st.empty()
my_slot2 = st.empty()

st.text("This will appear last")

st.subheader("Add data to chart on the fly")

# Pun in previously created slots
my_slot1.text("This will appear second")
my_slot2.line_chart(np.random.randn(20, 2))

# Animations
progress_bar = st.progress(0)
status_text = st.empty()
chart = st.line_chart(np.random.randn(10, 2))

for i in range(100):
    # Update progress bar
    progress_bar.progress(i)

    new_rows = np.random.randn(10, 2)

    # Update status text
    status_text.text("The latest random number is: %s" % new_rows[-1, 1])

    # Append data to the chart
    chart.add_rows(new_rows)
    time.sleep(0.03)

status_text.text("Done!")

st.subheader("Animations!")
st.balloons()

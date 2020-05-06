import streamlit as st
# To make things easier later, we're also importing numpy and pandas for
# working with sample data.
import numpy as np
import pandas as pd
import time

st.title('My first app')
st.write("Here is my first table:")
st.write(pd.DataFrame({
  'first column': [1, 2, 3, 4],
  'second column': [10, 20, 30, 40]
}))

df = pd.DataFrame({
  'first column': [1, 2, 3, 4],
  'second column': [10, 20, 30, 40]
})
df

"It's possible to add directly text using Streamlit Magic:"
x = 4
x, "squared is", x * x

st.write("It's possible to add charts")
chart_data = pd.DataFrame(
  np.random.randn(20, 3),
  columns=['a', 'b', 'c']
)
st.line_chart(chart_data)

st.write("It's possible to maps")
map_data = pd.DataFrame(
  np.random.randn(1000, 2) / [50, 50] + [37.76, -122.4],
  columns=['lat', 'lon']
)
st.map(map_data)

st.write("It's possible to add checkboxes to hide something")
if st.checkbox('Show dataframe'):
  chart_data = pd.DataFrame(
    np.random.randn(20, 3),
    columns=['a', 'b', 'c']
  )
  st.line_chart(chart_data)

st.write("It's possible to add dropdowns")
option = st.selectbox(
  'Which number do you like best?',
  df['first column']
)
'You selected: ', option

st.write("It's possible to add the dropdown, markdown and slider in the sidebar")
# option = st.sidebar.selectbox(
#   'Which number do you like best?',
#   df['first column']
# )
# 'You selected:', option
# st.sidebar.markdown('Hello')
# st.sidebar.slider('Hello')

# Add a selectbox to the sidebar:
add_selectbox = st.sidebar.selectbox(
    'How would you like to be contacted?',
    ('Email', 'Home phone', 'Mobile phone')
)

# Add a slider to the sidebar:
add_slider = st.sidebar.slider(
    'Select a range of values',
    0.0, 100.0, (25.0, 75.0)
)

st.write("It's possible to add a progress bar if it takes a lot of time to compute")
st.write('Starting a long computation...')
latest_iteration = st.empty()
bar = st.progress(0)
for i in range(100):
  # Update the progress bar with each iteration.
  latest_iteration.text(f'Iteration {i+1}')
  bar.progress(i + 1)
  time.sleep(0.1)

'...and now we\'re done!'


@st.cache
def slow_function(arg1, arg2):
  return output

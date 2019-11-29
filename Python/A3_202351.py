# This file needs to be named A3_202351.py

# Database structure
# Professor (id:int, name:char(50), address:char(50), age:int, height:float)
# Course (cid:char(25), title:char(50), area:char(30), instructor:int)
# Instructor is a FK to Professor,  No attribute can be null.

import psycopg2


# This file needs to be named A3_202351.py

# Database structure
# Professor (id:int, name:char(50), address:char(50), age:int, height:float)
# Course (cid:char(25), title:char(50), area:char(30), instructor:int)
# Instructor is a FK to Professor,  No attribute can be null.

import psycopg2
from time import time_ns

def main():
  conn = psycopg2.connect(dbname="db", user="marco")
  cursor = conn.cursor()
  solve(cursor, conn)

def solve(cursor, conn):
  startTime = time_ns()
  task1(cursor, conn)
  print("Step 1 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task2(cursor, conn)
  print("Step 2 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task3(cursor, conn)
  print("Step 3 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task4(cursor, conn)
  print("Step 4 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task5(cursor, conn)
  print("Step 5 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task6(cursor, conn)
  print("Step 6 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task7(cursor, conn)
  print("Step 7 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task8(cursor, conn)
  print("Step 8 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task9(cursor, conn)
  print("Step 9 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task10(cursor, conn)
  print("Step 10 needs " + str(time_ns() - startTime) + " ns")


def task1(cursor, conn):
  cursor.execute('DROP TABLE IF EXISTS "Course";')
  cursor.execute('DROP TABLE IF EXISTS "Professor";')
  conn.commit()

def task2(cursor, conn):
  cursor.execute(
    'CREATE TABLE "Professor"(id integer NOT NULL PRIMARY KEY,' +
    'name VARCHAR(50) NOT NULL,' +
    'address VARCHAR(50) NOT NULL,' +
    'age INTEGER NOT NULL,' +
    'height FLOAT NOT NULL);'
  )
  cursor.execute(
    'CREATE TABLE "Course"(' + 
    'cid integer NOT NULL PRIMARY KEY,' +
    'title VARCHAR(50) NOT NULL,' +
    'area VARCHAR(30) NOT NULL,' +
    'instructor INTEGER NOT NULL,' +
    'FOREIGN KEY(instructor) REFERENCES "Professor"(id));'
  )
  conn.commit()

def task3(cursor, conn):
  # Height between 184 and 100
  for i in range(1,1000): # Needs to be 999999
    cursor.execute(
      'INSERT INTO "Professor" (id, name, address, age, height)' + 
      'VALUES (' + str(i) + ', \'Professor name\', \'Professor address\', 40, (SELECT RANDOM()*(184-100+1)+100)' + 
      ');'
    )
  cursor.execute(
    'INSERT INTO "Professor" (id, name, address, age, height)' +
    'VALUES (\'1000000\', \'Professor name\', \'Professor address\', 40, 185);'
  )
  conn.commit()

def task4(cursor, conn):
  for i in range(1,1000): # Needs to be 1,000,000
    cursor.execute(
      'INSERT INTO "Course" (cid, title, area, instructor)' +
      'VALUES (' + str(i) + ', \'Course title\', \'Course area\', (SELECT FLOOR(RANDOM()*(1000-1)+1)));'
    )

def task5(cursor, conn):
  a = 0

def task6(cursor, conn):
  a = 0

def task7(cursor, conn):
  a = 0

def task8(cursor, conn):
  a = 0

def task9(cursor, conn):
  a = 0

def task10(cursor, conn):
  a = 0

if __name__ == "__main__":
  main()

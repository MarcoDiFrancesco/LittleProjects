# This file needs to be named A3_202351.py

# Database structure
# Professor (id:int, name:char(50), address:char(50), age:int, height:float)
# Course (cid:char(25), title:char(50), area:char(30), instructor:int)
# Instructor is a FK to Professor,  No attribute can be null.

import psycopg2
from time import time_ns
import sys
import random
import string

LIST_SIZE = 1000000

def main():
  conn = psycopg2.connect(dbname="db", user="marco")
  cursor = conn.cursor()
  solve(cursor)
  conn.commit()

def solve(cursor):
  startTime = time_ns()
  task1(cursor)
  print("Step 1 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task2(cursor)
  print("Step 2 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task3(cursor)
  print("Step 3 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task4(cursor)
  print("Step 4 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task5(cursor)
  print("Step 5 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task6(cursor)
  print("Step 6 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task7(cursor)
  print("Step 7 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task8(cursor)
  print("Step 8 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task9(cursor)
  print("Step 9 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task10(cursor)
  print("Step 10 needs " + str(time_ns() - startTime) + " ns")

  startTime = time_ns()
  task11(cursor)
  print("Step 11 needs " + str(time_ns() - startTime) + " ns")

# Random string lowercase
def stringLow(lenght):
  letters = string.ascii_lowercase
  return ''.join(random.choice(letters) for i in range(lenght))

# Random string uppercase
def stringUp(lenght):
  letters = string.ascii_uppercase
  return ''.join(random.choice(letters) for i in range(lenght))

# Return string with giver characters number
def randWord(min, max):
  lenght = random.randint(min, max)
  return stringUp(1) + stringLow(lenght-1)

# Random integer in string format
def randInt(min, max):
  return str(random.randint(min,max))

# Random float in string format
def randFloat(min, max):
  return str(random.random()*(max-min+1)+min)

def task1(cursor):
  cursor.execute('DROP TABLE IF EXISTS "Course";')
  cursor.execute('DROP TABLE IF EXISTS "Professor";')

def task2(cursor):
  cursor.execute(
    '''
    CREATE TABLE "Professor" (
      id integer NOT NULL PRIMARY KEY,
      name VARCHAR(50) NOT NULL,
      address VARCHAR(50) NOT NULL,
      age INTEGER NOT NULL,
      height FLOAT NOT NULL
    );
    '''
  )
  cursor.execute(
    '''
    CREATE TABLE "Course"(
      cid VARCHAR(25) NOT NULL PRIMARY KEY,
      title VARCHAR(50) NOT NULL,
      area VARCHAR(30) NOT NULL,
      instructor INTEGER NOT NULL,
      FOREIGN KEY(instructor) REFERENCES "Professor"(id)
    );
    '''
  )

def task3(cursor):
  idList = [i for i in range(1,LIST_SIZE)]
  random.shuffle(idList)
  for _ in range(1, len(idList)): # From 1 to 1,000,000
    # Name has two words cammel case
    # Address has one word cammel case and a number
    # Age from 30 to 90
    # Height from 150 cm to 180 cm
    cursor.execute(
      '''
      INSERT INTO "Professor" (
        id,
        name,
        address,
        age,
        height
      ) VALUES (
        ''' + str(idList.pop()) + ''',
        ' ''' + randWord(5,9) + ' ' + randWord(8,11) + ''' ',
        ' ''' + randWord(6,8) + ', ' + randInt(1,9) + ''' ',
        ''' + randInt(30,90) + ''',
        ''' + randFloat(150,180) + '''
      );
      '''
    )
  # Last professor 185 cm tall
  cursor.execute(
    '''
    INSERT INTO "Professor" (
      id,
      name,
      address,
      age,
      height
    ) VALUES (
      ''' + str(idList.pop()) + ''',
      ' ''' + randWord(5,9) + ' ' + randWord(8,11) + ''' ',
      ' ''' + randWord(6,8) + ', ' + randInt(1,9) + ''' ',
      ''' + randInt(30,90) + ''',
      185
    );
    '''
  )

def task4(cursor):
  idList = [i for i in range(1,LIST_SIZE)]
  random.shuffle(idList)
  for _ in range(1, len(idList)): # From 1 to 1,000,000
    cursor.execute(
      '''
      INSERT INTO "Course" (
        cid,
        title,
        area,
        instructor
      ) VALUES (
        ' ''' + str(idList.pop()) + ''' ',
        ' ''' + randWord(7,12) + ''' ',
        ' ''' + randWord(4,8) + ''' ',
        ''' + randInt(1,len(idList)) + '''
      );
      '''
    )

def task5(cursor):
  cursor.execute(
    'SELECT id FROM "Professor";'
  )
  idList = cursor.fetchall() # Fetch professor IDs
  for element in idList:
    print(element, file=sys.stderr)

def task6(cursor):
  cursor.execute(
    '''
    UPDATE "Professor"
    SET height=200
    WHERE height=185;
    '''
  )

def task7(cursor):
  cursor.execute(
    '''
    SELECT id, address
    FROM "Professor" 
    WHERE height=200;
    '''
  )
  idList = cursor.fetchall() # Fetch professor IDs
  for element in idList:
    print(element, file=sys.stderr)

def task8(cursor):
  cursor.execute(
    '''
    CREATE INDEX height_index
    ON "Professor"(height);
    '''
  )

def task9(cursor):
  cursor.execute(
    'SELECT id FROM "Professor";'
  )
  idList = cursor.fetchall() # Fetch professor IDs
  for element in idList:
    print(element, file=sys.stderr)

def task10(cursor):
  # Update height from 200 to 210
  cursor.execute(
    '''
    UPDATE "Professor"
    SET height=210
    WHERE height=200;
    '''
  )

def task11(cursor):
  cursor.execute(
    '''
    SELECT id, address
    FROM "Professor"
    WHERE height=210;
    '''
  )
  idList = cursor.fetchall() # Fetch professor IDs
  for element in idList:
    print(element, file=sys.stderr)

if __name__ == "__main__":
  main()

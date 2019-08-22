#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
using namespace std;

#define MAX_POINTS 10

struct sPoint
{
  float x;
  float y;
  sPoint()
  {
    x = 1.0;
    y = 1.0;
  }
  sPoint(int _x, int _y)
  {
    x = _x;
    y = _y;
  }
  
  // distance from the center
  float distFromZero()
  {
    return sqrt(x * x + y * y);
  }

  // distance from a given point
  float distFromPoint(int _x, int _y)
  {
    return sqrt((x - _x) * (x - _x) + (y - _y) * (y - _y));
  }

  void print()
  {
    cout << x << " " << y << endl;
  }
};

struct sFigure
{
  sPoint point[MAX_POINTS];
  int n;

  sFigure()
  {
    n = 0;
  }

  sFigure(int _n)
  {
    n = _n;
    for (int i = 0; i < _n; i++)
    {
      point[i].x = random() % 10;
      point[i].y = random() % 10;
    }
  }

  void print()
  {
    for (int i = 0; i < n; i++)
    {
      cout << point[i].x << " ";
      cout << point[i].y << " ";
      cout << "\t";
    }
    cout << endl;
  }

  void furthestPoint()
  {
    float maxDist = 0;
    int pointNumber = 0;
    for (int i = 0; i < MAX_POINTS; i++)
    {
      if (point[i].distFromZero() > maxDist)
      {
        pointNumber = i;
        maxDist = point[i].distFromZero();
      }
    }
    cout << "Max distance: " << maxDist << " Point number: " << pointNumber << endl;
  }
};

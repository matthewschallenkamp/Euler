#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool line_over_zero(int ax, int ay, int bx, int by)
{
  double slope = (double)(by - ay) / (double)(bx - ax);

  // slope * ax + b = ay
  double zero = ay - slope * ax;

  // cout << "slope " << slope << endl;
  // cout << "zero " << zero << endl;
  return zero > 0;
}

int main()
{
  ifstream fin;

  fin.open("triangles.txt");

  if (!fin) cout << "ERROR!" << endl;
  int  ct     = 0;
  int  old_ct = 0;
  int  ax, ay, bx, by, cx, cy;
  bool skip = false;

  while (fin >> ax)
  {
    skip   = false;
    old_ct = ct;
    fin >> ay >> bx >> by >> cx >> cy;

    // cout << ax << " " << ay << " " << bx << " " << by << " " << cx << " " <<cy << endl;
    if ((ax > 0) && (bx > 0) && (cx > 0)) skip = true;

    if ((ax < 0) && (bx < 0) && (cx < 0)) skip = true;

    if ((ay > 0) && (by > 0) && (cy > 0)) skip = true;

    if ((ay < 0) && (by < 0) && (cy < 0)) skip = true;

    if (skip)
    {
      // cout << "skipped" << endl;
      continue;
    }
    bool positive = (ax > 0) xor (bx > 0) xor (cx > 0);

    if (positive)
    {
      // cout << "positive" << endl;
      if (ax > 0)
        if (line_over_zero(ax, ay, bx, by) xor line_over_zero(ax, ay, cx, cy)) ct++;

      if (bx > 0)
        if (line_over_zero(ax, ay, bx, by) xor line_over_zero(bx, by, cx, cy)) ct++;

      if (cx > 0)
        if (line_over_zero(cx, cy, bx, by) xor line_over_zero(ax, ay, cx, cy)) ct++;
    }
    else
    {
      // cout << "negative" << endl;
      if (ax < 0)
        if (line_over_zero(ax, ay, bx, by) xor line_over_zero(ax, ay, cx, cy)) ct++;

      if (bx < 0)
        if (line_over_zero(ax, ay, bx, by) xor line_over_zero(bx, by, cx, cy)) ct++;

      if (cx < 0)
        if (line_over_zero(cx, cy, bx, by) xor line_over_zero(ax, ay, cx, cy)) ct++;
    }
  }
  cout << "the number of triangles was " << ct << endl;
  return 0;
}

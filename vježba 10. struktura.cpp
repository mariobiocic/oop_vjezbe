#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point
{
    double x, y;

   
    Point(double _x, double _y) : x(_x), y(_y) {}
};


vector<Point> readPoints(const string& filename) {
    ifstream file(filename);
    vector<Point> points;

    double x, y;
    while (file >> x >> y) 
    {
        points.emplace_back(x, y);
    }

    return points;
}

int main()
{
    
    vector<Point> points = readPoints("points.txt");

   
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return sqrt(a.x * a.x + a.y * a.y) < sqrt(b.x * b.x + b.y * b.y);
        });

   
    double radius = 5.0;  
    int countWithinRadius = count_if(points.begin(), points.end(), [radius](const Point& p) {
        return sqrt(p.x * p.x + p.y * p.y) < radius;
        });

    
    double replaceDistance = 3.0;  
    Point replacementPoint(10.0, 10.0);  
    replace_if(points.begin(), points.end(), [replaceDistance](const Point& p) {
        return sqrt(p.x * p.x + p.y * p.y) == replaceDistance;
        }, replacementPoint);

    
    reverse(points.begin(), points.end());
    copy(points.begin(), points.end(), ostream_iterator<Point>(cout, "\n"));

    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class Point {
private:
    T x;
    T y;

public:
    Point(T xCoord, T yCoord) : x(xCoord), y(yCoord) {}

    double operator-(const Point& other) const {
        T dx = x - other.x;
        T dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    friend std::ostream& operator<<(ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

int main() {
    Point<int> p1(2, 3);
    Point<int> p2(3, 4);

    std::cout << "Udaljenost tocaka " << p1 << " i " << p2 << " je " << static_cast<double>(p1 - p2) << endl;

    return 0;
}

#include <iostream>

class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& point)
    {
        os << point.x << " " << point.y << std::endl;
        return os;
    }
};

int main()
{
    Point v(1, 0);
    std::cout << v;
    return 0;
}


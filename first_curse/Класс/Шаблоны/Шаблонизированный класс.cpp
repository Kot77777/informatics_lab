#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Vector2D
{
private:
    T x;
    T y;
public:
    // ������������
    Vector2D(){}
    Vector2D(T x, T y){}

    // ����������
    ~Vector2D(){}

    // ��������� ���������
    T getX() const
    {
        return this->x;
    }
    T getY() const
    {
        return this->y;
    }


    // ������� ���������
    void setX(T x)
    {
        this->x = x;
    }
    void setY(T y)
    {
        this->y = y;
    }

    // ������������� �������� - ��������� ���� �������� �� ���������
    bool operator== (const Vector2D& v2) const
    {
        return ((this->getX() == v2.getX())&&(this->getY() == v2.getY()));
    }

    // ��� ���� ������������� �������� - ����������� ��������
    // ��, ��� ��������� ��������! ���� - ��������� ������ ������ ��� != ������������ ��� ���������� ==
    bool operator!= (const Vector2D& v2) const
    {
        return !(*this == v2);
    }

    // ����� ���� ��������, �������� ������� �� ��������, ������������ ����� ������
    Vector2D operator+ (const Vector2D& v2) const;

    // ��������� ��������, �������� ������� �� ��������, ������������ ����� ������
    Vector2D operator- (const Vector2D& v2) const
    {
        Vector2D v3;
        v3.setX(this->getX() - v2.getX());
        v3.setY(this->getY() - v2.getY());
        return v3;
    }

    // �������� ��������� ������� �� ������, �������� ������ �� ��������, ������������ ����� ������
    Vector2D operator* (const int a) const
    {
        Vector2D v;
        v.setX(this->getX()*a);
        v.setY(this->getY()*a);
        return v;
    }


};

//�������� ��������� ������� �� ������, �������� ������ �� ��������, ������������ ����� ������
// ����������, ������? ��������� ������� �� ������ - ��� ��������� ��������, ������ ��������� *���* ������.
template<typename T>
Vector2D<T> operator* (int a, const Vector2D<T>& v)
{
        Vector2D<T> v1;
        v1.setX(v.getX()*a);
        v1.setY(v.getY()*a);
        return v1;
}

// ����� �������, ��������� ������ � ������� (1; 1)
template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector2D<T>& v)
{
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
}

// ������ �������, ������ ������ ��� ���������� ��� ���������
template<typename T>
std::istream& operator>>(std::istream &is, Vector2D<T>& v)
{
    T a, b;
    is >> a;
    v.setX(a);
    is >> b;
    v.setY(b);
    return is;
}

int main() {
Vector2D<int> v1;
    cin >> v1;
    cout << "Read vector: " << v1 << endl;
    cout << "Vector multiplied by 42: " << v1 * 42 << endl;

    Vector2D<double> v2;
    cin >> v2;
    cout << "Read vector: " << v2 << endl;
    cout << "Vector multiplied by 42: " << 42 * v2 << endl;
    return 0;
}

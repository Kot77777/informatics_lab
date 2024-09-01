#include <iostream>
#include <string>
using namespace std;

class Vector2D
{
private:
    int x;
    int y;
public:
    // ������������
    Vector2D(){}
    Vector2D(int x, int y){}

    // ����������
    ~Vector2D(){}

    // ��������� ���������
    int getX() const
    {
        return this->x;
    }
    int getY() const
    {
        return this->y;
    }


    // ������� ���������
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
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

    friend std::istream& operator>>(std::istream &is, Vector2D &v);
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);
};

//�������� ��������� ������� �� ������, �������� ������ �� ��������, ������������ ����� ������
// ����������, ������? ��������� ������� �� ������ - ��� ��������� ��������, ������ ��������� *���* ������.

Vector2D operator* (int a, const Vector2D& v)
{
        Vector2D v1;
        v1.setX(v.getX()*a);
        v1.setY(v.getY()*a);
        return v1;
}

// ����� �������, ��������� ������ � ������� (1; 1)
std::ostream& operator<<(std::ostream& os, const Vector2D& v)
{
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
}

// ������ �������, ������ ������ ��� ���������� ��� ���������
std::istream& operator>>(std::istream &is, Vector2D &v)
{
    is >> v.x;
    is >> v.y;
    return is;
}

int main() {
    Vector2D v1;
    cin >> v1;
    cout << v1 << endl;
    Vector2D v2;
    cin >> v2;
    cout << v2 << endl;
    cout << boolalpha << (v1 == v2) << endl;
    cout << boolalpha << (v1 != v2) << endl;
    Vector2D v3 = v1 - v2;
    cout << v3 << endl;
    cout << v3 * 42 << endl;
    cout << 42 * v3 << endl;
    return 0;
}

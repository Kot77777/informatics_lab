#include <iostream>
#include <string>
using namespace std;

class Point
{
private: //�� ������ ���� ��������
    int x;
    int y;

public:

    Point ()//������ ����������
    {
        x = 0;
        y = 0;
        cout << this << " constructor" << endl;
    }

    Point(int valueX, int valueY) //�����������
    {
        x = valueX;
        y = valueY;
        cout << this << " constructor" << endl;
    }

    int GetY()
    {
        return y;
    }

    void SetY(int y)
    {
        this->y = y;
    }

    int GetX () //��������� ������ ���� �� ��� ������
    {
        return x;
    }

    void SetX(int valueX)//������������� �������� ��� ���������� ����
    {
        x = valueX;
    }
    void Print()
    {
        cout << "x = " << x << "\t y = " << y << endl;
    }
};

class MyClass
{
private:
    int* data;
public:
    MyClass(int size)
    {
        data = new int[size];

        cout << "������" << data << "�������� �����������" << endl;
    }

    ~MyClass() //����������(������ ���� � �� ��������� ����������)
    {
        delete[] data;
        cout << "������" << data << "�������� ����������" << endl;
    }
};


int main()
 {
    Point a;
    a.SetY(5);
    a.Print();


	return 0;
}

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
    }

    Point(int valueX, int valueY) //�����������
    {
        x = valueX;
        y = valueY;
    }

    int GetY()
    {
        return y;
    }

    void SetY(int valueY)
    {
        y = valueY*2;
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
    setlocale(LC_ALL, "ru");
    Point a;
    a.Print();

    Point b(4, 14);
    b.Print();

    MyClass n(5);
    MyClass m(10);

	return 0;
}

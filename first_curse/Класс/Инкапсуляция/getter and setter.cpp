#include <iostream>
#include <string>
using namespace std;

class Point
{
private: //�� ������ ���� ��������
    int x;
    int y;

public:
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

int main()
 {
    Point a;
    a.SetX(5);
    a.SetY(11);
    a.Print();

	return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Train
{
private:
    double massa;
    double v;
    double x;
public:
    // ������� ������� ������ m,
    // ������� � ������ ���������
    Train(double m)
    {
        massa = m;
        v = 0;
        x = 0;
    }

    // ����� � ������� ��������� � ������� ������� dt
    void move(double dt)
    {
        x += v*dt;
    }

    // �������� ������ ������� �������� (p = mv) �� dp
    // ��������� ����� ������ ���� ��������
    void accelerate(double dp)
    {
        v += dp/massa;
    }

    // �������� ������� ���������� ��������
    double getX()
    {
        return x;
    }
};

int main(){
    Train t(10);
    t.accelerate(1); // �������� ����� 0.1
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.accelerate(-2); // �������� ����� -0.1
    t.move(3);
    cout << "Current X: " << t.getX() << endl;
}

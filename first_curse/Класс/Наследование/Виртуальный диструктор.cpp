#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    A()
    {
        cout << "Vydelit Pamyt" << endl;
    }
    virtual ~A()
    {
        cout << "Osvobogdeny Pamyt" << endl;
    }
};

class B: public A
{
public:
    B()
    {
        cout << "Vydelit Pamyt" << endl;
    }
    ~B() override
    {
        cout << "Osvobogdeny Pamyt" << endl;
    }
};

int main()
{
    A *bptr = new B;// ��� ��� ���������� ������� ����� �� ���������� virtual ����� �������������� ��� � ������� �����������

    delete bptr;
    return 0;
}

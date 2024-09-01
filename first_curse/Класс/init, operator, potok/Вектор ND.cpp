#include <iostream>
#include <string>
using namespace std;

class VectorN
{
private:
    int* elem;
    int dim;
public:
    // ����������� ������� ����������� n
    VectorN(unsigned int n)
    {
        this->elem = new int[n];
        this->dim = n;
    }

    // ����������
    ~VectorN()
    {
        delete [] elem;
    }

    // ��������� ����������� �������
    unsigned getSize() const
    {
        return this->dim;
    }

    // ��������� �������� i-�� ���������� �������,
    // i ��������� � ��������� �� 0 �� n-1
    int getValue(unsigned int i) const
    {
        return this->elem[i];
    }

    // ������� �������� i-�� ���������� ������� ������ value,
    // i ��������� � ��������� �� 0 �� n-1
    void setValue(unsigned int i, int value)
    {
        this->elem[i] = value;
    }

    /*
     * ����� ���������� ������������� ���������
     */

    // �������� == ��������� ��� ������� �� ���������,
    // ����� ���, ���� ������ ����� ���� �� ����������
    bool operator== (const VectorN& v2) const
    {
        for(int i = 0; i < this->getSize(); i++)
        {
            if(this->elem[i] != v2.elem[i])
            {
                return false;
            }
        }
        return true;
    }

    // �������� != ��������� ��� ������� �� �����������,
    // ��� �� �����, ���� ���� �� ���� ���������� ����������
    bool operator!= (const VectorN& v2) const
    {
        return !(*this == v2);
    }

    // �������� + ���������� ��� ������� �������������,
    // ���������� ��������� ��� ����� ��������� �������
    VectorN operator+ (const VectorN& v2) const
    {
        VectorN v(this->getSize());
        for(int i = 0; i < this->getSize(); i++)
        {
            v.setValue(i, this->elem[i] + v2.elem[i]);
        }
        return v;

    }

    VectorN operator* (const int a) const
    {
        VectorN v(this->getSize());
        for(int i = 0; i < this->getSize(); i++)
        {
            v.setValue(i, this->elem[i]*a);
        }
        return v;
    }

    // �������� * �������� ������ �� ������ ���� int �������������,
    // ���������� ��������� ��� ����� ��������� �������.
    // ��������� ������ �������� ��� ����� ������� ���������.
};

VectorN operator* (int a, const VectorN& v)
{
        VectorN v1(v.getSize());
        for(int i = 0; i < v.getSize(); i++)
        {
            v1.setValue(i, v.getValue(i)*a);
        }
        return v1;
}


int main() {
    VectorN a(4);
    a.setValue(0, 0);
    a.setValue(1, 1);
    a.setValue(2, 2);
    a.setValue(3, 3);

    VectorN b(4);
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);
    b.setValue(3, -3);

    cout << (a == b) << endl;
    cout << (a != b) << endl;

    VectorN c = a + b;
    VectorN d = 5 * c;

    for(unsigned int i = 0; i < a.getSize(); ++i)
        cout << d.getValue(i) << endl;
    return 0;
}

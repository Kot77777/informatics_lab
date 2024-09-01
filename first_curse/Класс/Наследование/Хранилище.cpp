#include <iostream>
#include <string>
using namespace std;

class Storage
{
private:
    int* a;
    int n;
public:
    // ����������� ��������� ����������� n
    Storage(unsigned int n)
    {
        a = new int[n];
        this->n = n;
    }

    // �������� ������ ����������
    virtual ~Storage()
    {
        delete[] a;
    }

    // ��������� ����������� ���������
    unsigned getSize()
    {
        return n;
    }

    // ��������� �������� i-�� �������� �� ���������,
    // i ��������� � ��������� �� 0 �� n-1,
    // ������ ������������ i ����� �� ������������.
    int getValue(unsigned int i)
    {
        if(i <= n-1 && i >= 0)
        {
            return a[i];
        }
    }

    // ������� �������� i-�� �������� �� ��������� ������ value,
    // i ��������� � ��������� �� 0 �� n-1,
    // ������ ������������ i ����� �� ������������.
    void setValue(unsigned int i, int value)
    {
        if(i <= n-1 && i >= 0)
        {
            a[i] = value;
        }
    }
};

// ����� TestStorage, ����������� �� ����� ���������� Storage
class TestStorage : public Storage {
protected:
    // �������������� ���������� �����-�� ����� �������� ��� ������. ����� �����.
    int* more_data;

public:
    // � ������������ ������ ����������,
    TestStorage(unsigned int n) : Storage(n) {
        more_data = new int[n];
    }
    // ... � � ����������� ������������� - �� ������.
    ~TestStorage() override {
        delete[] more_data;
    }
};

int main() {
    Storage *ts = new TestStorage(42);
    delete ts;
    return 0;
}

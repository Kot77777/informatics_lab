#include <iostream>
#include <string>
using namespace std;

class SpacePort
{
private:
    int* doki;
    int size;
public:
    // ������� ���������, � ������� size ���� �����.
    // ���� ���������� �� 0 �� size-1.
    // � ������ �������� ��� ���� ��������.
    SpacePort(unsigned int size)
    {
        doki = new int[size];
        for (int i = 0; i < size; i++)
        {
            doki[i] = 0;
        }
        this->size = size;
    }

    // ��������� ������� � ��� � ������� dockNumber.
    // ���� ������ ���� ��� - ������� false (������ �������).
    // ���� ��� ����, �� ����� - ������� false (������ �������).
    // ���� ��� ���� � �������� - ������� true (���������� �������) � ��� ���������� �����.
    bool requestLanding(unsigned int dockNumber)
    {
        if(dockNumber >=0 && dockNumber < size)
        {
            if(doki[dockNumber] == 1)
            {
                return false;
            }
            else
            {
                doki[dockNumber] = 1;
                return true;
            }
        }
        else
        {
            return false;
        }
    }

    // ��������� ���� �� ���� � ������� dockNumber.
    // ���� ������ ���� ��� - ������� false (������ �����).
    // ���� ��� ����, �� ��� ����� - ������� false (������ �����).
    // ���� ��� ���� � � �� ���-�� ����� - ������� true (���������� �����) � ��� ���������� ��������.
    bool requestTakeoff(unsigned int dockNumber)
    {
        if(dockNumber >=0 && dockNumber < size)
        {
            if(doki[dockNumber] == 0)
            {
                return false;
            }
            else
            {
                doki[dockNumber] = 0;
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    ~SpacePort()
    {
        delete[] doki;
    }
};

int main(){
    SpacePort s(5);
    cout << boolalpha << s.requestLanding(0) << endl;
    cout << boolalpha << s.requestLanding(4) << endl;
    cout << boolalpha << s.requestLanding(5) << endl;

    cout << boolalpha << s.requestTakeoff(0) << endl;
    cout << boolalpha << s.requestTakeoff(4) << endl;
    cout << boolalpha << s.requestTakeoff(5) << endl;
}

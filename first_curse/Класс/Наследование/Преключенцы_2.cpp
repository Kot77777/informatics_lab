#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    // ��������� ������ ��������.
    // ����������� ������� �� ���������� ������� ������ ��� ������ ���������� ��������.
    virtual void pet() = 0;

    virtual ~Animal() {};
};

class NPC {
public:
    // ���������� � NPC.
    // ��� �� ������ - ������� �� ���������� ������� ������ ��� ����������� NPC.
    virtual void talk() = 0;

    virtual ~NPC() {};
};

class SmartCat: public Animal, public NPC
{
    void talk() override
    {
        cout << "Meow!" << endl;
    }
    void pet() override
    {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal *a = new SmartCat();
    a->pet();
    delete a;

    // � ��� - ����� ������, ������� �������� � NPC.
    NPC *n = new SmartCat();
    n->talk();
    delete n;
}

#include <iostream>
#include <string>
using namespace std;

namespace namespaceA {
    class Engine {
    public:
        void run() {
            cout << "EngineA run" << endl;
        }
    };
}

namespace namespaceB {
    class Engine {
    public:
        void run() {
            cout << "EngineB run" << endl;
        }
    };
}

namespace namespaceC {
    class Engine {
    public:
        void run() {
            cout << "EngineC run" << endl;
        }
    };
}

class MyEngine {
public:
    // ���� ������� �������� 1 - ������ ���� ������ ����� run � Engine-� �� ���������� A.
    // ���� ������� �������� 2 - ������ ���� ������ ����� run � Engine-� �� ���������� B.
    // ���� ������� �������� 3 - ������ ���� ������ ����� run � Engine-� �� ���������� C.
    // ���� �������� ���-�� ���� - ������ ������ �� ���������.
    void run(unsigned int number)
    {
        if(number == 1)
        {
            namespaceA::Engine a;
            a.run();
        }

        if(number == 2)
        {
            namespaceB::Engine a;
            a.run();
        }

        if(number == 3)
        {
            namespaceC::Engine a;
            a.run();
        }
    }
};

int main()
{
    MyEngine e;
    e.run(1); // ����� run �� Engine-� �� ���������� A
    e.run(2); // ����� run �� Engine-� �� ���������� B
    e.run(3); // ����� run �� Engine-� �� ���������� C
    e.run(10); // ������ �� ����������
    return 0;
}

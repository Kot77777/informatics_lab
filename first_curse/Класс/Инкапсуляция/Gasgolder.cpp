#include <iostream>
#include <string>
using namespace std;

class GasHolder
{
private:
    float obyem;
    float T;
    float M;
    float m;
public:
    // ������� ���������� ��������� ������.
    // ����������� ���������� ���������� ����� 273 �.
    GasHolder(float v)
    {
        obyem = v;
        T = 273;
        m = 0;
        M = 0;
    }

    // ���������� ����������.
    ~GasHolder()
    {

    }

    // ������ ������ ���� ������ m � �������� ������ M.
    // �������, ��� ��� ��������� ������� ����������� ����������� �� ������������ ����� �����.
    void inject(float m, float M)
    {
        if(this->m!=0 && this->M!=0)
        {
        this->M = (this->m + m)/((this->m / this-> M)+(m/M));
        this->m += m;
        }
        else
        {
            this->m = m;
            this->M = M;
        }
    }

    // ��������� ���������� �� dT ��������.
    // �������, ��� ������ �������� �� ����� �������� �����������.
    void heat(float dT)
    {
        T += dT;
    }

    // �������� ���������� �� dT ��������.
    // ��� ������� �������� ���� 0 � ����������� ���������� ����� 0 �.
    void cool(float dT)
    {
        if ((T - dT) > 0)
        {
            T -= dT;
        }
        else
        {
            T = 0;
        }
    }

    // �������� ������� �������� � �����������.
    // �������, ��� ��� ���� ����� ��������� ��������� PV = (m/M)RT.
    // �������� ���������� R ������� 8.31 ��/(����*�).
    double getPressure()
    {
        return ((m/M)*8.31*T)/obyem;
    }
};

int main(){
    GasHolder h(1.0);
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.heat(273);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
}

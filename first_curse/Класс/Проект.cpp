#include <iostream>
#include <string>
using namespace std;

class Weapon
{
public:
    virtual void Shoot() = 0; //������ ������ �����������
    virtual int Get() = 0;
};

class Gun: public Weapon
{
private:
    int damage = 10;
public:
    int Get()
    {
        return this->damage;
    }
    void Shoot() override
    {
        cout << "��������" << endl;
        cout << "�� �������� �� ����� ���� ������ �����" << endl;
    }
};

class Snaiper: public Gun
{
private:
    int damage = 20;
public:
    int Get()
    {
        return damage;
    }
    void Shoot() override
    {
        cout << "��������" << endl;
        cout << "�� �������� �� ����� ���� ������, �� ������ �����" << endl;
    }
};

class SubmachinGun: public Gun
{
private:
    int damage = 30;
public:
    int Get()
    {
        return damage;
    }
    void Shoot() override
    {
        cout << "�������" << endl;
        cout << "�� ����������� �����" << endl;
    }
};

class Bazooka: public Weapon
{
private:
    int damage = 40;
public:
    int Get()
    {
        return damage;
    }
    void Shoot() override
    {
        cout << "������" << endl;
        cout << "�� ������ ����� ����� ����� ����" << endl;
    }
};

class Click: public Weapon
{
private:
    int damage = 1;
public:
    int Get()
    {
        return damage;
    }
    void Shoot() override
    {
        cout << "������" << endl;
        cout << "�� �������� ����� � ������, �������, ������" << endl;
    }
};

class Knife: public Weapon
{
private:
    int damage = 5;
public:
    int Get()
    {
        return damage;
    }
    void Shoot() override
    {
        cout << "���" << endl;
        cout << "�� ������� �����" << endl;
    }
};

class heal: public Weapon
{
private:
    int damage = -10;
public:
    int Get()
    {
        return this->damage;
    }
    void Shoot() override
    {
        cout << "���� �������������� ��������" << endl;
    }
};

class Grenade: public Weapon
{
private:
    int damage = 0;
public:
    int Get()
    {
        return damage;
    }

    void Shoot() override
    {
        cout << "�������" << endl;
        cout << "�� ������ ��������� ����, ������� �� ������� ����(" << endl;
    }
};



class Enemy
{
private:
    int HP = 100;
public:
    int Get1()
    {
        return this->HP;
    }

    bool kick(int damage)
    {
        this->HP -= damage;
        if(this->HP <= 0)
        {
            cout << "���� ��������" << endl;
            return false;
        }
        return true;
    }

};

class Player
{
public:
    void Shoot(Weapon* weapon)
    {
       weapon->Shoot();
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    Enemy enemy;
    Player player;
    Weapon* lists[8];
    lists[0] = new Gun;
    lists[1] = new SubmachinGun;
    lists[2] = new Snaiper;
    lists[3] = new Bazooka;
    lists[4] = new Knife;
    lists[5] = new Grenade;
    lists[6] = new Click;
    lists[7] = new heal;
    int k;
    while (true){
        cout << "��������(10) - 0, �������(30) - 1, ��������(20) - 2, ������(40) - 3, ���(5) - 4, �������(100) - 5, ������(1) - 6" << endl;
        cout << "������� ����� ������, ������� ������ ������������" << endl;
        cin >> k;
        player.Shoot(lists[k]);
        if (enemy.kick(lists[k]->Get()))
        {
            cout << "�������� �����:" << enemy.Get1() << endl;
        }
        else
        {
            break;
        }
        if(enemy.Get1() <= 10)
        {
            player.Shoot(lists[7]);
            enemy.kick(lists[7]->Get());
            cout << "�������� �����:" << enemy.Get1() << endl;
        }
    }
    for (int i = 0; i < 8; i++) {
        delete lists[i];
}
    return 0;
}

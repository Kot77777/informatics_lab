#include <iostream>
#include <string>
using namespace std;

class Item {
protected:
    string title;
    int weight;
    int level;
    bool magical;

public:
    // ��� ����� ������� �������, ������ ��� ��������, ���, ������� � ����������
    Item(string title, int weight, int level, bool magical) {
        this->title = title;
        this->weight = weight;
        this->level = level;
        this->magical = magical;
    }

    // �������� ��� ��������
    int getWeight() const {
        return weight;
    }

    // �������� ������� ��������
    int getLevel() const {
        return level;
    }

    // ��������, �������� �� ������� ��������
    int isMagical() const {
        return magical;
    }
};

// ������� ����� �����
class Player {
protected:
    // ���� � ������� �����
    int strength;
    int level;

public:
    // ������� �����, ��� ����������� ����� ������� �����
    Player() { }
    // ������� �����, ������ ������ ��� ��������� ���� ��� �� �������
    virtual ~Player() { }

    // ������� ������, ���� ��� ����� �������.
    // �� ������ ����� ����� �������, ��� ��� ���� ������ ��� ����� ���� ���������,
    // ��� ��� ����� ����� � ������� ������.

    // ������ ����
    virtual void setStrength(int strength) final {
        this->strength = strength;
    }
    // ������ �������
    virtual void setLevel(int level) final {
        this->level = level;
    }

    // �������� ����
    virtual int getStrength() const final {
        return strength;
    }
    // �������� �������
    virtual int getLevel() const final {
        return level;
    }

    // ��������, ����� �� ����� ������������ �������.
    // ������ ����� ������������ (�) ������ ������������ �������� � ������ ����
    // (�) ���� ����� �� ������ ���� ��������, (�) ������� ����� �� ������ ������ ��������.
    // ��������� ������� � ����� ��� ��, �� ���������� �������� ������������ ���� �����.
    virtual bool canUse(const Item& item) const = 0;

    // ����� �� ����� ���������, ������� �� ����������� ������ ������
    virtual bool canCast() const = 0;

    // ��������, ����� �� ����� ������ ������ �������.
    // ������ ����� ��� ����� ���������, ���
    // ����� ���������� �������� ������.
    virtual bool canHeal() const {
        return canCast() || getLevel() > 10;
    }
};

class Knight: public Player
{
public:
    bool canUse(const Item& item) const
    {
        if(item.isMagical() == 0 && this->strength >= item.getWeight() && this->level >= item.getLevel())
        {
            return true;
        }
        return false;
    }
    bool canCast() const
    {
        return false;
    }
};

class Wizard: public Player
{
public:
    bool canUse(const Item& item) const
    {
        if(this->strength >= item.getWeight() && this->level >= item.getLevel())
        {
            return true;
        }
        return false;
    }
    bool canCast() const
    {
        return true;
    }
};

int main()
{
Item items[3] = {
        Item("Small sword", 1, 1, false),
        Item("Big sword", 5, 3, false),
        Item("Ward", 1, 3, true)
    };

    Player* players[2];
    players[0] = new Wizard();
    players[0]->setStrength(3);
    players[0]->setLevel(5);
    players[1] = new Knight();
    players[1]->setStrength(6);
    players[1]->setLevel(5);

    for(int i = 0; i < 2; i++) {
        cout << "Can heal: " << players[i]->canHeal() << endl;
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "Can use: " << players[i]->canUse(items[j]) << endl;
        }
    }

    for(int i = 0; i < 2; i++)
        delete players[i];
    return 0;
}

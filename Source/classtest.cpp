///////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include < vector>
#include <iostream>
using namespace std; //命名空间
#define uint16 unsigned int
#define uint8 unsigned char

class CHero
{
public:
    void SetHP(int hp) //设置血量
    {
        m_HP = hp;
    }
    int GetHP() //获得hp
    {
        return m_HP;
    }

protected: //保护
private:
    int m_HP; //私有,血量
};

int main()
{
    CHero hero;
    CHero *phero;
    phero = &hero;
    hero.SetHP(10);

    cout << "hp: " << hero.GetHP() << endl;
    cout << "php :" << phero->GetHP() << endl; //类指针
    printf("hello \n");
    system("pause");
    return 0;
}

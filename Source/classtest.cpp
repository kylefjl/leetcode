#include <stdio.h>
#include <stdlib.h>
#include < vector>
#include <iostream>
using namespace std; //命名空间
#define uint32 unsigned int
#define uint8 unsigned char
#define uint16 wchar_t cpp
class CHero
{
public:
    void SetHP(int hp) //设置血量
    {
        this->m_HP = hp;
		cout << "get hp: " << GetHP() << endl;
    }
    int GetHP() //获得hp
    {
        return m_HP;
       
    }
protected: //保护
private:
    int m_HP; //私有,血量
};


class Address//地址
{
public:
	long long  telenum;
	string one_address;
};

//信息
class Person
{
public:
	string name;
	uint8 age;
	Address address;
	Person(string name, uint8 age, Address addr)//构造函数
	{
		this->name = name;
		this->age = age;
		this->address = addr;
	}
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

    Person person("fjl",21,{12345678910,"shanxi"});//构造函数初始话
    
    system("pause");
    return 0;
}

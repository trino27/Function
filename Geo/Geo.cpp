#include <iostream>
#include <math.h>

using namespace std;

#define PI 3.14159265
typedef long long ll;
typedef long double ld;

class Geo
{
protected:
    ll sizefunc = 30; //общее кооличество  точек = sizefunc*sizefunc + 2(sizefunc*(sizefunc-1)) + (sizefunc-1)*(sizefunc-1)
    char** Func1;
    char** Func2;
    char** Func3;
    char** Func4;
    short x = 1;
    short y = 1;
    ld k = 1;
    ld b = 0;
    Geo();
public:
    virtual void Show(bool hide) = 0;
    void Hide();
    void input(string fu);
    virtual void Move(ll vec) = 0;
    virtual void IMenu() = 0;

    ~Geo();
};
void Geo::input(string fu)
{

}
Geo::Geo()
{
    Func1 = new char* [sizefunc];
    for (ll i = 0; i < sizefunc; i++)
    {
        Func1[i] = new char[sizefunc];
    }

    Func2 = new char* [sizefunc];
    for (ll i = 0; i < sizefunc; i++)
    {
        Func2[i] = new char[sizefunc];
    }
    Func3 = new char* [sizefunc];
    for (ll i = 0; i < sizefunc; i++)
    {
        Func3[i] = new char[sizefunc];
    }
    Func4 = new char* [sizefunc];
    for (ll i = 0; i < sizefunc; i++)
    {
        Func4[i] = new char[sizefunc];
    }
}
void Geo::Hide()
{
    system("cls");
    for (ll i = 0; i < sizefunc; i++)
    {
        for (ll j = 0; j < sizefunc; j++)
        {
            if (i == 0) Func1[i][j] = '>';
            else Func1[i][j] = '.';
        }
    }
    for (ll i = 0; i < sizefunc; i++)
    {

        for (ll j = 0; j < sizefunc; j++)
        {
            if (i == 0) Func2[i][j] = '>';
            else if (j == 0) Func2[i][j] = '^';
            else Func2[i][j] = '.';
        }
    }
    Func2[0][0] = '0';
    for (ll i = 0; i < sizefunc; i++)
    {
        for (ll j = 0; j < sizefunc; j++)
        {
            Func3[i][j] = '.';
        }
    }
    for (ll i = 0; i < sizefunc; i++)
    {
        for (ll j = 0; j < sizefunc; j++)
        {
            if (j == 0) Func4[i][j] = '^';
            else Func4[i][j] = '.';
        }
    }
}
Geo::~Geo()
{
    for (ll i = 0; i < sizefunc; i++)
    {
        delete[] Func1[i];
    }
    delete[] Func1;
    for (ll i = 0; i < sizefunc; i++)
    {
        delete[] Func2[i];
    }
    delete[] Func2;
    for (ll i = 0; i < sizefunc; i++)
    {
        delete[] Func3[i];
    }
    delete[] Func3;
    for (ll i = 0; i < sizefunc; i++)
    {
        delete[] Func4[i];
    }
    delete[] Func4;
}
#include <iostream>
#include "../Geo/Geo.cpp"

class Line : public Geo
{
private:
    short scope = 0;
public:

    void Hide()
    {
        Geo::Hide();
    }
    void SetX()
    {
        if (x == -1) x = 1;
        else x--;
    }
    void SetY()
    {
        if (y == -1) y = 1;
        else y--;
    }
    void SetDeg(ld tan)
    {
        k = round((tan) * 1000) / 1000;
    }
    ld GetK()
    {
        return k;
    }
    ld GetX()
    {
        return x;
    }
    ld GetY()
    {
        return y;
    }
    ld GetB()
    {
        return b;
    }
    ld GetDeg()
    {
        if (y == 0) return 0;
        else if (y == -1) return 90 + round((atan(k) * 180 / PI * x) * 10) / 10;
        else return 90 - round((atan(k) * 180 / PI * x) * 10) / 10;
    }
    short  GetScope()
    {
        return scope;
    }
    void ScaleDown()
    {
        scope++;
    }
    void ScaleUP()
    {
        scope--;
    }
    void Move(ll vec) override
    {
        b += vec;
    }
    void Show(bool hide) override;
    void IMenu() override;
};
void Line::Show(bool hide)
{
    Hide();
    if (!hide)
    {
        for (ll i = 0; i < sizefunc; i++)
        {
            for (ll j = 0; j < sizefunc; j++)
            {
                if (round((i * (x * k) - b) * pow(2, scope)) / pow(2, scope) == round(((j * y) * -1) * pow(2, scope)) / pow(2, scope))
                {
                    Func1[i][j] = '@';
                }
            }
        }
        for (ll i = 0; i < sizefunc; i++)
        {

            for (ll j = 0; j < sizefunc; j++)
            {
                if (round((i * (x * k) - b) * pow(2, scope)) / pow(2, scope) == round((j * y) * pow(2, scope)) / pow(2, scope))
                {
                    Func2[i][j] = '@';
                }
            }
        }
        for (ll i = 0; i < sizefunc; i++)
        {
            for (ll j = 0; j < sizefunc; j++)
            {
                if (round((i * ((x * k) * -1) - b) * pow(2, scope)) / pow(2, scope) == round(((j * y) * -1) * pow(2, scope)) / pow(2, scope))
                {
                    Func3[i][j] = '@';
                }
            }
        }
        for (ll i = 0; i < sizefunc; i++)
        {
            for (ll j = 0; j < sizefunc; j++)
            {
                if (round((i * ((x * k) * -1) - b) * pow(2, scope)) / pow(2, scope) == round((j * y) * pow(2, scope)) / pow(2, scope))
                {
                    Func4[i][j] = '@';
                }
            }
        }
    }


    for (ll i = sizefunc - 1; i >= 0; i--)
    {
        for (ll j = sizefunc - 1; j > 0; j--)
        {
            cout << Func1[i][j] << ' ';
        }
        for (ll j = 0; j < sizefunc; j++)
        {
            cout << Func2[i][j] << ' ';
        }
        cout << endl;
    }
    for (ll i = 1; i < sizefunc; i++)
    {
        for (ll j = sizefunc - 1; j > 0; j--)
        {
            cout << Func3[i][j] << ' ';
        }
        for (ll j = 0; j < sizefunc; j++)
        {
            cout << Func4[i][j] << ' ';
        }
        cout << endl;
    }

}
void Line::IMenu()
{
    short key = -1;
    bool put = true;
    while (key != 0)
    {
        system("cls");
        if (key == 5)
        {
            SetX();
        }
        if (key == 6)
        {
            SetY();
        }
        if (key == 7)
        {
            ScaleUP();
        }
        if (key == 8)
        {
            ScaleDown();
        }
        if (key == 2 || !put)
        {
            put = false;
            Show(true);
        }
        if (key == 1 || put)
        {
            put = true;
            Show(false);
        }
        cout << GetY() << "f(x) = " << GetK() * GetX() << "x + " << GetB() << "               Scope: " << pow(2, (GetScope() * -1)) << "               Angle between straight line and X: " << GetDeg() << endl;
        cout << "Enter 1 to show line" << endl;
        cout << "Enter 2 to hide line" << endl;
        cout << "Enter 3 to move line (change: b)" << endl;
        cout << "Enter 4 to rotate line by degries(chage k)" << endl;
        cout << "Enter 5 to (1/0/-1) x (change: x=1 or x=0) " << endl;
        cout << "Enter 6 to (1/0/-1) (change: y=1 or y=0)" << endl;
        cout << "Enter 7 to bring closer" << endl;
        cout << "Enter 8 to move away)" << endl;
        cout << "Enter 0 to end programm" << endl;
        cout << "Input: ";
        cin >> key;
        if (key == 3)
        {
            ll vec;
            cout << "Enter vector: ";
            cin >> vec;
            Move(vec);
        }
        if (key == 4)
        {
            ld degr;
            cout << "Enter degries: ";
            cin >> degr;
            if (degr == 180 || 0)
            {
                y = 0;
            }
            if (degr == 90 || degr == 270)
            {
                char ch;
                cout << "BAD VALUE, press something to continue!";
                cin >> ch;
            }
            else SetDeg(tan((90 - degr) * PI / 180));
        }
    }
}

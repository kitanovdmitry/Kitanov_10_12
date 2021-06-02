/*
Автор: Китанов Дмитрий
Группа: СБС-001, 2-я подгруппа
Задача №10, 2-й вариант
Цель: класс с комплексными числами в тригонометрической форме с вычитанием и сложением
*/

#include <iostream>
#include <cmath>
#include <climits>
#define _USE_MATH_DEFINES

using namespace std;

class ComplexTrigonometry
{
private:
    double x, y,
           r, phi;

public:

    void setX(double val)
    {
        x = val;
    }

    void setY(double val)
    {
        y = val;
    }

    void setModule(double x, double y)
    {
        r = sqrt(x*x + y*y);
    }

    void setPhi()
    {
        phi = acos(x/r) * 180.0 / M_PI; //угол фи в градусах
    }


    ComplexTrigonometry(double x, double y)
    {
        setX(x);
        setY(y);
        setModule(x, y);
        setPhi();
    }

    ComplexTrigonometry(double x) //для сложения комплексного с действительным
    {
        setX(x);
        setY(0.0);
        setModule(x, y);
        setPhi();
    }

    ~ComplexTrigonometry()
    {
    }


    ComplexTrigonometry operator+(const ComplexTrigonometry &res_plus)
    {
        return ComplexTrigonometry(x + res_plus.x, y + res_plus.y);
    }

    ComplexTrigonometry operator-(const ComplexTrigonometry &res_minus)
    {
        return ComplexTrigonometry(x - res_minus.x, y - res_minus.y);
    }


    void print()
    {
        cout << r << "e^(i*"<< phi << ") = "
             << r << "(cos(" << phi << ") + isin(" << phi << "))\n";
    }
};

void Cin_Check(double &number)
{
    bool typeFail;

    do
    {
        cin >> number;
        typeFail = cin.fail();
        if (typeFail)
        {
            cout << "Error! Enter correct value\n";
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    while (typeFail);

    return;
}

int main()
{
    double x1 = 0.0;
    cout << "Enter real part of your first complex number\n";
    Cin_Check(x1);

    double y1 = 0.0;
    cout << "Enter imaginary part of your first complex number\n";
    Cin_Check(y1);

    cout << "Your first complex number:\n";
    cout << x1 << " + " << y1 << "i\n";


    double x2 = 0.0;
    cout << "\nEnter real part of your second complex number\n";
    Cin_Check(x2);

    double y2 = 0.0;
    cout << "Enter imaginary part of your second complex number\n";
    Cin_Check(y2);

    cout << "Your second complex number:\n";
    cout << x2 << " + " << y2 << "i\n";


    ComplexTrigonometry obj_1 = ComplexTrigonometry(x1, y1);
    ComplexTrigonometry obj_2 = ComplexTrigonometry(x2, y2);

    cout << "\nYour the first complex number in trigonometric form:\n";
    obj_1.print();
    cout << "\nYour the second complex number in trigonometric form:\n";
    obj_2.print();


    ComplexTrigonometry res_plus = obj_1 + obj_2;
    cout << "\nThe result of adding your complex numbers:\n";
    res_plus.print();

    ComplexTrigonometry res_minus = obj_1 - obj_2;
    cout << "\nThe result of substraction your complex numbers(1-st - 2-nd):\n";
    res_minus.print();

    double real = 0.0;
    cout << "\nEnter a real number for adding:\n";
    Cin_Check(real);

    ComplexTrigonometry res_plus_real = obj_1 + real;
    cout << "\nThe result of substraction your the first complex number and real number:\n";
    res_plus_real.print();

    return 0;
}

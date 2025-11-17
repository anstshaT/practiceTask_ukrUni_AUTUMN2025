#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    float R = 0;

    cout << "Введіть значення зміної a: ";
    cin >> a;
    cout << "Введіть значення зміної b: ";
    cin >> b;

    for (float t = 0; t < 1.1; t += 0.1)
    {
        if (t > 0.2)
        {
            R = (a * (t * t)) - (b * (t * t * t));
            cout << "t = " << t << ", тоді R = " << R << "\n";
            cout << "-------\n";
        }
        else if (t < 0.1)
        {
            R = (a * (t * t)) + (b * t);
            cout << "t = " << t << ", тоді R = " << R << "\n";
            cout << "-------\n";
        }
        else
        {
            R = (a * t) + b;
            cout << "t = " << t << ", тоді R = " << R << "\n";
            cout << "-------\n";
        }
    }

    return 0;
}

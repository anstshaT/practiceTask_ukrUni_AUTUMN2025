#include <iostream>

using namespace std;

void check_number()
{
    float num = 0;
    cout << "Напишіть своє число: ";
    cin >> num;

    if (num > 0)
    {
        cout << num << " більше ніж 0\n";
    }
    else if (num == 0)
    {
        cout << num << " дорівнює 0\n";
    }
    else
    {
        cout << num << " менше ніж 0\n";
    }

    return;
}

int main()
{
    check_number();
    return 0;
}
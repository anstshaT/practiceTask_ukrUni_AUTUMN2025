#include <iostream>

using namespace std;

int main()
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
    return 0;
}
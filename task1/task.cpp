#include <iostream>

using namespace std;

void check_number()
{
    float num = 0;
    cout << "Write your number: ";
    cin >> num;

    if (num > 0)
    {
        cout << num << " is bigger than 0\n";
    }
    else if (num < 0)
    {
        cout << num << " is smaller than 0\n";
    }
    else
    {
        cout << num << " is equal to 0\n";
    }

    return;
}

int main()
{
    check_number();
    return 0;
}

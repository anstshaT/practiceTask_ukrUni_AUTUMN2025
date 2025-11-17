#include <iostream>

using namespace std;

int main()
{
    int mediana;
    /* int arr[] = {25, 45, 3, 100, 33, 443}; */
    /* int arr[] = {19, 675, 9, 1, 74, 34, 20, 71, 91}; */
    int arr[] = {1000, 4, 974, 503, 129, 56, 943};

    // кількість елементів в масиві
    int arr_lenght = sizeof(arr) / sizeof(arr[0]);

    cout << "Масив: ";
    for (int i = 0; i < arr_lenght; ++i)
        cout << arr[i] << ' ';
    cout << "\n";

    // сортування масиву
    for (int start_i = 0; start_i < arr_lenght - 1; start_i++)
    {
        int smallest_i = start_i;
        for (int current_i = start_i + 1; current_i < arr_lenght; current_i++)
        {
            if (arr[current_i] < arr[smallest_i])
                smallest_i = current_i;
        }

        swap(arr[start_i], arr[smallest_i]);
    }

    mediana = (arr_lenght - 1) / 2;
    cout << "Медіана масиву " << arr[mediana] << "\n";

    return 0;
}

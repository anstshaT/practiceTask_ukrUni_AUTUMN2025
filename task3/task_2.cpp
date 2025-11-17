#include <iostream>

using namespace std;

enum Cell_opt
{
    EMPTY,
    PIECE
};

int main()
{
    Cell_opt board[8][8];     // дошка board[r][c]
    int is_active = 0;        // гра активна
    int r_current, c_current; // теперешнє значення положення шашки
    int r_move, c_move = 0;   // значення номеру клітинки вибранного користувачем
    int r_piece;              // на якій частині дошки було початкове розміщення шашки 0 - верхня, 1 - нижня
    int is_allowed;           // хід можливий
    int count_play;           // продовжити гру

    /* присвоюємо значення EMPTY для кожної клатинки */
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            board[r][c] = EMPTY;
        }
    }

    cout << "Хочете почати гру? \n 1 - Так \n 0 - Ні \n";
    cin >> is_active;

    if (is_active == 0) // Вихід з гри, якщо гравець сказав ні
    {
        cout << "Гра завершена\n";
        return 0;
    }

    /* Початковий вигляд дошки */
    cout << "\n    1 2 3 4 5 6 7 8\n";
    cout << "   -----------------\n";
    for (int r = 0; r < 8; r++)
    {
        cout << r + 1 << " | ";
        for (int c = 0; c < 8; c++)
        {
            if (board[r][c] == EMPTY)
                cout << ". ";
            else
                cout << "O ";
        }
        cout << endl;
    }

    /* Стартове положення шашки*/
    cout << "Введіть рядок і стовбець для розміщення шашки (через пробіл): ";
    cin >> r_current >> c_current;
    r_current--;
    c_current--;

    if (r_current <= 3) // визначення початкового положення шашки відносно рядку
        r_piece = 0;
    else
        r_piece = 1;

    while (is_active == 1)
    {
        /* присвоюємо значення PIECE вибраній клітинці */
        board[r_current][c_current] = PIECE;

        /* Вивід дошки з початковий положення шашки*/
        cout << "\n    1 2 3 4 5 6 7 8\n";
        cout << "   -----------------\n";
        for (int r = 0; r < 8; r++)
        {
            cout << r + 1 << " | ";
            for (int c = 0; c < 8; c++)
            {
                if (board[r][c] == EMPTY)
                    cout << ". ";
                else
                    cout << "O ";
            }
            cout << endl;
        }

        /* Наступний хід */
        cout << "Введіть рядок і стовбець для ходу (через пробіл): ";
        cin >> r_move >> c_move;
        r_move--;
        c_move--;

        /* Перевірка вибраної клітинки для ходу*/
        if (board[r_move][c_move] != EMPTY)
        {
            cout << "Клітинка зайнята!\n";
            continue;
        }

        is_allowed = 0;

        if (r_piece == 0) // початкове положення у верхній частині дошки, напрям вниз
        {
            if (c_current != 0 && c_current != 7) //  шашка між стовпчиком 1 та 8
            {
                if (r_move == r_current + 1 && (c_move == c_current + 1 || c_move == c_current - 1))
                {
                    is_allowed = 1;
                }
            }
            else if (c_current == 0) // шашка у стовпчику 1
            {
                if (r_move == r_current + 1 && c_move == c_current + 1)
                {
                    is_allowed = 1;
                }
            }
            else if (c_current == 7) // шашка у стовпчику 8
            {
                if (r_move == r_current + 1 && c_move == c_current - 1)
                {
                    is_allowed = 1;
                }
            }
        }
        else if (r_piece == 1) // початкове положення у ніжній частині дошкиб напрям вверх
        {
            if (c_current != 0 && c_current != 7) //  шашка між стовпчиком 1 та 8
            {
                if (r_move == r_current - 1 && (c_move == c_current + 1 || c_move == c_current - 1))
                {
                    is_allowed = 1;
                }
            }
            else if (c_current == 0) // шашка у стовпчику 1
            {
                if (r_move == r_current - 1 && c_move == c_current + 1)
                {
                    is_allowed = 1;
                }
            }
            else if (c_current == 7) // шашка у стовпчику 8
            {
                if (r_move == r_current - 1 && c_move == c_current - 1)
                {
                    is_allowed = 1;
                }
            }
        }

        if (is_allowed == 1) // Хід можливий
        {
            /* Виконується хід */
            board[r_move][c_move] = PIECE;
            board[r_current][c_current] = EMPTY;
            r_current = r_move;
            c_current = c_move;
            cout << "Хід успішний! \n";

            /* Виведення дошки після ходу */
            cout << "\n    1 2 3 4 5 6 7 8\n";
            cout << "   -----------------\n";
            for (int r = 0; r < 8; r++)
            {
                cout << r + 1 << " | ";
                for (int c = 0; c < 8; c++)
                {
                    if (board[r][c] == EMPTY)
                        cout << ". ";
                    else
                        cout << "O ";
                }
                cout << endl;
            }
        }
        else // Хід не можливий
        {
            cout << "Хід не можливий \n";
        }

        cout << "Хочете продовжити? \n 1 - Так \n 0 - Ні \n ";
        cin >> count_play;

        if (count_play == 0) // Вихід із гри
        {
            is_active = 0;
        }
    }

    cout << "Гра завершена\n";

    return 0;
}

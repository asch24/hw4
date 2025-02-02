﻿#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(0, "");

    // 1. С клавиатуры вводится целое число. 
    // Вывести на экран все числа, на которые введённое число делится без остатка. 
    // Например, для 60 такими числами станут 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60.

    int num;

    cout << "Введите число: ";
    cin >> num;

    for (int i = 1; i <= num; ++i)
    {
        if (num % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << "\n";

    //-------------------------------------

    // 2. Написать игру «Угадай число». 
    // Пользователь мысленно загадывает число от 0 до 1000, компьютер отгадывает его за минимальное количество попыток.

    int start = 0;
    int end = 1000;
    int guess;
    char answer;
    int attempts = 0;

    cout << "Загадайте число от 0 до 1000\n";

    while (start <= end) 
    {
        guess = (start + end) / 2;
        attempts++;

        cout << "Ваше число " << guess << "? (введите '+' если больше, '-' если меньше, '=' если угадал): ";
        cin >> answer;

        if (answer == '=')
        {
            cout << "Я угадал ваше число за " << attempts << " попыток!\n";
            break;
        }
        else if (answer == '+')
        {
            start = guess + 1;
        }
        else if (answer == '-')
        {
            end = guess - 1;
        }
        else 
        {
            cout << "Ошибка! Используйте только '+', '-', или '='\n";
        }
    }

    //-------------------------------------

    // 3. Ежемесячная стипендия студента составляет N гривен, а расходы на проживание превышают стипендию и составляют M гривен в месяц. 
    // Рост цен ежемесячно увеличивает расходы на 3%. 
    // Составьте программу расчёта суммы денег, которую необходимо единовременно попросить у родителей, 
    // чтобы можно было прожить учебный год (10 месяцев), используя только эти деньги и стипендию.

    double N;
    double M;
    double total_needed = 0;
    double expenses;

    cout << "Введите размер ежемесячной стипендии: ";
    cin >> N;
    cout << "Введите ежемесячные расходы: ";
    cin >> M;

    expenses = M;

    for (int month = 1; month <= 10; ++month)
    {
        if (expenses > N)
        {
            total_needed += (expenses - N);
        }
        expenses *= 1.03;
    }
    cout << "Нужно попросить у родителей " << total_needed << " гривен\n";

    //-------------------------------------

    // 4. Скоро Новый год! Необходимо срочно нарисовать ёлочку. 
    // С клавиатуры вводится количество ярусов, и высота каждого яруса ёлочки.

    int tiers;
    int height;

    cout << "Введите количество ярусов: ";
    cin >> tiers;
    cout << "Введите высоту каждого яруса: ";
    cin >> height;

    int max_width = 2 * (height + tiers - 1) - 1;

    for (int tier = 0; tier < tiers; ++tier) 
    {
        for (int row = 0; row < height; ++row) 
        {
            int stars = 2 * (row + tier) + 1;
            int spaces = (max_width - stars) / 2;

            for (int i = 0; i < spaces; ++i) 
            {
                cout << " ";
            }
            for (int i = 0; i < stars; ++i) 
            {
                cout << "*";
            }
            cout << "\n";
        }
    }
    for (int i = 0; i < 2; ++i) 
    {
        for (int j = 0; j < (max_width - 3) / 2; ++j) 
        {
            cout << " ";
        }
        cout << "***\n";
    }

}


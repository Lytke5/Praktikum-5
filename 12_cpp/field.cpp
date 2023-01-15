#include <iostream>
#include "field.h"

using namespace std;

Field::Field(int size_, int bombAmount)
{
    size = size_;

    srand(time(0));

    for(int i = 0; i < size; i++) // Feld befüllung
    {
        for (int j = 0; j < size; j++)
        {
            field[i][j] = '*';
            fieldIntern[i][j] = false;
        }
    }

    for(int i = 0; i < bombAmount; i++) // Bomben werden plaziert
    {
        int h = rand() % size;
        int v = rand() % size;
        fieldIntern[v][h] = true;
    }
}

void Field::printField()
{
    cout << "   ";
    SetConsoleTextAttribute(hConsole, 11);
    for(int i = 0; i < size; i++) // Buchstabenausgabe
    {
        int a = i+65;
        cout << (char)a << " ";
    }
    cout << endl;

    for(int i = 0; i < size; i++) // Feldausgabe
    {
        SetConsoleTextAttribute(hConsole, 11);
        if(i < 10)
            cout << " ";
        cout << i << " ";
        SetConsoleTextAttribute(hConsole, 15);
        for (int j = 0; j < size; j++)
        {
            if(field[i][j] == '#')
                SetConsoleTextAttribute(hConsole, 12);
            else if(field[i][j] == 'P')
                SetConsoleTextAttribute(hConsole, 10);

            cout << field[i][j] << " ";
             SetConsoleTextAttribute(hConsole, 15);
        }
        cout << endl;
    }
}

char Field::sweepMine(int v, int h)
{
    int mines = 0;
    if(h-1 >= 0)
    {
    if(fieldIntern[v-1][h-1] == true)
        mines++;
    if(fieldIntern[v][h-1] == true)
        mines++;
    if(fieldIntern[v+1][h-1] == true)
        mines++;
    }
    if(h+1 <= size)
    {
    if(fieldIntern[v-1][h+1] == true)
        mines++;
    if(fieldIntern[v][h+1] == true)
        mines++;
    if(fieldIntern[v+1][h+1] == true)
        mines++;
    }

    if(fieldIntern[v-1][h] == true)
        mines++;
    if(fieldIntern[v+1][h] == true)
        mines++;


 return (char)mines+48;
}

void Field::openField(int v, int h)
{
    if(sweepMine(v, h) == '0')
    {
        if(fieldIntern[v][h] == false)
        {
        field[v][h] = '_';

        if(h-1 >= 0)
        {
        if(field[v-1][h-1] == '*')
        openField(v-1, h-1);
        if(field[v][h-1] == '*')
        openField(v, h-1);
        if(field[v+1][h-1] == '*')
        openField(v+1, h-1);
        }

        if(h +1 < size)
        {
        if(field[v-1][h+1] == '*')
        openField(v-1, h+1);
        if(field[v+1][h+1] == '*')
        openField(v+1, h+1);
        if(field[v][h+1] == '*')
        openField(v, h+1);
        }

        if(field[v-1][h] == '*')
        openField(v-1, h);
        if(field[v+1][h] == '*')
        openField(v+1, h);
        }
    }
    else
    {
        field[v][h] = sweepMine(v, h);
    }
}

bool Field::getFieldIntern(int v, int h)
{
    return fieldIntern[v][h];
}

char Field::getField(int v, int h)
{
    return field[v][h];
}

void Field::setField(int v, int h, char c)
{
    field[v][h] = c;
}

int Field::getScore()
{
    int score = 0;
    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(field[i][j] != '*' && field[i][j] != '#' && field[i][j] != 'P')
                score++;
        }
    }
    return score;
}

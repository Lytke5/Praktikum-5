#include <iostream>
#include <cctype>
#include <Windows.h>
#include <fstream>
#include <string>
#include "field.h"

using namespace std;

int highscores[11] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
string names[11] = {"x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x"};
ofstream out;

int LetterToNumber(char c)
{
    int a = (int)c;
    a -= 97;
    return a;
}
void getHighscoresFromFile()
{
    ifstream in("highscores.txt");
        if(in.is_open())
        {
            string line;

            int i = 0;
            bool isName = true;
            while(getline(in, line))
            {
                if(isName)
                {
                    names[i] = line;
                }
                else
                {
                    highscores[i] = stoi(line);
                    i++;
                }

                isName = !isName;
            }
            in.close();
        }
}


void FindRank(string n, int s)
{   
    getHighscoresFromFile();
    highscores[10] = s;
    names[10] = n;

    for (int i = 11; i > 0; i--) {
        if (highscores[i] > highscores[i - 1]) {

            int temp1 = highscores[i];
            string temp2 = names[i];

            highscores[i] = highscores[i - 1];
            highscores[i - 1] = temp1;

            names[i] = names[i - 1];
            names[i - 1] = temp2;
        }
    }

    out.open("highscores.txt");

    for(int i = 0; i < 10; i++)
    {
        out << names[i] << endl << highscores[i] << endl;
    }

    out.close();
}

int main()
{   
    int answer;
    int currScore = 0;
    int bombAmount = 10;
    int fieldSize = 10;
    string currName;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 15); // helles weiß

    do{
        do{
            do {
                system("cls");
                cout << "Welcome to Minesweeper" << endl << endl;
                cout << "(1) Instruction" << endl << endl;
                cout << "(2) Play" << endl << endl;
                cout << "(3) Highscore" << endl << endl;
                cout << "(4) Settings" << endl << endl;
                cout << "(5) Exit" << endl << endl;

                cin >> answer;
            } while(answer < 0 || answer > 6);

            system("cls");

            switch(answer)
            {
            case 1: // Anleitung
                cout << "Minesweeper is a predictable logic and thinking game." << endl;
                Sleep(2000);
                cout << "The numbers indicate how many bombs are within eight squares of the tiles." << endl;
                Sleep(2000);
                cout << "Set markers to keep track of where bombs are likely to be." << endl;
                Sleep(2000);
                cout << "Uncover all tiles without activating a bomb to win the game!" << endl;
                Sleep(4000);
                break;
            case 3: //Bestenliste
                getHighscoresFromFile();
                for(int i = 0; i < 10; i++)
                {
                    if(i == 0)
                        SetConsoleTextAttribute(hConsole, 14); // helles gelb
                    else if(i == 1)
                        SetConsoleTextAttribute(hConsole, 8); // silber
                    else if(i == 2)
                        SetConsoleTextAttribute(hConsole, 12); // helles rot
                    else
                        SetConsoleTextAttribute(hConsole, 15); // helles weiß

                    if(highscores[i] != -1)
                        cout << i+1 << ". " << names[i] << " with " << highscores[i] << " points" << endl;
                    Sleep(500);
                }
                Sleep(1000);
                break;
            case 4: // Einstellungen
                cout << "Currently there are " << bombAmount << " bombs. How many bombs should there be? ";
                cin >> bombAmount;
                cout << endl;
                do{
                    cout << "Currently the field is " << fieldSize << " tiles large. How big should it be (max. 26)? ";
                    cin >> fieldSize;
                }while (fieldSize > 26);
                cout << endl;
                break;
            }
        }while(answer == 1 || answer == 3 || answer == 4);
        if(answer == 2)
        {
            char coordinateLetter;
            int coordinateV;
            bool gameOver = false;

            Field myField(fieldSize, bombAmount);

            do
            {
                bool mark = false;
                myField.printField();
                do{
                    cout << endl;
                    cout << "Coordinates (e.g. A5) or '.XX' for (un)marking: ";
                    cin >> coordinateLetter;
                    if(coordinateLetter == '.')
                    {
                        mark = true;
                        cin >> coordinateLetter;
                    }
                    cin >> coordinateV;

                    coordinateLetter = tolower(coordinateLetter);

                }while((int)coordinateLetter < 97 || (int)coordinateLetter > fieldSize + 96 || coordinateV < 0 || coordinateV > fieldSize-1);


                coordinateLetter = tolower(coordinateLetter);
                int coordinateH = LetterToNumber(coordinateLetter);

                if(mark == true)
                {
                    if(myField.getField(coordinateV, coordinateH) != 'P')
                    myField.setField(coordinateV, coordinateH, 'P');
                    else
                        myField.setField(coordinateV, coordinateH, '*');
                }

                else
                {
                    if(myField.getFieldIntern(coordinateV,coordinateH) == false) //Soll Feld geöffent werden oder wurde Bombe erwischt?
                    {
                        if(myField.getField(coordinateV,coordinateH) == '*')
                            myField.openField(coordinateV, coordinateH);
                    }
                    else
                    {
                        myField.setField(coordinateV, coordinateH, '#');
                        gameOver = true;
                    }
                }
                system("cls");

            }while(!gameOver);

                                //Wenn Spiel vorbei!

            myField.printField();

            currScore = myField.getScore();

            cout << "You lost!" << endl;
            cout << "Your score: " << currScore << "!" << endl;
            cout << "Name: ";
            cin >> currName;

            FindRank(currName, currScore);
        }
    }while(answer != 5);

    return 0;
}

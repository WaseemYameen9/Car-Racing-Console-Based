#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;
char path[19][30];
int live = 3;
int carx = 17;
int cary = 11;
int score = 0;
char flag = '0';
int road1xx = 1;
int road1yy = 5;
char item1 = 'H';
char item2 = 'C';
char item3 = '.';
char item4 = 'C';
int road2xx = 5;
int road2yy = 11;
int road3xx = 13;
int road3yy = 17;
int road4xx = 2;
int road4yy = 23;
int health = 100;
char previousitem1 = ' ';
char previousitem2 = ' ';
char previousitem3 = ' ';
char previousitem4 = ' ';
void header()
{
    cout << "         _________    ____     ____  ___   ___________   ________  " << endl;
    cout << "        / ____/   |  / __ |   / __ ||   | / ____/  _/ | / / ____/  " << endl;
    cout << "       / /   / /| | / /_/ /  / /_/ / /| |/ /    / //  |/ / / __    " << endl;
    cout << "      / /___/ ___ |/ _, _/  / _, _/ ___ / /____/ // /|  / /_/ /    " << endl;
    cout << "      |____/_/  |_/_/ |_|  /_/ |_/_/  |_|____/___/_/ |_/|____/     " << endl;
    cout << endl;
    cout << "BY MUHAMMAD WASEEM 2021-CS-61" << endl;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void gameover()
{
    flag = '1';
}
void load()
{
    fstream newwfile;
    newwfile.open("path.txt", ios::in);
    string line;
    for (int row = 0; row < 19; row++)
    {
        getline(newwfile, line);
        for (int col = 0; col < 30; col++)
        {
            path[row][col] = line[col];
        }
    }
    newwfile.close();
}
void display()
{
    for (int row = 0; row < 19; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            cout << path[row][col];
        }
        cout << endl;
    }
}
void movecarleft()
{
    if (path[carx][cary - 4] != '|')
    {
        path[carx][cary] = ' ';
        gotoxy(cary, carx);
        cout << " ";
        cary = cary - 6;
        gotoxy(cary, carx);
        cout << "^";
    }
}
void movecarright()
{
    if (path[carx][cary + 4] != '|')
    {
        path[carx][cary] = ' ';
        gotoxy(cary, carx);
        cout << " ";
        cary = cary + 6;
        gotoxy(cary, carx);
        cout << "^";
    }
}
void movecarup()
{

    path[carx][cary] = ' ';
    gotoxy(cary, carx);
    cout << " ";
    carx = carx - 1;
    gotoxy(cary, carx);
    cout << "^";
}
void movecardown()
{
    if (path[carx + 1][cary] == '#')
    {
    }
    else
    {
        path[carx][cary] = ' ';
        gotoxy(cary, carx);
        cout << " ";
        carx = carx + 1;
        gotoxy(cary, carx);
        cout << "^";
    }
}
void road1()
{
    path[road1xx][road1yy] = previousitem1;
    gotoxy(road1yy, road1xx);
    cout << previousitem1;
    road1xx = road1xx + 1;
    previousitem1 = path[road1xx][road1yy];
    gotoxy(road1yy, road1xx);
    cout << item1;

    if (road1xx == 17)
    {
        gotoxy(road1yy, road1xx);
        cout << ' ';
        int num = (rand() % 3) + 1;
        if (num == 1)
        {
            item1 = 'H';
        }
        if (num == 2)
        {
            item1 = '.';
        }
        if (num == 3)
        {
            item1 = 'C';
        }
        road1xx = 1;
        road1yy = 5;
    }
}
void road2()
{
    path[road2xx][road2yy] = previousitem2;
    gotoxy(road2yy, road2xx);
    cout << previousitem2;
    road2xx = road2xx + 1;
    previousitem2 = path[road2xx][road2yy];
    gotoxy(road2yy, road2xx);
    cout << item2;
    if (road2xx == 17)
    {
        gotoxy(road2yy, road2xx);
        cout << ' ';
        int num = (rand() % 3) + 1;
        if (num == 1)
        {
            item2 = '.';
        }
        if (num == 2)
        {
            item2 = 'C';
        }
        if (num == 3)
        {
            item2 = 'H';
        }
        road2xx = 1;
        road2yy = 11;
    }
}
void road3()
{
    path[road3xx][road3yy] = previousitem3;
    gotoxy(road3yy, road3xx);
    cout << previousitem3;
    road3xx = road3xx + 1;
    previousitem3 = path[road3xx][road3yy];
    gotoxy(road3yy, road3xx);
    cout << item3;
    if (road3xx == 17)
    {
        gotoxy(road3yy, road3xx);
        cout << ' ';
        int num = (rand() % 3) + 1;
        if (num == 1)
        {
            item3 = 'C';
        }
        if (num == 2)
        {
            item3 = 'H';
        }
        if (num == 3)
        {
            item3 = '.';
        }
        road3xx = 1;
        road3yy = 17;
    }
}
void road4()
{
    path[road4xx][road4yy] = previousitem4;
    gotoxy(road4yy, road4xx);
    cout << previousitem4;
    road4xx = road4xx + 1;
    previousitem4 = path[road4xx][road4yy];
    gotoxy(road4yy, road4xx);
    cout << item4;
    if (road4xx == 17)
    {
        gotoxy(road4yy, road4xx);
        cout << ' ';
        int num = (rand() % 3) + 1;
        if (num == 1)
        {
            item4 = 'H';
        }
        if (num == 2)
        {
            item4 = 'C';
        }
        if (num == 3)
        {
            item4 = '.';
        }
        road4xx = 1;
        road4yy = 23;
    }
}
void livessco()
{
    if ((carx == road1xx && cary == road1yy))
    {
        if (item1 == 'C')
        {
            item1 = ' ';
            live--;
        }
        if (item1 == '.')
        {
            item1 = ' ';
            score = score + 10;
        }
        if (item1 == 'H')
        {
            item1 = ' ';
            health = health - 33;
        }
    }
    if ((carx == road2xx && cary == road2yy))
    {
        if (item2 == 'C')
        {
            item2 = ' ';
            live--;
        }
        if (item2 == '.')
        {
            item2 = ' ';
            score = score + 10;
        }
        if (item2 == 'H')
        {
            item2 = ' ';
            health = health - 33;
        }
    }
    if ((carx == road3xx && cary == road3yy))
    {
        if (item3 == 'C')
        {
            item3 = ' ';
            live--;
        }
        if (item3 == '.')
        {
            item3 = ' ';
            score = score + 10;
        }
        if (item3 == 'H')
        {
            item3 = ' ';
            health = health - 33;
        }
    }
    if ((carx == road4xx && cary == road4yy))
    {
        if (item4 == 'C')
        {
            item4 = ' ';
            live--;
        }
        if (item4 == '.')
        {
            item4 = ' ';
            score = score + 10;
        }
        if (item4 == 'H')
        {
            item4 = ' ';
            health = health - 33;
        }
    }
    if (health == 1)
    {
        live--;
        health = 100;
    }
}

main()
{
    load();
    system("CLS");
    header();
    Sleep(3000);
    system("CLS");
    display();
    gotoxy(11, 17);
    cout << "^";

    while (flag != '1')
    {
        Sleep(200);

        if (GetAsyncKeyState(VK_LEFT))
        {
            movecarleft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movecarright();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            movecarup();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movecardown();
        }
        if (GetAsyncKeyState(VK_ESCAPE) || live == 0 || score > 500)
        {
            flag = '1';
        }
        livessco();
        road1();
        road2();
        road3();
        road4();

        gotoxy(50, 10);
        cout << "LIVES:" << live;
        gotoxy(50, 11);
        cout << "SCORE:" << score;
        gotoxy(50, 12);
        cout << "HEALTH:" << health;
        gotoxy(50, 14);
        cout << "GOAL : 500";
        gotoxy(0, 19);
        cout << " C = CAR" << endl;
        gotoxy(0, 20);
        cout << " . = SCORE" << endl;
        gotoxy(0, 21);
        cout << "H = HURDLE" << endl;
        gotoxy(0, 22);
        cout << "If the car collides with C its life decreases by 1" << endl;
        gotoxy(0, 23);
        cout << "If the car collides with H its health decreases by 33%" << endl;
        gotoxy(0, 24);
        cout << "If the car collides with '.' its score increases by 10" << endl;
    }
    system("CLS");
    cout << "SCORE:" << score << endl;
    if (score > 500)
    {
        cout << "YOU WIN!!!!" << endl;
    }
    else
    {
        cout << "BETTER LUCK NEXT TIME" << endl;
    }
    cout << "THANKS FOR PLAYING... GET BACK SOON..." << endl;
}
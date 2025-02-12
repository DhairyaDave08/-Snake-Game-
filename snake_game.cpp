#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <climits>

using namespace std;

#define MAX_LENGTH 1000

const char DIR_UP = 'U';
const char DIR_DOWN = 'D';
const char DIR_LEFT = 'L';
const char DIR_RIGHT = 'R';

int consoleWidth, consoleHeight;
string playerName;
int highestScore = 0;
int score = 0;

void initScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void setColor(int textColor, int bgColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
}

void hideCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void gotoxy(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(hConsole, coord);
}

void drawBoundary()
{
    setColor(12, 0);
    for (int i = 0; i < consoleWidth; i++)
    {
        gotoxy(i, 0);
        cout << "#";
        gotoxy(i, consoleHeight - 1);
        cout << "#";
    }
    for (int i = 0; i < consoleHeight; i++)
    {
        gotoxy(0, i);
        cout << "#";
        gotoxy(consoleWidth - 1, i);
        cout << "#";
    }
}

struct Point
{
    int xCoord, yCoord;
    Point() {}
    Point(int x, int y)
    {
        xCoord = x;
        yCoord = y;
    }
};

class Snake
{
    int length;
    char direction;

public:
    Point body[MAX_LENGTH];

    Snake(int x, int y)
    {
        length = 3;
        body[0] = Point(x, y);
        direction = DIR_RIGHT;
    }

    int getLength() { return length; }

    void changeDirection(char newDirection)
    {
        if ((newDirection == DIR_UP && direction != DIR_DOWN) ||
            (newDirection == DIR_DOWN && direction != DIR_UP) ||
            (newDirection == DIR_LEFT && direction != DIR_RIGHT) ||
            (newDirection == DIR_RIGHT && direction != DIR_LEFT))
        {
            direction = newDirection;
        }
    }

    bool move(Point &food, vector<Point> &obstacles, int &score)
    {
        gotoxy(body[length - 1].xCoord, body[length - 1].yCoord);
        cout << " ";

        for (int i = length - 1; i > 0; i--)
        {
            body[i] = body[i - 1];
        }

        switch (direction)
        {
        case DIR_UP:
            body[0].yCoord--;
            break;
        case DIR_DOWN:
            body[0].yCoord++;
            break;
        case DIR_RIGHT:
            body[0].xCoord++;
            break;
        case DIR_LEFT:
            body[0].xCoord--;
            break;
        }

        if (body[0].xCoord <= 0 || body[0].xCoord >= consoleWidth - 1 ||
            body[0].yCoord <= 0 || body[0].yCoord >= consoleHeight - 1)
        {
            return false;
        }

        for (int i = 1; i < length; i++)
        {
            if (body[0].xCoord == body[i].xCoord && body[0].yCoord == body[i].yCoord)
                return false;
        }

        for (auto &obs : obstacles)
        {
            if (body[0].xCoord == obs.xCoord && body[0].yCoord == obs.yCoord)
                return false;
        }

        if (body[0].xCoord == food.xCoord && body[0].yCoord == food.yCoord)
        {
            length++;
            score += 100;
            food = Point(rand() % (consoleWidth - 2) + 1, rand() % (consoleHeight - 2) + 1);
        }

        gotoxy(body[0].xCoord, body[0].yCoord);
        setColor(10, 0);
        cout << 'O';

        return true;
    }
};

void getInput(Snake &snake)
{
    if (_kbhit())
    {
        int key = _getch();
        if (key == 224)
            key = _getch();
        if (key == 'w' || key == 'W' || key == 72)
            snake.changeDirection(DIR_UP);
        else if (key == 's' || key == 'S' || key == 80)
            snake.changeDirection(DIR_DOWN);
        else if (key == 'a' || key == 'A' || key == 75)
            snake.changeDirection(DIR_LEFT);
        else if (key == 'd' || key == 'D' || key == 77)
            snake.changeDirection(DIR_RIGHT);
    }
}

void displayScore(int score)
{
    gotoxy(5, 0);
    setColor(10, 0);
    cout << "Score: " << score;
}

void showRuleBook()
{
    system("cls");
    setColor(12, 0);
    gotoxy(5, 1);
    cout << "===================== RULE BOOK =====================";
    gotoxy(5, 2);
    cout << "1. Use 'W' for UP, 'S' for DOWN, 'A' for LEFT, 'D' for RIGHT.";
    gotoxy(5, 3);
    cout << "2. Arrow keys are also allowed";
    gotoxy(5, 4);
    cout << "3. The snake moves in the direction you press.";
    gotoxy(5, 5);
    cout << "4. Eat the food '*' to grow and earn points.";
    gotoxy(5, 6);
    cout << "5. Avoid hitting the walls or your own body.";
    gotoxy(5, 7);
    cout << "6. Each level increases the difficulty with more obstacles.";
    gotoxy(5, 8);
    cout << "7. Press any key to start playing the game.";
    gotoxy(5, 9);
    cout << "=======================================================";
    getch();
}

bool askToRestartGame()
{
    system("cls");
    setColor(4, 0);
    gotoxy(5, 1);
    cout << "Game Over! " << playerName << "'s Score: " << score;
    gotoxy(5, 2);
    cout << "Highest Score: " << highestScore;
    gotoxy(5, 3);
    cout << "1. Restart";
    gotoxy(5, 4);
    cout << "2. Quit";
    int choice;
    gotoxy(5, 5);
    setColor(10, 0);
    cout << "Enter your choice: ";
    cin >> choice;
    return (choice == 1);
}

void getPlayerName()
{
    system("cls");
    setColor(10, 0);
    gotoxy(5, 1);
    cout << "*****  *   *  *****  *   *  *****    ****    *****  *   *  *****";
    gotoxy(5, 2);
    cout << "*      **  *  *   *  *  *   *        *       *   *  ** **  *     ";
    gotoxy(5, 3);
    cout << "*****  * * *  *****  ***    ****     *  **   *****  * * *  ****  ";
    gotoxy(5, 4);
    cout << "    *  *  **  *   *  *  *   *        *   *   *   *  *   *  *     ";
    gotoxy(5, 5);
    cout << "*****  *   *  *   *  *   *  *****    ****    *   *  *   *  *****";
    cout << endl
         << endl;
    gotoxy(5, 7);
    setColor(12, 0);
    cout << "Enter your name: ";
    cin >> playerName;
}

void generateObstacles(vector<Point> &obstacles, int obstacleCount, Snake &snake)
{
    obstacles.clear();
    while (obstacles.size() < obstacleCount)
    {
        Point newObstacle(rand() % (consoleWidth - 2) + 1, rand() % (consoleHeight - 2) + 1);

        bool overlap = false;
        for (int i = 0; i < snake.getLength(); i++)
        {
            if (snake.body[i].xCoord == newObstacle.xCoord && snake.body[i].yCoord == newObstacle.yCoord)
            {
                overlap = true;
                break;
            }
        }

        if (!overlap)
        {
            obstacles.push_back(newObstacle);
        }
    }
}

int main()
{
    srand(time(0));
    initScreen();
    hideCursor();

    getPlayerName();

    while (true)
    {

        if (highestScore == 0)
        {
            showRuleBook();
        }

        int levelChoice = 0;
        while (levelChoice < 1 || levelChoice > 4)
        {
            system("cls");
            setColor(13, 0);
            gotoxy(5, 1);
            cout << "Select difficulty level:";
            gotoxy(5, 2);
            cout << "1. Easy";
            gotoxy(5, 3);
            cout << "2. Medium";
            gotoxy(5, 4);
            cout << "3. High";
            gotoxy(5, 5);
            cout << "4. Expert";
            gotoxy(5, 6);
            cout << "Enter your choice (1-4): ";
            cin >> levelChoice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                levelChoice = 0;
            }
        }

        system("cls");

        int speed = 150;
        int obstacleCount = 14;
        int levelThreshold = 500;
        int gameLevel = 1;
        if (levelChoice == 1)
        {
            speed = 140;
            obstacleCount = 18;
        }

        else if (levelChoice == 2)
        {
            speed = 120;
            obstacleCount = 24;
        }
        else if (levelChoice == 3)
        {
            speed = 100;
            obstacleCount = 28;
        }
        else if (levelChoice == 4)
        {
            speed = 70;
            obstacleCount = 32;
        }
        else
        {
            speed = 100;
            obstacleCount = 24;
        }

        drawBoundary();
        Snake snake(consoleWidth / 2, consoleHeight / 2);
        Point food(rand() % (consoleWidth - 2) + 1, rand() % (consoleHeight - 2) + 1);
        vector<Point> obstacles;
        generateObstacles(obstacles, obstacleCount, snake);

        score = 0;

        while (true)
        {

            gotoxy(food.xCoord, food.yCoord);
            setColor(11, 0);
            cout << "+";

            for (auto &obs : obstacles)
            {
                gotoxy(obs.xCoord, obs.yCoord);
                setColor(0, 14);
                cout << " ";
            }

            displayScore(score);

            getInput(snake);
            if (!snake.move(food, obstacles, score))
                break;

            if (score > highestScore)
            {
                highestScore = score;
            }

            Sleep(speed);
        }

        if (!askToRestartGame())
            break;
    }

    return 0;
}

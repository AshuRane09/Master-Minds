
#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <mmsystem.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;

void grid(void);
void startpage(void);
void border(void);
void mainmenu(void);
void mainmenu1(void);
void mainmenu2(void);
void mainmenu3(void);
void menustart(void);
void startgame(void);
void instruction(void);
void highscore(void);
void helpmenu(void);
void quitgame(void);
void quitgame1(void);
void warmup(void);
void challenge(void);
void wpquestion1(void);
void wpquestion2(void);
void wpquestion3(void);
void wpquestion4(void);
void wpquestion5(void);
int timecount(void);
void checkans(int, int);
int randomize(void);
void quelayout(void);
void chquestion1(void);
void chquestion2(void);
void chquestion3(void);
void chquestion4(void);
void chquestion5(void);
void chquestion6(void);
void chquestion7(void);
void chquestion8(void);
void chquestion9(void);
void chquestion10(void);

int wpscore, chscore = 0, rightans = 0, aa = 0, wwp = 0, wp1 = 0, wp2 = 0, wp3 = 0, q = 0, ii; //global variable for warmup round score

int main()
{
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN); //make console window full screen
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    initwindow(screenWidth, screenHeight, "", -3, -3); //remove bezels
    cout << getmaxx() << "   " << getmaxy() << endl;
    cout << endl
         << "Program is running";
    //grid();
    startpage();
    menustart();
    mainmenu();
    getch();
    closegraph();
    return 0;
}

void startpage()
{
    PlaySound(TEXT("acdc.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    int angle = 0, i, j;
    struct arccoordstype a, b;
    setcolor(WHITE);
    settextstyle(10, 0, 10);
    delay(500);
    outtextxy(getmaxx() / 2 - 150, getmaxy() / 2 - 150, "QUIZ");
    while (angle <= 360)
    {
        setcolor(BLACK);
        arc(getmaxx() / 2, getmaxy() / 2 - 90, angle, angle + 2, 240);
        setcolor(RED);
        getarccoords(&a);
        circle(a.xstart, a.ystart, 85);
        setcolor(BLACK);
        arc(getmaxx() / 2, getmaxy() / 2 - 90, angle, angle + 2, 220);
        setcolor(GREEN);
        getarccoords(&a);
        circle(a.xstart, a.ystart, 65);
        setcolor(BLACK);
        arc(getmaxx() / 2, getmaxy() / 2 - 90, angle, angle + 2, 200);
        getarccoords(&a);
        setcolor(BROWN);
        circle(a.xstart, a.ystart, 45);
        angle = angle + 5;
        delay(50);
    }
    setcolor(MAGENTA);
    settextstyle(10, 0, 10);
    outtextxy(getmaxx() / 2 - 150, getmaxy() / 2 - 150, "QUIZ");
    setcolor(WHITE);
    settextstyle(8, 0, 4);
    outtextxy(getmaxx() / 2 - 120, getmaxy() / 2 + 380, "Loading...!!!");
    setcolor(WHITE);

    for (i = 290; i < 910; i++)
    {
        delay(1);
        line(i, 980, i, 990);
    }
    setcolor(RED);
    settextstyle(10, 0, 10);
    outtextxy(getmaxx() / 2 - 150, getmaxy() / 2 - 150, "QUIZ");

    setcolor(WHITE);
    for (j = 910; j < 1630; j++)
    {
        delay(0.50);
        line(j, 980, j, 990);
    }
    PlaySound(NULL, NULL, 0);
    delay(200);
    cleardevice();
}
void grid()
{
    int z = 0, w = 0;

    while (z < 1919)
    {
        line(z, 0, z, 1079);
        z = z + 50;
    }
    while (w < 1079)
    {
        line(0, w, 1919, w);
        w = w + 50;
    }
}

void border()
{
    setfillstyle(9, 15);
    bar(40, 40, 1869, 50);
    bar(40, 40, 50, 1029);
    bar(40, 1029, 1869, 1039);
    bar(1869, 40, 1879, 1039);
}

void menustart()
{
    border();
    setfillstyle(1, 0);
    bar(0, 0, 1919, 1079);
    border();
    settextstyle(9, 0, 5);
    setcolor(WHITE);
    outtextxy(810, 70, " Welcome To ");
    settextstyle(9, 0, 9.5);
    setfillstyle(4, 15);
    bar(500, 136, 1426, 260);
    setcolor(CYAN);
    outtextxy(520, 150, " Lets Play Quiz ");
    settextstyle(8, 0, 8);
    setcolor(YELLOW);
    setfillstyle(4, 15);
    bar(660, 290, 1250, 400);
    outtextxy(680, 305, " Main Menu ");
}

void mainmenu()
{
    settextstyle(8, 0, 6);
    setcolor(YELLOW);
    setfillstyle(4, 4);
    bar(285, 488, 711, 565);
    outtextxy(300, 500, " Start Game ");
    outtextxy(775, 500, " : >> Start a New Game ");

    setcolor(WHITE);
    setfillstyle(4, 2);
    bar(285, 608, 711, 685);
    outtextxy(300, 620, " High Score ");

    setcolor(WHITE);
    setfillstyle(4, 2);
    bar(285, 728, 711, 808);
    outtextxy(300, 740, " Help Menu  ");

    setcolor(WHITE);
    setfillstyle(4, 2);
    bar(285, 851, 711, 935);
    outtextxy(300, 867, " Quit Game  ");
mm:
{
    int key = getch();

    if (key == 13)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
        startgame();
    }
    else
    {
        switch (key)
        {
        case 00:
        {
            key = getch();
            switch (key)
            {
            case 80:
                PlaySound(NULL, NULL, 0);
                PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
                mainmenu1();
                break;
            case 72:
                PlaySound(NULL, NULL, 0);
                PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
                mainmenu3();
                break;
                /*          case 77:
                               startgame();
                               break;*/
            default:
                cout << endl
                     << "Wrong key pressed";
                mainmenu();
            }
        }
        }
    }

    if ((key != 13) || (key != 72) || (key != 80))
    {
        goto mm;
    }
}
}

void mainmenu1()
{
    settextstyle(8, 0, 6);
    setcolor(WHITE);
    setfillstyle(4, 2);
    bar(285, 488, 711, 565);
    outtextxy(300, 500, " Start Game ");
    outtextxy(775, 500, " : >> Start a New Game ");

    setcolor(YELLOW);
    setfillstyle(4, 4);
    bar(285, 608, 711, 685);
    outtextxy(300, 620, " High Score ");
    outtextxy(775, 620, " : >> View High Score ");

    setcolor(WHITE);
    setfillstyle(4, 2);
    bar(285, 728, 711, 808);
    outtextxy(300, 740, " Help Menu  ");

    setcolor(WHITE);
    setfillstyle(4, 2);
    bar(285, 851, 711, 935);
    outtextxy(300, 867, " Quit Game  ");
mm1:
{
    int key = getch();

    if (key == 13)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
        highscore();
    }
    else
    {
        switch (key)
        {
        case 00:
        {
            key = getch();
            switch (key)
            {
            case 80:
                PlaySound(NULL, NULL, 0);
                PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
                mainmenu2();
                break;
            case 72:
                PlaySound(NULL, NULL, 0);
                PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
                setcolor(WHITE);
                outtextxy(775, 620, " : >> View High Score ");
                mainmenu();
                break;
                /*         case 77:
                  highscore();
                break;*/
            default:
                cout << endl
                     << "Wrong key pressed";
                mainmenu1();
            }
        }
        }
    }
    if ((key != 13) || (key != 72) || (key != 80))
    {
        goto mm1;
    }
}
}

void mainmenu2()
{
    settextstyle(8, 0, 6);
    setcolor(WHITE);
    setfillstyle(4, 2);
    bar(285, 488, 711, 565);
    outtextxy(300, 500, " Start Game ");
    outtextxy(775, 500, " : >> Start a New Game ");

    setcolor(WHITE);
    setfillstyle(4, 2);
    bar(285, 608, 711, 685);
    outtextxy(300, 620, " High Score ");
    outtextxy(775, 620, " : >> View High Score ");

    setcolor(YELLOW);
    setfillstyle(4, 4);
    bar(285, 728, 711, 808);
    outtextxy(300, 740, " Help Menu  ");
    outtextxy(775, 740, " : >> How to Play ");

    setcolor(WHITE);
    setfillstyle(4, 2);
    bar(285, 851, 711, 935);
    outtextxy(300, 867, " Quit Game  ");
mm2:
{
    int key = getch();
    if (key == 13)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
        helpmenu();
    }
    else
    {
        switch (key)
        {
        case 00:
        {
            key = getch();
            switch (key)
            {
            case 80:
                PlaySound(NULL, NULL, 0);
                PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
                mainmenu3();
                break;
            case 72:
                PlaySound(NULL, NULL, 0);
                PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
                setcolor(WHITE);
                outtextxy(775, 500, " : >> Start a New Game ");
                outtextxy(775, 740, " : >> How to Play ");
                mainmenu1();
                break;
                /*       case 77:
                   helpmenu();
                break;*/
            default:
                cout << endl
                     << "Wrong key pressed";
                mainmenu2();
            }
        }
        }
    }
    if ((key != 13) || (key != 72) || (key != 80))
    {
        goto mm2;
    }
}
}

void mainmenu3()
{
    settextstyle(8, 0, 6);
    setcolor(WHITE);
    setfillstyle(4, 2);
    bar(285, 488, 711, 565);
    outtextxy(300, 500, " Start Game ");
    outtextxy(775, 500, " : >> Start a New Game ");

    setcolor(WHITE);
    setfillstyle(4, 2);
    bar(285, 608, 711, 685);
    outtextxy(300, 620, " High Score ");
    outtextxy(775, 620, " : >> View High Score ");

    setcolor(WHITE);
    setfillstyle(4, 2);
    bar(285, 728, 711, 808);
    outtextxy(300, 740, " Help Menu  ");
    outtextxy(775, 740, " : >> How to Play ");

    setcolor(YELLOW);
    setfillstyle(4, 4);
    bar(285, 851, 711, 935);
    outtextxy(300, 867, " Quit Game  ");
    setcolor(RED);
    outtextxy(775, 867, " : >> Close the Game ");

mm3:
{
    int key = getch();

    if (key == 13)
    {
        cleardevice();
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
        quitgame();
    }
    else
    {
        switch (key)
        {
        case 00:
        {
            key = getch();
            switch (key)
            {
            case 80:
                PlaySound(NULL, NULL, 0);
                PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
                setcolor(WHITE);
                outtextxy(775, 620, " : >> View High Score ");
                outtextxy(775, 740, " : >> How to Play ");
                outtextxy(775, 867, " : >> Close the Game ");
                mainmenu();
                break;
            case 72:
                PlaySound(NULL, NULL, 0);
                PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
                setcolor(WHITE);
                outtextxy(775, 500, " : >> Start a New Game ");
                outtextxy(775, 620, " : >> View High Score ");
                outtextxy(775, 867, " : >> Close the Game ");
                mainmenu2();
                break;
                /*   case 77:
                  cleardevice();
                  quitgame();
               break;*/
            default:
                cout << endl
                     << "Wrong key pressed";
                mainmenu3();
            }
        }
        }
    }
    if ((key != 13) || (key != 72) || (key != 80))
    {
        goto mm3;
    }
}
} //mainmenu3 ends

void startgame()
{
    PlaySound(NULL, NULL, 0);
    ofstream fout;
    fout.open("quiz.txt", ios::out);
    char name[30], last;
    int i;
    cleardevice();
    border();
    settextstyle(8, 0, 9);
    outtextxy(320, 400, " ENTER YOUR NAME :- ");
    //line(600,550,840,550);

    for (i = 0; i < 30; i++)
    {
        last = toupper(getch());
        if (last == 13) //enter
        {
            PlaySound(NULL, NULL, 0);
            PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
            break;
        }

        if (last == 8) //backspace
        {
            name[i - 1] = '\0';

            setfillstyle(SOLID_FILL, BLACK);
            bar(200, 540, 1800, 900);

            setcolor(WHITE);
            settextstyle(8, 0, 7);
            //line(600,550,840,550);
            outtextxy(700, 580, name);
            i = i - 2;
            continue;
        }

        setcolor(WHITE);
        settextstyle(8, 0, 7);
        name[i] = last;
        name[i + 1] = '\0';

        outtextxy(700, 580, name);
    }
    fout << name; //write in file name
    fout.close(); //file close

    delay(100);
    instruction();
} //startgame ends

void instruction()
{
    setbkcolor(12); //background colour
    cleardevice();
    setfillstyle(9, 0);
    bar(50, 30, 1869, 40);     //border
    bar(50, 30, 60, 1029);     //border
    bar(50, 1029, 1869, 1039); //border
    bar(1869, 30, 1879, 1039); //border

    settextstyle(8, 0, 5);
    setbkcolor(12);
    setcolor(WHITE);
    outtextxy(840, 70, "Welcome to");
    settextstyle(8, 0, 9);
    setcolor(YELLOW);
    outtextxy(180, 110, "------LETS PLAY QUIZ------");
    settextstyle(10, 0, 5);
    setcolor(BLACK);
    outtextxy(250, 220, " HERE ARE SOME TIPS YOU MIGHT WANNA KNOW BEFORE PLAYING : ");
    settextstyle(8, 0, 9);
    setcolor(YELLOW);
    outtextxy(180, 252, "--------------------------");
    settextstyle(10, 0, 5);
    setcolor(BLUE);
    outtextxy(180, 340, "There are 2 rounds in this Quiz,");
    setcolor(BLACK);
    outtextxy(980, 340, "WARMUP ROUND & CHALLENGE ROUND.");
    setcolor(GREEN);
    outtextxy(110, 385, "  In warmup round you will be asked a total of 5 questions to test ");
    outtextxy(180, 428, "                     your general knowledge.");
    setcolor(RED);
    outtextxy(120, 485, " You will be eligible to play the game if you give atleast 3 right");
    outtextxy(120, 520, "   answers, otherwise you can't proceed to the Challenge Round.");
    setcolor(GREEN);
    outtextxy(120, 580, " Your game starts with Challenge Round. In this round you will be ");
    outtextxy(135, 620, "asked a total of 10 Questions. Each right answer will get 5 points ");
    setcolor(BLUE);
    outtextxy(120, 680, "  You will be given 4 options and you have to press A,B,C or D to ");
    outtextxy(130, 720, "answer the question. You will be asked questions continuously, till");
    outtextxy(130, 760, "   right answers are given.No negative point for wrong answer.");
    setcolor(RED);
    outtextxy(140, 820, "          If you get a wrong answer the game will end. ");
    setcolor(BLACK);
    settextstyle(10, 0, 8);
    outtextxy(170, 870, "  !!!!!!!! ALL THE BEST !!!!!!!!");
    settextstyle(8, 0, 5);
    outtextxy(530, 980, ": To Continue Press Y else N :");
im:
{
    int key = getch();
    //  switch(key)
    {
        // case 00:
        //   key = getch();
        switch (key)
        {
        case 'Y':
            PlaySound(NULL, NULL, 0);
            PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
            warmup();
            break;
        case 'y':
            PlaySound(NULL, NULL, 0);
            PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
            warmup();
            break;
        case 'N':
            PlaySound(NULL, NULL, 0);
            PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
            cleardevice();
            setbkcolor(BLACK);
            //PlaySound(TEXT("acdc.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
            menustart();
            mainmenu();
            break;
        case 'n':
            PlaySound(NULL, NULL, 0);
            PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
            cleardevice();
            setbkcolor(BLACK);
            //PlaySound(TEXT("acdc.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
            menustart();
            mainmenu();
            break;
        }
    }
    if ((key != 'Y') || (key != 'y') || (key != 'N') || (key != 'n'))
    {
        goto im;
    }
}
}

void helpmenu()
{
    //PlaySound(NULL,NULL,0);
    setbkcolor(9);
    cleardevice();
    setfillstyle(9, 4);
    bar(50, 30, 1869, 40);     //border
    bar(50, 30, 60, 1029);     //border
    bar(50, 1029, 1869, 1039); //border
    bar(1869, 30, 1879, 1039); //border

    settextstyle(8, 0, 5);
    setbkcolor(9);
    setcolor(WHITE);
    outtextxy(840, 70, "Welcome to");
    settextstyle(8, 0, 9);
    setcolor(YELLOW);
    outtextxy(180, 110, "------LETS PLAY QUIZ------");
    settextstyle(10, 0, 5);
    setcolor(BLACK);
    outtextxy(250, 220, " HERE ARE SOME TIPS YOU MIGHT WANNA KNOW BEFORE PLAYING : ");
    settextstyle(8, 0, 9);
    setcolor(YELLOW);
    outtextxy(180, 252, "--------------------------");
    settextstyle(10, 0, 5);
    setcolor(BLUE);
    outtextxy(180, 340, "There are 2 rounds in this Quiz,");
    setcolor(BLACK);
    outtextxy(980, 340, "WARMUP ROUND & CHALLENGE ROUND.");
    setcolor(GREEN);
    outtextxy(110, 385, "  In warmup round you will be asked a total of 5 questions to test ");
    outtextxy(180, 428, "                     your general knowledge.");
    setcolor(RED);
    outtextxy(120, 485, " You will be eligible to play the game if you give atleast 3 right");
    outtextxy(120, 520, "   answers, otherwise you can't proceed to the Challenge Round.");
    setcolor(GREEN);
    outtextxy(120, 580, " Your game starts with Challenge Round. In this round you will be ");
    outtextxy(135, 620, "asked a total of 10 Questions. Each right answer will get 5 points ");
    setcolor(BLUE);
    outtextxy(120, 680, "  You will be given 4 options and you have to press A,B,C or D to ");
    outtextxy(130, 720, "answer the question. You will be asked questions continuously, till");
    outtextxy(130, 760, "   right answers are given.No negative point for wrong answer.");
    setcolor(RED);
    outtextxy(140, 820, "          If you get a wrong answer the game will end. ");
    setcolor(BLACK);
    settextstyle(10, 0, 8);
    outtextxy(170, 870, "  !!!!!!!! ALL THE BEST !!!!!!!!");
    settextstyle(8, 0, 5);
    outtextxy(730, 980, "Press << to GO BACK");
hm:
{
    int key = getch();
    switch (key)
    {
    case 00:
        key = getch();
        switch (key)
        {
        case 75:
            PlaySound(NULL, NULL, 0);
            PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
            cleardevice();
            setbkcolor(BLACK);
            menustart();
            mainmenu2();
            break;
        }
    }
    if (key != 75)
    {
        goto hm;
    }
}
}

void quitgame()
{
    PlaySound(NULL, NULL, 0);
    PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
    border();
    setcolor(WHITE);
    settextstyle(8, 0, 8);
    outtextxy(350, 400, "Do you Want to Quit Game :");

    setcolor(WHITE);
    settextstyle(10, 0, 7);
    outtextxy(730, 550, "YES ");
    outtextxy(880, 550, "<<");
    setcolor(YELLOW);
    outtextxy(1100, 550, " NO");
    outtextxy(1030, 550, ">>");
qm:
{
    int key = getch();
    if (key == 13)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
        cleardevice();
        menustart();
        mainmenu3();
    }
    else
    {
        switch (key)
        {
        case 00:
            key = getch();
            switch (key)
            {
            case 77:
                quitgame1();
                break;

            case 75:
                quitgame1();
                break;
            }
        }
    }
    if ((key != 13) || (key != 77) || (key != 75))
    {
        goto qm;
    }
}
}

void quitgame1()
{
    /*    border();
    setcolor(WHITE);
    settextstyle(8,0,8);
    outtextxy(350,400,"Do you Want to Quit Game :");
*/
    PlaySound(NULL, NULL, 0);
    PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
    setcolor(YELLOW);
    settextstyle(10, 0, 7);
    outtextxy(730, 550, "YES ");
    outtextxy(880, 550, "<<");
    setcolor(WHITE);
    outtextxy(1100, 550, " NO");
    outtextxy(1030, 550, ">>");

qm1:
{
    int key = getch();
    /* switch(key)
     {
      case 00:
         key = getch();
         switch(key)
         {
          case 77:
               quitgame();
               break;
          case 75:
              exit(1);
         }
     }*/
    if (key == 13)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
        delay(300);
        system("cls");
        cout << "Program Closed";
        exit(1);
    }
    else
    {
        switch (key)
        {
        case 00:

            key = getch();
            switch (key)
            {
            case 77:
                quitgame();
                break;
            case 75:
                quitgame();
                break;
            }
        }
    }
    if ((key != 13) || (key != 77) || (key != 75))
    {
        goto qm1;
    }
}
}

void highscore(void)
{
    //PlaySound(NULL,NULL,0);
    char name[30], chsc[50];
    cleardevice();
    border();
    ofstream fout;
    fout.open("quiz.txt", ios::app);

    ifstream fin;
    fin.open("quiz.txt", ios::in); //file open read mode

    fout << endl
         << chscore;
    fout.close();

    fin >> name >> chscore;
    sprintf(chsc, "%d", chscore);
    if (aa == 1)
    {
        settextstyle(9, 0, 9);
        setfillstyle(4, 15);
        bar(580, 136, 1370, 260);
        setcolor(YELLOW);
        outtextxy(600, 150, " Your Score  ");
        aa = 0;
    }

    else
    {
        settextstyle(9, 0, 9);
        setfillstyle(4, 15);
        bar(580, 136, 1370, 260);
        setcolor(YELLOW);
        outtextxy(600, 150, " High Scores ");
    }
    settextstyle(9, 0, 5);
    setcolor(CYAN);
    outtextxy(790, 80, "Lets Play Quiz ");

    setcolor(YELLOW);
    line(460, 450, 1460, 450);
    line(460, 550, 1460, 550);
    line(460, 450, 460, 750);
    line(1460, 450, 1460, 750);
    line(460, 750, 1460, 750);
    line(585, 450, 585, 750);
    line(460, 650, 1460, 650);
    line(1180, 450, 1180, 750);

    settextstyle(10, 0, 7);
    setcolor(WHITE);
    outtextxy(780, 467, "Name ");

    settextstyle(10, 0, 7);
    setcolor(WHITE);
    outtextxy(1200, 467, "Score ");

    settextstyle(10, 0, 7);
    setcolor(WHITE);
    outtextxy(464, 467, "Sno");
    outtextxy(482, 567, "1.");
    outtextxy(482, 667, "2.");

    settextstyle(8, 0, 7);
    outtextxy(610, 570, name);
    outtextxy(1300, 570, chsc);
    settextstyle(8, 0, 6);
    outtextxy(600, 950, "Press << to GO BACK");

    fin.close();
hs:
{
    int key = getch();
    switch (key)
    {
    case 00:
        key = getch();
        switch (key)
        {
        case 75:
            PlaySound(NULL, NULL, 0);
            PlaySound(TEXT("light.wav"), NULL, SND_ASYNC | SND_NOSTOP);
            menustart();
            mainmenu1();
            break;
        }
    }
    if (key != 75)
    {
        goto hs;
    }
}
}

int timecount()
{
    //   cleardevice();
    int hh, mm, ss, ms, z;
    char arrss[50], arrmm[50], arrhh[50], arrms[50];
    hh = 0;
    mm = 0;
    ss = 30;
    ms = 0;

tc: //to avoid breaking if any other key is pressed
{
    while (1)
    {
        if (!kbhit())
        {
            if (ms != 9)
                ms++;
            else
            {
                ms = 0;
                if (ss != 1)
                    ss--;
                else
                {
                    delay(100);
                    cleardevice();
                    settextstyle(8, 0, 9);
                    outtextxy(650, 500, "Time's Up");
                    z = 0;
                    getch();
                    break;
                }
            }

            delay(100);
            setcolor(BLACK);
            setbkcolor(12);
            settextstyle(10, 0, 8);
            sprintf(arrss, "%d", ss);
            //sprintf(arrmm,"%d",mm);
            //sprintf(arrhh,"%d",hh);
            sprintf(arrms, "%d", ms);

            //outtextxy(500,400, arrhh);
            //outtextxy(600,400,":");
            // outtextxy(700,400, arrmm);
            //outtextxy(800,400,":");
            outtextxy(920, 700, "  ");
            outtextxy(925, 710, arrss);
            //outtextxy(1000,400,":");
            //outtextxy(1100,400, arrms);
        }
        else
        {
            //      tc :
            //          {
            char last = getch();
            if (last == 'a' || last == 'A')
            {
                z = 1;
                break;
            }
            else if (last == 'b' || last == 'B')
            {
                z = 2;
                break;
            }
            else if (last == 'c' || last == 'C')
            {
                z = 3;
                break;
            }
            else if (last == 'd' || last == 'D')
            {
                z = 4;
                break;
            }
            if ((last != 'a') || (last != 'b') || (last != 'c') || (last != 'd') || (last != 'A') || (last != 'B') || (last != 'C') || (last != 'D'))
            {
                goto tc;
            }
        }
    }
}
    return (z);
}

int randomize()
{
    int lower = 1, upper = 3, count = 1, i, num1;

    srand(time(0));

    for (i = 0; i < count; i++)
    {
        num1 = ((rand() % (upper - lower + 1)) + lower);
    }
    return (num1);
}

void warmup()
{
    int num;
    setbkcolor(1);
    cleardevice();
    border();
    setcolor(WHITE);
    settextstyle(9, 0, 10);
    setfillstyle(1, 0);
    setfillstyle(1, 0);
    setlinestyle(1, 1, 10);
    rectangle(500, 393, 1400, 617);
    setcolor(YELLOW);
    outtextxy(510, 400, "WARM UP");
    settextstyle(9, 0, 8);
    setcolor(YELLOW);
    outtextxy(810, 532, "Round");

    settextstyle(8, 0, 4);
    setcolor(WHITE);
    outtextxy(670, 950, "Press Enter to continue...");
wp:
{
    int k = getch();
    if (k == 13)
    {
        cleardevice();
        wpquestion1();
    }
    else
        goto wp;
}
}

void quelayout()
{
    int i;
    setcolor(YELLOW);
    setlinestyle(5, 1, 4);
    if (q == 0)
    {
        for (i = 0; i <= 450; i = i + 100)
        {
            circle(760 + i, 540, 20);

            setfillstyle(1, 5);
            floodfill(761 + i, 541, YELLOW);
        }
    }

    if (q == 1)
    {
        for (i = 0; i <= 950; i = i + 100)
        {
            circle(520 + i, 540, 20);

            setfillstyle(1, 5);
            floodfill(521 + i, 541, YELLOW);
        }
    }

    line(480, 120, 1400, 120);
    line(480, 230, 1400, 230);
    line(420, 175, 480, 120);
    line(420, 175, 480, 230);
    line(1400, 120, 1460, 175);
    line(1400, 230, 1460, 175);

    line(230, 300, 1700, 300);
    line(230, 500, 1700, 500);
    line(130, 400, 230, 300);
    line(130, 400, 230, 500);
    line(1700, 300, 1800, 400);
    line(1700, 500, 1800, 400);
    //setfillstyle(SOLID_FILL, BLUE);
    //floodfill(232,302,WHITE);

    line(230, 600, 835, 600);
    line(230, 700, 835, 700);
    line(180, 650, 230, 600);
    line(180, 650, 230, 700);
    line(835, 600, 885, 650);
    line(835, 700, 885, 650);
    //setfillstyle(SOLID_FILL, BLUE);
    //floodfill(232,602,WHITE);

    line(1095, 600, 1700, 600);
    line(1095, 700, 1700, 700);
    line(1045, 650, 1095, 600);
    line(1045, 650, 1095, 700);
    line(1700, 600, 1750, 650);
    line(1700, 700, 1750, 650);
    //setfillstyle(SOLID_FILL, BLUE);
    //floodfill(1097,602,WHITE);

    line(230, 790, 835, 790);
    line(230, 890, 835, 890);
    line(180, 840, 230, 790);
    line(180, 840, 230, 890);
    line(835, 790, 885, 840);
    line(835, 890, 885, 840);
    //setfillstyle(SOLID_FILL, BLUE);
    //floodfill(232,792,WHITE);

    line(1095, 790, 1700, 790);
    line(1095, 890, 1700, 890);
    line(1045, 840, 1095, 790);
    line(1045, 840, 1095, 890);
    line(1700, 790, 1750, 840);
    line(1700, 890, 1750, 840);
    //setfillstyle(SOLID_FILL, BLUE);
    //floodfill(1097,792,WHITE);

    line(910, 690, 1015, 690);
    line(910, 800, 1015, 800);
    line(855, 745, 910, 690);
    line(855, 745, 910, 800);
    line(1070, 745, 1015, 690);
    line(1070, 745, 1015, 800);
    setfillstyle(SOLID_FILL, 12);
    floodfill(912, 692, YELLOW);
}

void wpquestion1()
{
    int getc, corr = 0, rann, a, last, i;
    setbkcolor(1);
    //cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 1");
    q = 0;
    quelayout();
    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 1+1 ?");
        outtextxy(250, 620, "A :  2");
        outtextxy(1100, 620, "B :  1");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 1+2 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  3");
        outtextxy(250, 820, "C : 2");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 1+3 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B : 2");
        outtextxy(250, 820, "C : 4");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();

    if (getc == 0)
    {
        goto rr;
    }

    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(761, 541, YELLOW);
        wwp = 1;
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(761, 541, YELLOW);
        wwp = 1;
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(761, 541, YELLOW);
        wwp = 1;
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(761, 541, YELLOW);
        wwp = 1;
    }

    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  2");
    }
    if (getc == 2 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  3");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 4");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    getch();
rr:
{
    setbkcolor(13);
    cleardevice();
    setcolor(BLACK);
    setbkcolor(13);
    settextstyle(8, 0, 5);
    outtextxy(1300, 1000, "Loading next Question....");
    a = randomize();
    if (a == 1)
    {
        delay(1000);
    }
    if (a == 2)
    {
        delay(500);
    }
    if (a == 3)
    {
        delay(200);
    }
    wpquestion2();
}
}

void wpquestion2()
{
    int getc, corr = 0, rann, a;
    setbkcolor(1);
    cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 2");

    quelayout();

    if (wwp == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(761, 541, YELLOW);
        wwp = 2;
    }
    else
    {
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
        wwp = 0;
    }

    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 2+1 ?");
        outtextxy(250, 620, "A :  3");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 1");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 2+2 ?");
        outtextxy(250, 620, "A :  2");
        outtextxy(1100, 620, "B : 4");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 2+3 ?");
        outtextxy(250, 620, "A :  3");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 5");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
    {
        goto rr1;
    }

    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(861, 541, YELLOW);
        wp1 = 1;
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(861, 541, YELLOW);
        wp1 = 1;
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(861, 541, YELLOW);
        wp1 = 1;
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(861, 541, YELLOW);
        wp1 = 1;
    }

    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  3");
    }
    if ((getc == 2) && (corr == 1))
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(861, 541, YELLOW);
    }
    if ((getc == 3) && (corr == 1))
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 1");
        setfillstyle(1, RED);
        floodfill(861, 541, YELLOW);
    }
    if ((getc == 4) && (corr == 1))
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(861, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B : 4");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  2");
        setfillstyle(1, RED);
        floodfill(861, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(861, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(861, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 5");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  3");
        setfillstyle(1, RED);
        floodfill(861, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(861, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(861, 541, YELLOW);
    }
    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    getch();
rr1:
{

    setbkcolor(11);
    cleardevice();
    setcolor(BLACK);
    setbkcolor(11);
    settextstyle(8, 0, 5);
    outtextxy(1300, 1000, "Loading next Question....");
    a = randomize();
    if (a == 1)
    {
        delay(1000);
    }
    if (a == 2)
    {
        delay(500);
    }
    if (a == 3)
    {
        delay(200);
    }
    wpquestion3();
}
}

void wpquestion3()
{
    int getc, corr = 0, rann, a;
    setbkcolor(1);
    cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 3");

    quelayout();

    if (wwp == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(761, 541, YELLOW);
        if (wp1 == 1)
        {
            setfillstyle(1, GREEN);
            floodfill(861, 541, YELLOW);
            wp1 = 2;
        }
        else
        {
            setfillstyle(1, RED);
            floodfill(861, 541, YELLOW);
            wp1 = 0;
        }
    }
    if (wwp == 0)
    {
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
        if (wp1 == 1)
        {
            setfillstyle(1, GREEN);
            floodfill(861, 541, YELLOW);
            wp1 = 2;
        }
        else
        {
            setfillstyle(1, RED);
            floodfill(861, 541, YELLOW);
            wp1 = 0;
        }
    }

    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 3+1 ?");
        outtextxy(250, 620, "A :  4");
        outtextxy(1100, 620, "B :  3");
        outtextxy(250, 820, "C : 1");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 3+2 ?");
        outtextxy(250, 620, "A :  3");
        outtextxy(1100, 620, "B : 5");
        outtextxy(250, 820, "C : 2");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 3+3 ?");
        outtextxy(250, 620, "A :  3");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 6");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
    {
        goto rr2;
    }

    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(961, 541, YELLOW);
        wp2 = 1;
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(961, 541, YELLOW);
        wp2 = 1;
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(961, 541, YELLOW);
        wp2 = 1;
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(961, 541, YELLOW);
        wp2 = 1;
    }

    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  4");
    }
    if (getc == 2 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  3");
        setfillstyle(1, RED);
        floodfill(961, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 1");
        setfillstyle(1, RED);
        floodfill(961, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(961, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B : 5");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  3");
        setfillstyle(1, RED);
        floodfill(961, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 2");
        setfillstyle(1, RED);
        floodfill(961, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(961, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 6");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  3");
        setfillstyle(1, RED);
        floodfill(961, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(961, 541, YELLOW);
    }

    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(961, 541, YELLOW);
    }
    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    getch();
rr2:
{
    setbkcolor(13);
    cleardevice();
    setcolor(BLACK);
    setbkcolor(13);
    settextstyle(8, 0, 5);
    outtextxy(1300, 1000, "Loading next Question....");
    a = randomize();
    if (a == 1)
    {
        delay(1000);
    }
    if (a == 2)
    {
        delay(500);
    }
    if (a == 3)
    {
        delay(200);
    }
    wpquestion4();
}
}

void wpquestion4()
{
    int getc, corr = 0, rann, a;
    setbkcolor(1);
    cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 4");

    quelayout();

    if (wwp == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(761, 541, YELLOW);
        if (wp1 == 2)
        {
            setfillstyle(1, GREEN);
            floodfill(861, 541, YELLOW);
            if (wp2 == 1)
            {
                setfillstyle(1, GREEN);
                floodfill(961, 541, YELLOW);
                wp2 = 2;
            }
            else
            {
                setfillstyle(1, RED);
                floodfill(961, 541, YELLOW);
                wp2 = 0;
            }
        }
        if (wp1 == 0)
        {
            setfillstyle(1, RED);
            floodfill(861, 541, YELLOW);
            if (wp2 == 1)
            {
                setfillstyle(1, GREEN);
                floodfill(961, 541, YELLOW);
                wp2 = 2;
            }
            else
            {
                setfillstyle(1, RED);
                floodfill(961, 541, YELLOW);
                wp2 = 0;
            }
        }
    }
    if (wwp == 0)
    {
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);

        if (wp1 == 2)
        {
            setfillstyle(1, GREEN);
            floodfill(861, 541, YELLOW);
            if (wp2 == 1)
            {
                setfillstyle(1, GREEN);
                floodfill(961, 541, YELLOW);
                wp2 = 2;
            }
            else
            {
                setfillstyle(1, RED);
                floodfill(961, 541, YELLOW);
                wp2 = 0;
            }
        }
        if (wp1 == 0)
        {
            setfillstyle(1, RED);
            floodfill(861, 541, YELLOW);
            if (wp2 == 1)
            {
                setfillstyle(1, GREEN);
                floodfill(961, 541, YELLOW);
                wp2 = 2;
            }
            else
            {
                setfillstyle(1, RED);
                floodfill(961, 541, YELLOW);
                wp2 = 0;
            }
        }
    }
    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 4+1 ?");
        outtextxy(250, 620, "A :  5");
        outtextxy(1100, 620, "B :  4");
        outtextxy(250, 820, "C : 1");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 4+2 ?");
        outtextxy(250, 620, "A :  4");
        outtextxy(1100, 620, "B : 6");
        outtextxy(250, 820, "C : 2");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 4+3 ?");
        outtextxy(250, 620, "A :  4");
        outtextxy(1100, 620, "B :  3");
        outtextxy(250, 820, "C : 7");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
    {
        goto rr3;
    }

    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(1061, 541, YELLOW);
        wp3 = 1;
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(1061, 541, YELLOW);
        wp3 = 1;
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(1061, 541, YELLOW);
        wp3 = 1;
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(1061, 541, YELLOW);
        wp3 = 1;
    }

    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  5");
    }
    if (getc == 2 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  4");
        setfillstyle(1, RED);
        floodfill(1061, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 1");
        setfillstyle(1, RED);
        floodfill(1061, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1061, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B : 6");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  4");
        setfillstyle(1, RED);
        floodfill(1061, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 2");
        setfillstyle(1, RED);
        floodfill(1061, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1061, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 7");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  4");
        setfillstyle(1, RED);
        floodfill(1061, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  3");
        setfillstyle(1, RED);
        floodfill(1061, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1061, 541, YELLOW);
    }
    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    getch();
rr3:
{
    setbkcolor(12);
    cleardevice();
    setcolor(BLACK);
    setbkcolor(12);
    settextstyle(8, 0, 5);
    outtextxy(1300, 1000, "Loading next Question....");
    a = randomize();
    if (a == 1)
    {
        delay(1000);
    }
    if (a == 2)
    {
        delay(500);
    }
    if (a == 3)
    {
        delay(200);
    }

    wpquestion5();
}
}

void wpquestion5()
{
    int getc, corr = 0, rann;
    setbkcolor(1);
    cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 5");

    quelayout();

    if (wwp == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(761, 541, YELLOW);
        if (wp1 == 2)
        {
            setfillstyle(1, GREEN);
            floodfill(861, 541, YELLOW);
            if (wp2 == 2)
            {
                setfillstyle(1, GREEN);
                floodfill(961, 541, YELLOW);
                if (wp3 == 1)
                {
                    setfillstyle(1, GREEN);
                    floodfill(1061, 541, YELLOW);
                }
                else
                {
                    setfillstyle(1, RED);
                    floodfill(1061, 541, YELLOW);
                }
            }
            else
            {
                setfillstyle(1, RED);
                floodfill(961, 541, YELLOW);
                if (wp3 == 1)
                {
                    setfillstyle(1, GREEN);
                    floodfill(1061, 541, YELLOW);
                }
                else
                {
                    setfillstyle(1, RED);
                    floodfill(1061, 541, YELLOW);
                }
            }
        }
        if (wp1 == 0)
        {
            setfillstyle(1, RED);
            floodfill(861, 541, YELLOW);
            if (wp2 == 2)
            {
                setfillstyle(1, GREEN);
                floodfill(961, 541, YELLOW);
                if (wp3 == 1)
                {
                    setfillstyle(1, GREEN);
                    floodfill(1061, 541, YELLOW);
                }
                else
                {
                    setfillstyle(1, RED);
                    floodfill(1061, 541, YELLOW);
                }
            }
            else
            {
                setfillstyle(1, RED);
                floodfill(961, 541, YELLOW);
                if (wp3 == 1)
                {
                    setfillstyle(1, GREEN);
                    floodfill(1061, 541, YELLOW);
                }
                else
                {
                    setfillstyle(1, RED);
                    floodfill(1061, 541, YELLOW);
                }
            }
        }
    }
    if (wwp == 0)
    {
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
        if (wp1 == 2)
        {
            setfillstyle(1, GREEN);
            floodfill(861, 541, YELLOW);
            if (wp2 == 2)
            {
                setfillstyle(1, GREEN);
                floodfill(961, 541, YELLOW);
                if (wp3 == 1)
                {
                    setfillstyle(1, GREEN);
                    floodfill(1061, 541, YELLOW);
                }
                else
                {
                    setfillstyle(1, RED);
                    floodfill(1061, 541, YELLOW);
                }
            }
            else
            {
                setfillstyle(1, RED);
                floodfill(961, 541, YELLOW);
                if (wp3 == 1)
                {
                    setfillstyle(1, GREEN);
                    floodfill(1061, 541, YELLOW);
                }
                else
                {
                    setfillstyle(1, RED);
                    floodfill(1061, 541, YELLOW);
                }
            }
        }
        if (wp1 == 0)
        {
            setfillstyle(1, RED);
            floodfill(861, 541, YELLOW);
            if (wp2 == 2)
            {
                setfillstyle(1, GREEN);
                floodfill(961, 541, YELLOW);
                if (wp3 == 1)
                {
                    setfillstyle(1, GREEN);
                    floodfill(1061, 541, YELLOW);
                }
                else
                {
                    setfillstyle(1, RED);
                    floodfill(1061, 541, YELLOW);
                }
            }
            else
            {
                setfillstyle(1, RED);
                floodfill(961, 541, YELLOW);
                if (wp3 == 1)
                {
                    setfillstyle(1, GREEN);
                    floodfill(1061, 541, YELLOW);
                }
                else
                {
                    setfillstyle(1, RED);
                    floodfill(1061, 541, YELLOW);
                }
            }
        }
    }

    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 5+1 ?");
        outtextxy(250, 620, "A :  6");
        outtextxy(1100, 620, "B :  5");
        outtextxy(250, 820, "C : 1");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 5+2 ?");
        outtextxy(250, 620, "A :  5");
        outtextxy(1100, 620, "B : 7");
        outtextxy(250, 820, "C : 2");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the addition of 5+3 ?");
        outtextxy(250, 620, "A :  5");
        outtextxy(1100, 620, "B :  3");
        outtextxy(250, 820, "C : 8");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
    {
        goto rr4;
    }
    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(1161, 541, YELLOW);
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(1161, 541, YELLOW);
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(1161, 541, YELLOW);
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(1161, 541, YELLOW);
    }

    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  6");
    }
    if (getc == 2 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  5");
        setfillstyle(1, RED);
        floodfill(1161, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 1");
        setfillstyle(1, RED);
        floodfill(1161, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1161, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B : 7");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  5");
        setfillstyle(1, RED);
        floodfill(1161, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 2");
        setfillstyle(1, RED);
        floodfill(1161, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1161, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 8");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  5");
        setfillstyle(1, RED);
        floodfill(1161, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  3");
        setfillstyle(1, RED);
        floodfill(1161, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1161, 541, YELLOW);
    }
    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    getch();
rr4:
{
    cout << wpscore;
    if (wpscore >= 30)
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        settextstyle(8, 0, 6);
        outtextxy(470, 400, "You Are Eligible to play the");
        settextstyle(10, 0, 8);
        outtextxy(600, 500, "CHALLENGE Round");

        settextstyle(8, 0, 4);
        setcolor(BLUE);
        outtextxy(690, 950, "Press Enter to continue...");
    ccr:
    {
        int k = getch();
        if (k == 13)
        {
            cleardevice();
            //wpquestion1();
        }
        else
            goto ccr;
    }
        challenge();
    }
    else
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        settextstyle(8, 0, 6);
        outtextxy(440, 400, "You Are Not Eligible to play the");
        settextstyle(10, 0, 8);
        outtextxy(600, 480, "CHALLENGE Round");
        settextstyle(8, 0, 5);
        outtextxy(680, 950, "Better Luck Next Time...");

        //settextstyle(8,0,4);
    //setcolor(BLUE);
    //outtextxy(690,950,"Press Enter to continue...");
    cccr:
    {
        int k = getch();
        if (k == 13)
        {
            cleardevice();
        }
        else
            goto cccr;
    }
        setbkcolor(BLACK);
        menustart();
        mainmenu();
    }
}
}

void checkans(int ans, int cor)
{
    if (ans == 1)
    {
        setfillstyle(SOLID_FILL, 5);
        floodfill(232, 602, YELLOW);
    }
    if (ans == 2)
    {
        setfillstyle(SOLID_FILL, 5);
        floodfill(1097, 602, YELLOW);
    }
    if (ans == 3)
    {
        setfillstyle(SOLID_FILL, 5);
        floodfill(232, 792, YELLOW);
    }
    if (ans == 4)
    {
        setfillstyle(SOLID_FILL, 5);
        floodfill(1097, 792, YELLOW);
    }
    delay(600);
    /////////////////////////////////////////
    if (ans == 1 && cor == 1)
    {
        setfillstyle(SOLID_FILL, GREEN);
        floodfill(232, 602, YELLOW);
        rightans = 1;
    }

    if (ans == 2 && cor == 2)
    {

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(1097, 602, YELLOW);
        rightans = 1;
    }

    if (ans == 3 && cor == 3)
    {
        setfillstyle(SOLID_FILL, GREEN);
        floodfill(232, 792, YELLOW);
        rightans = 1;
    }

    if (ans == 4 && cor == 4)
    {
        setfillstyle(SOLID_FILL, GREEN);
        floodfill(1097, 792, YELLOW);
        rightans = 1;
    }

    if (ans == 1 && cor == 2)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("buzz1.wav"), NULL, SND_ASYNC | SND_NOSTOP);

        setfillstyle(SOLID_FILL, RED);
        floodfill(232, 602, YELLOW);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(1097, 602, YELLOW);

        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(700, 950, "Incorrect Answer");
    }
    if (ans == 1 && cor == 3)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("buzz1.wav"), NULL, SND_ASYNC | SND_NOSTOP);

        setfillstyle(SOLID_FILL, RED);
        floodfill(232, 602, YELLOW);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(232, 792, YELLOW);

        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(700, 950, "Incorrect Answer");
    }
    if (ans == 1 && cor == 4)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("buzz1.wav"), NULL, SND_ASYNC | SND_NOSTOP);

        setfillstyle(SOLID_FILL, RED);
        floodfill(232, 602, YELLOW);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(1097, 792, YELLOW);

        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(700, 950, "Incorrect Answer");
    }
    if (ans == 2 && cor == 1)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("buzz1.wav"), NULL, SND_ASYNC | SND_NOSTOP);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(232, 602, YELLOW);

        setfillstyle(SOLID_FILL, RED);
        floodfill(1097, 602, YELLOW);

        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(700, 950, "Incorrect Answer");
    }
    if (ans == 2 && cor == 3)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("buzz1.wav"), NULL, SND_ASYNC | SND_NOSTOP);

        setfillstyle(SOLID_FILL, RED);
        floodfill(1097, 602, YELLOW);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(232, 792, YELLOW);

        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(700, 950, "Incorrect Answer");
    }
    if (ans == 2 && cor == 4)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("buzz1.wav"), NULL, SND_ASYNC | SND_NOSTOP);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(1097, 792, YELLOW);

        setfillstyle(SOLID_FILL, RED);
        floodfill(1097, 602, YELLOW);

        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(700, 950, "Incorrect Answer");
    }

    if (ans == 3 && cor == 1)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("buzz1.wav"), NULL, SND_ASYNC | SND_NOSTOP);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(232, 602, YELLOW);

        setfillstyle(SOLID_FILL, RED);
        floodfill(232, 792, YELLOW);

        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(700, 950, "Incorrect Answer");
    }
    if (ans == 3 && cor == 2)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("buzz1.wav"), NULL, SND_ASYNC | SND_NOSTOP);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(1097, 602, YELLOW);

        setfillstyle(SOLID_FILL, RED);
        floodfill(232, 792, YELLOW);

        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(700, 950, "Incorrect Answer");
    }
    if (ans == 3 && cor == 4)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("buzz1.wav"), NULL, SND_ASYNC | SND_NOSTOP);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(1097, 792, YELLOW);

        setfillstyle(SOLID_FILL, RED);
        floodfill(232, 792, YELLOW);

        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(700, 950, "Incorrect Answer");
    }
    if (ans == 4 && cor == 1)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("buzz1.wav"), NULL, SND_ASYNC | SND_NOSTOP);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(232, 602, YELLOW);

        setfillstyle(SOLID_FILL, RED);
        floodfill(1097, 792, YELLOW);

        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(700, 950, "Incorrect Answer");
    }
    if (ans == 4 && cor == 2)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("buzz1.wav"), NULL, SND_ASYNC | SND_NOSTOP);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(1097, 602, YELLOW);

        setfillstyle(SOLID_FILL, RED);
        floodfill(1097, 792, YELLOW);

        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(700, 950, "Incorrect Answer");
    }
    if (ans == 4 && cor == 3)
    {
        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("buzz1.wav"), NULL, SND_ASYNC | SND_NOSTOP);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(232, 792, YELLOW);

        setfillstyle(SOLID_FILL, RED);
        floodfill(1097, 792, YELLOW);

        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(700, 950, "Incorrect Answer");
    }
    ///////////////////////print correct and evaluate score////////////////////////////////////
    if (ans == 1 && cor == 1)
    {
        wpscore = wpscore + 10;
        chscore = chscore + 10;

        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("correct.wav"), NULL, SND_ASYNC | SND_NOSTOP);
        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(750, 950, "Correct Answer");
    }

    if (ans == 2 && cor == 2)
    {
        wpscore = wpscore + 10;
        chscore = chscore + 10;

        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("correct.wav"), NULL, SND_ASYNC | SND_NOSTOP);
        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(750, 950, "Correct Answer");
    }

    if (ans == 3 && cor == 3)
    {
        wpscore = wpscore + 10;
        chscore = chscore + 10;

        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("correct.wav"), NULL, SND_ASYNC | SND_NOSTOP);
        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(750, 950, "Correct Answer");
    }

    if (ans == 4 && cor == 4)
    {
        wpscore = wpscore + 10;
        chscore = chscore + 10;

        PlaySound(NULL, NULL, 0);
        PlaySound(TEXT("correct.wav"), NULL, SND_ASYNC | SND_NOSTOP);
        settextstyle(8, 0, 6);
        setbkcolor(BLUE);
        setcolor(WHITE);
        outtextxy(750, 950, "Correct Answer");
    }
}

void challenge()
{
    int num;
    chscore = 0;
    setbkcolor(1);
    cleardevice();
    border();
    setcolor(WHITE);
    settextstyle(9, 0, 9);
    setfillstyle(1, 0);
    setlinestyle(1, 1, 10);
    rectangle(490, 393, 1360, 617);
    setcolor(YELLOW);
    setbkcolor(BLUE);
    outtextxy(510, 400, "CHALLENGE");
    settextstyle(9, 0, 8);
    setcolor(YELLOW);
    outtextxy(735, 512, "ROUND");

    settextstyle(8, 0, 4);
    setcolor(WHITE);
    outtextxy(670, 950, "Press Enter to continue...");
cr:
{
    int k = getch();
    if (k == 13)
    {
        cleardevice();
        chquestion1();
    }
    else
        goto cr;
}
}

void chquestion1()
{
    int getc, corr = 0, rann, a, last;
    setbkcolor(1);
    //cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 1");
    q = 1;
    quelayout();
    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 1*1 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 1*2 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 1*3 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
    {
        rightans = 0;
        goto rt;
    }
    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(521, 541, YELLOW);
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(521, 541, YELLOW);
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(521, 541, YELLOW);
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(521, 541, YELLOW);
    }

    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
    }
    if (getc == 2 && corr == 1)
    {

        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(521, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(521, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(521, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(521, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(521, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(521, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(521, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(521, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(521, 541, YELLOW);
    }
    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    getch();
rt:
    if (rightans == 1)
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 5);
        outtextxy(1300, 1000, "Loading next Question....");
        a = randomize();
        if (a == 1)
        {
            delay(1000);
        }
        if (a == 2)
        {
            delay(500);
        }
        if (a == 3)
        {
            delay(200);
        }
        chquestion2();
    }
    else
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 8);
        setfillstyle(4, 4);
        bar(675, 390, 1200, 510);
        outtextxy(710, 410, "GAME OVER");
        settextstyle(8, 0, 5);
        outtextxy(550, 1000, "Press Enter to view your Score");
        getch();
        setbkcolor(BLACK);
        aa = 1;
        highscore();
    }
}

void chquestion2()
{
    rightans = 0;
    int getc, corr = 0, rann, a, last;
    setbkcolor(1);
    cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 2");

    quelayout();
    setfillstyle(1, GREEN);
    floodfill(521, 541, YELLOW);

    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 2*1 ?");
        outtextxy(250, 620, "A :  2");
        outtextxy(1100, 620, "B :  1");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 2*2 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  4");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 2*3 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 6");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
        goto rt1;
    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(621, 541, YELLOW);
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(621, 541, YELLOW);
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(621, 541, YELLOW);
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(621, 541, YELLOW);
    }
    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  2");
    }
    if (getc == 2 && corr == 1)
    {

        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  1");
        setfillstyle(1, RED);
        floodfill(621, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(621, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(621, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  4");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(621, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(621, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(621, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 6");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(621, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(621, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(621, 541, YELLOW);
    }
    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    getch();
rt1:
    if (rightans == 1)
    {

        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 5);
        outtextxy(1300, 1000, "Loading next Question....");
        a = randomize();
        if (a == 1)
        {
            delay(1000);
        }
        if (a == 2)
        {
            delay(500);
        }
        if (a == 3)
        {
            delay(200);
        }

        chquestion3();
    }
    else
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 8);
        setfillstyle(4, 4);
        bar(675, 390, 1200, 510);
        outtextxy(710, 410, "GAME OVER");
        settextstyle(8, 0, 5);
        outtextxy(550, 1000, "Press Enter to view your Score");
        getch();
        setbkcolor(BLACK);
        aa = 1;
        highscore();
    }
}

void chquestion3()
{
    rightans = 0;
    int getc, corr = 0, rann, a, last;
    setbkcolor(1);
    cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 3");

    quelayout();
    setfillstyle(1, GREEN);
    floodfill(521, 541, YELLOW);
    setfillstyle(1, GREEN);
    floodfill(621, 541, YELLOW);

    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 3*1 ?");
        outtextxy(250, 620, "A :  3");
        outtextxy(1100, 620, "B :  1");
        outtextxy(250, 820, "C : 2");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 3*2 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  6");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 3*3 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 9");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
        goto rt3;
    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(721, 541, YELLOW);
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(721, 541, YELLOW);
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(721, 541, YELLOW);
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(721, 541, YELLOW);
    }
    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  3");
    }
    if (getc == 2 && corr == 1)
    {

        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  1");
        setfillstyle(1, RED);
        floodfill(721, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 2");
        setfillstyle(1, RED);
        floodfill(721, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(721, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  6");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(721, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(721, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(721, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 9");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(721, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(721, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(721, 541, YELLOW);
    }
    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    getch();
rt3:
    if (rightans == 1)
    {

        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 5);
        outtextxy(1300, 1000, "Loading next Question....");
        a = randomize();
        if (a == 1)
        {
            delay(1000);
        }
        if (a == 2)
        {
            delay(500);
        }
        if (a == 3)
        {
            delay(200);
        }
        chquestion4();
    }
    else
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 8);
        setfillstyle(4, 4);
        bar(675, 390, 1200, 510);
        outtextxy(710, 410, "GAME OVER");
        settextstyle(8, 0, 5);
        outtextxy(550, 1000, "Press Enter to view your Score");
        getch();
        setbkcolor(BLACK);
        aa = 1;
        highscore();
    }
}

void chquestion4()
{
    rightans = 0;
    int getc, corr = 0, rann, a, last;
    setbkcolor(1);
    cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 4");

    quelayout();
    for (ii = 0; ii < 210; ii = ii + 100)
    {
        setfillstyle(1, GREEN);
        floodfill(521 + ii, 541, YELLOW);
    }

    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 4*1 ?");
        outtextxy(250, 620, "A :  4");
        outtextxy(1100, 620, "B :  1");
        outtextxy(250, 820, "C : 2");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 4*2 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  8");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 4*3 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 12");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
        goto rt4;
    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(821, 541, YELLOW);
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(821, 541, YELLOW);
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(821, 541, YELLOW);
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(821, 541, YELLOW);
    }

    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  4");
    }
    if (getc == 2 && corr == 1)
    {

        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  1");
        setfillstyle(1, RED);
        floodfill(821, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 2");
        setfillstyle(1, RED);
        floodfill(821, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(821, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  8");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(821, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(821, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(821, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 12");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(821, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(821, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(821, 541, YELLOW);
    }

    getch();
rt4:
    if (rightans == 1)
    {

        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 5);
        outtextxy(1300, 1000, "Loading next Question....");
        a = randomize();
        if (a == 1)
        {
            delay(1000);
        }
        if (a == 2)
        {
            delay(500);
        }
        if (a == 3)
        {
            delay(200);
        }
        chquestion5();
    }
    else
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 8);
        setfillstyle(4, 4);
        bar(675, 390, 1200, 510);
        outtextxy(710, 410, "GAME OVER");
        settextstyle(8, 0, 5);
        outtextxy(550, 1000, "Press Enter to view your Score");
        getch();
        setbkcolor(BLACK);
        aa = 1;
        highscore();
    }
}

void chquestion5()
{
    rightans = 0;
    int getc, corr = 0, rann, a, last;
    setbkcolor(1);
    cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 5");

    quelayout();
    for (ii = 0; ii < 310; ii = ii + 100)
    {
        setfillstyle(1, GREEN);
        floodfill(521 + ii, 541, YELLOW);
    }

    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 5*1 ?");
        outtextxy(250, 620, "A :  5");
        outtextxy(1100, 620, "B :  1");
        outtextxy(250, 820, "C : 2");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 5*2 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  10");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 5*3 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 15");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
        goto rt5;
    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(921, 541, YELLOW);
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(921, 541, YELLOW);
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(921, 541, YELLOW);
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(921, 541, YELLOW);
    }

    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  5");
    }
    if (getc == 2 && corr == 1)
    {

        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  1");
        setfillstyle(1, RED);
        floodfill(921, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 2");
        setfillstyle(1, RED);
        floodfill(921, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(921, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  10");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(921, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(921, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(921, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 15");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(921, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(921, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(921, 541, YELLOW);
    }
    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    getch();
rt5:
    if (rightans == 1)
    {
    rr:
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 5);
        outtextxy(1300, 1000, "Loading next Question....");
        a = randomize();
        if (a == 1)
        {
            delay(1000);
        }
        if (a == 2)
        {
            delay(500);
        }
        if (a == 3)
        {
            delay(200);
        }
    }
        chquestion6();
    }
    else
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 8);
        setfillstyle(4, 4);
        bar(675, 390, 1200, 510);
        outtextxy(710, 410, "GAME OVER");
        settextstyle(8, 0, 5);
        outtextxy(550, 1000, "Press Enter to view your Score");
        getch();
        setbkcolor(BLACK);
        aa = 1;
        highscore();
    }
}

void chquestion6()
{
    rightans = 0;
    int getc, corr = 0, rann, a, last;
    setbkcolor(1);
    cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 6");

    quelayout();
    for (ii = 0; ii < 410; ii = ii + 100)
    {
        setfillstyle(1, GREEN);
        floodfill(521 + ii, 541, YELLOW);
    }
    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 6*1 ?");
        outtextxy(250, 620, "A :  6");
        outtextxy(1100, 620, "B :  1");
        outtextxy(250, 820, "C : 2");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of  6*2 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  12");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 6*3 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 18");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
        goto rt6;
    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(1021, 541, YELLOW);
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(1021, 541, YELLOW);
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(1021, 541, YELLOW);
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(1021, 541, YELLOW);
    }
    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  6");
    }
    if (getc == 2 && corr == 1)
    {

        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  1");
        setfillstyle(1, RED);
        floodfill(1021, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 2");
        setfillstyle(1, RED);
        floodfill(1021, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1021, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  12");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(1021, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(1021, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1021, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 18");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(1021, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(1021, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1021, 541, YELLOW);
    }
    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    getch();
rt6:
    if (rightans == 1)
    {
    rr:
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 5);
        outtextxy(1300, 1000, "Loading next Question....");
        a = randomize();
        if (a == 1)
        {
            delay(1000);
        }
        if (a == 2)
        {
            delay(500);
        }
        if (a == 3)
        {
            delay(200);
        }
    }
        chquestion7();
    }
    else
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 8);
        setfillstyle(4, 4);
        bar(675, 390, 1200, 510);
        outtextxy(710, 410, "GAME OVER");
        settextstyle(8, 0, 5);
        outtextxy(550, 1000, "Press Enter to view your Score");
        getch();
        setbkcolor(BLACK);
        aa = 1;
        highscore();
    }
}

void chquestion7()
{
    rightans = 0;
    int getc, corr = 0, rann, a, last;
    setbkcolor(1);
    cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 7");

    quelayout();
    for (ii = 0; ii < 510; ii = ii + 100)
    {
        setfillstyle(1, GREEN);
        floodfill(521 + ii, 541, YELLOW);
    }
    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 7*1 ?");
        outtextxy(250, 620, "A :  7");
        outtextxy(1100, 620, "B :  1");
        outtextxy(250, 820, "C : 2");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 7*2 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  14");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 7*3 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 21");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
        goto rt7;
    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(1121, 541, YELLOW);
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(1121, 541, YELLOW);
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(1121, 541, YELLOW);
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(1121, 541, YELLOW);
    }
    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  7");
    }
    if (getc == 2 && corr == 1)
    {

        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  1");
        setfillstyle(1, RED);
        floodfill(1121, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 2");
        setfillstyle(1, RED);
        floodfill(1121, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1121, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  14");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(1121, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(1121, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1121, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 21");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(1121, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(1121, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1121, 541, YELLOW);
    }
    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    getch();
rt7:
    if (rightans == 1)
    {
    rr:
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 5);
        outtextxy(1300, 1000, "Loading next Question....");
        a = randomize();
        if (a == 1)
        {
            delay(1000);
        }
        if (a == 2)
        {
            delay(500);
        }
        if (a == 3)
        {
            delay(200);
        }
    }
        chquestion8();
    }
    else
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 8);
        setfillstyle(4, 4);
        bar(675, 390, 1200, 510);
        outtextxy(710, 410, "GAME OVER");
        settextstyle(8, 0, 5);
        outtextxy(550, 1000, "Press Enter to view your Score");
        getch();
        setbkcolor(BLACK);
        aa = 1;
        highscore();
    }
}

void chquestion8()
{
    rightans = 0;
    int getc, corr = 0, rann, a, last;
    setbkcolor(1);
    cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 8");

    quelayout();
    for (ii = 0; ii < 610; ii = ii + 100)
    {
        setfillstyle(1, GREEN);
        floodfill(521 + ii, 541, YELLOW);
    }
    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 8*1 ?");
        outtextxy(250, 620, "A :  8");
        outtextxy(1100, 620, "B :  1");
        outtextxy(250, 820, "C : 2");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 8*2 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  16");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 8*3 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 24");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
        goto rt8;
    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(1221, 541, YELLOW);
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(1221, 541, YELLOW);
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(1221, 541, YELLOW);
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(1221, 541, YELLOW);
    }
    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  8");
    }
    if (getc == 2 && corr == 1)
    {

        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  1");
        setfillstyle(1, RED);
        floodfill(1221, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 2");
        setfillstyle(1, RED);
        floodfill(1221, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1221, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  16");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(1221, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(1221, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1221, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 24");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(1221, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(1221, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1221, 541, YELLOW);
    }
    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    getch();
rt8:
    if (rightans == 1)
    {
    rr:
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 5);
        outtextxy(1300, 1000, "Loading next Question....");
        a = randomize();
        if (a == 1)
        {
            delay(1000);
        }
        if (a == 2)
        {
            delay(500);
        }
        if (a == 3)
        {
            delay(200);
        }
    }
        chquestion9();
    }
    else
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 8);
        setfillstyle(4, 4);
        bar(675, 390, 1200, 510);
        outtextxy(710, 410, "GAME OVER");
        settextstyle(8, 0, 5);
        outtextxy(550, 1000, "Press Enter to view your Score");
        getch();
        setbkcolor(BLACK);
        aa = 1;
        highscore();
    }
}

void chquestion9()
{
    rightans = 0;
    int getc, corr = 0, rann, a, last;
    setbkcolor(1);
    cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 9");

    quelayout();
    for (ii = 0; ii < 710; ii = ii + 100)
    {
        setfillstyle(1, GREEN);
        floodfill(521 + ii, 541, YELLOW);
    }
    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 9*1 ?");
        outtextxy(250, 620, "A :  9");
        outtextxy(1100, 620, "B :  1");
        outtextxy(250, 820, "C : 2");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 9*2 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  18");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 9*3 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 27");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
        goto rt9;
    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(1321, 541, YELLOW);
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(1321, 541, YELLOW);
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(1321, 541, YELLOW);
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(1321, 541, YELLOW);
    }
    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  9");
    }
    if (getc == 2 && corr == 1)
    {

        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  1");
        setfillstyle(1, RED);
        floodfill(1321, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 2");
        setfillstyle(1, RED);
        floodfill(1321, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1321, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  18");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(1321, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(1321, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1321, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 27");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(1321, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(1321, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1321, 541, YELLOW);
    }

    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    getch();
rt9:
    if (rightans == 1)
    {
    rr:
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 5);
        outtextxy(1300, 1000, "Loading next Question....");
        a = randomize();
        if (a == 1)
        {
            delay(1000);
        }
        if (a == 2)
        {
            delay(500);
        }
        if (a == 3)
        {
            delay(200);
        }
    }
        chquestion10();
    }
    else
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 8);
        setfillstyle(4, 4);
        bar(675, 390, 1200, 510);
        outtextxy(710, 410, "GAME OVER");
        settextstyle(8, 0, 5);
        outtextxy(550, 1000, "Press Enter to view your Score");
        getch();
        setbkcolor(BLACK);
        aa = 1;
        highscore();
    }
}

void chquestion10()
{
    //ofstream fout;
    //fout.open("quiz.txt",ios::app);

    int getc, corr = 0, rann;
    setbkcolor(1);
    cleardevice();
    border();

    setfillstyle(SOLID_FILL, 4);
    floodfill(1, 1, WHITE);

    settextstyle(10, 0, 9);
    setcolor(WHITE);
    outtextxy(500, 130, "Question no : 10");

    quelayout();
    for (ii = 0; ii < 810; ii = ii + 100)
    {
        setfillstyle(1, GREEN);
        floodfill(521 + ii, 541, YELLOW);
    }
    rann = randomize();
    if (rann == 1)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 10*1 ?");
        outtextxy(250, 620, "A :  10");
        outtextxy(1100, 620, "B :  1");
        outtextxy(250, 820, "C : 2");
        outtextxy(1100, 820, "D : None ");
        corr = 1;
    }
    if (rann == 2)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 10*2 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  20");
        outtextxy(250, 820, "C : 3");
        outtextxy(1100, 820, "D : None ");
        corr = 2;
    }

    if (rann == 3)
    {
        settextstyle(8, 0, 7);
        setcolor(WHITE);
        outtextxy(300, 350, "What is the multiplication of 10*3 ?");
        outtextxy(250, 620, "A :  1");
        outtextxy(1100, 620, "B :  2");
        outtextxy(250, 820, "C : 30");
        outtextxy(1100, 820, "D : None ");
        corr = 3;
    }

    getc = timecount();
    if (getc == 0)
        goto rt10;
    checkans(getc, corr);

    if (getc == 1 && corr == 1)
    {
        setfillstyle(1, GREEN);
        floodfill(1421, 541, YELLOW);
    }
    if (getc == 2 && corr == 2)
    {
        setfillstyle(1, GREEN);
        floodfill(1421, 541, YELLOW);
    }
    if (getc == 3 && corr == 3)
    {
        setfillstyle(1, GREEN);
        floodfill(1421, 541, YELLOW);
    }
    if (getc == 4 && corr == 4)
    {
        setfillstyle(1, GREEN);
        floodfill(1421, 541, YELLOW);
    }
    if (corr == 1)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  10");
    }
    if (getc == 2 && corr == 1)
    {

        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  1");
        setfillstyle(1, RED);
        floodfill(1421, 541, YELLOW);
    }
    if (getc == 3 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 2");
        setfillstyle(1, RED);
        floodfill(1421, 541, YELLOW);
    }
    if (getc == 4 && corr == 1)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1421, 541, YELLOW);
    }

    if (corr == 2)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  20");
    }
    if (getc == 1 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(1421, 541, YELLOW);
    }
    if (getc == 3 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 3");
        setfillstyle(1, RED);
        floodfill(1421, 541, YELLOW);
    }
    if (getc == 4 && corr == 2)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1421, 541, YELLOW);
    }

    if (corr == 3)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 820, "C : 30");
    }
    if (getc == 1 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(250, 620, "A :  1");
        setfillstyle(1, RED);
        floodfill(1421, 541, YELLOW);
    }
    if (getc == 2 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 620, "B :  2");
        setfillstyle(1, RED);
        floodfill(1421, 541, YELLOW);
    }
    if (getc == 4 && corr == 3)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None ");
        setfillstyle(1, RED);
        floodfill(1421, 541, YELLOW);
    }
    if (corr == 4)
    {
        setbkcolor(GREEN);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        outtextxy(1100, 820, "D : None");
    }
    if (getc == 1 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,620,"A :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 2 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(1100,620,"B :  1");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }
    if (getc == 3 && corr == 4)
    {
        setbkcolor(RED);
        setcolor(BLACK);
        settextstyle(8, 0, 7);
        //outtextxy(250,820,"C : 2");
        setfillstyle(1, RED);
        floodfill(761, 541, YELLOW);
    }

    //fout<<endl<<chscore;
    //fout.close();

    getch();
rt10:
    if (rightans == 1)
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(10, 0, 10);
        setcolor(BLACK);
        setfillstyle(4, 4);
        bar(620, 395, 1220, 550);
        outtextxy(660, 410, "You Win");
        settextstyle(8, 0, 5);
        outtextxy(530, 1000, "Press Enter to view your Score");
        setbkcolor(BLACK);
        aa = 1;
        highscore();
    }

    else
    {
        setbkcolor(13);
        cleardevice();
        setcolor(BLACK);
        setbkcolor(13);
        settextstyle(8, 0, 8);
        setfillstyle(4, 4);
        bar(675, 390, 1200, 510);
        outtextxy(710, 410, "GAME OVER");
        settextstyle(8, 0, 5);
        outtextxy(550, 1000, "Press Enter to view your Score");
        getch();
        setbkcolor(BLACK);
        aa = 1;
        highscore();
    }
}

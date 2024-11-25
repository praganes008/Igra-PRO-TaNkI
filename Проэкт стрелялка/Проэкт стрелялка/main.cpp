#include "TXLib.h"

struct Tank
{
    HDC right;
    HDC left;
    HDC up;
    HDC image;
    int x;
    int y;
    int v;
    int h;
    int w;
    bool visible;

    void draw()
    {
        if(visible)
        {
            if(image == right || image == left)
            {
                txTransparentBlt(txDC(), x, y, w, h, image, 0, 0, TX_BLACK);
            }

            else if(image == up)
            {
                txTransparentBlt(txDC(), x, y, h, w, up, 0, 0, TX_BLACK);
            }
        }
    }



};

struct Bul
{
    HDC image;
    int x;
    int y;
    int v;
    int h;
    int w;
    bool visible;

    void draw()
    {
        if(visible)
        {
            txTransparentBlt(txDC(), x, y, w, h, image, 0, 0, TX_BLACK);
        }
    }

};

struct Button
{
    int x;
    int y;
    int w;
    int h;
    const char* text;

    void draw()
    {
       txSetColor(TX_RED, 5);
       txSetFillColor(TX_WHITE);
       txRectangle(x, y, x+w, y+h);
       txDrawText(x, y, x+w, y+h, text);

    }
};

struct SU_100
{

 HDC image;
 int x;
 int y;
 int v;
 int w;
 int h;
 bool visible;

void draw()
    {     //Win32::
        if(visible)
        {
            {
                txTransparentBlt(txDC(), x, y, w, h, image, 0, 0, TX_WHITE);
            }
        }
    }
};

struct SU_100_BUL
{
 HDC image;
 int x;
 int y;
 int v;
 int w;
 int h;
 bool visible;

    void draw()
    {
    if(visible)
        {
            txTransparentBlt(txDC(), x, y, w, h, image, 0, 0, TX_BLACK);
        }

    }


};

struct Button2
{
    int x;
    int y;
    int w;
    int h;
    const char* text;

    void draw()
    {
       txSetColor(TX_RED, 4);
       txSetFillColor(TX_WHITE);
       txRectangle(x, y, x+w, y+h);
       txDrawText(x, y, x+w, y+h, text);

    }
};

struct Button3
{
    int x;
    int y;
    int w;
    int h;
    const char* text;

    void draw()
    {
       txSetColor(TX_RED, 4);
       txSetFillColor(TX_WHITE);
       txRectangle(x, y, x+w, y+h);
       txDrawText(x, y, x+w, y+h, text);

    }
};


int main()
{
txCreateWindow (800, 600);

  string PAGE = "menu";

  int count_btn = 3;
  Button btn[count_btn];
    btn[0]  = {300, 100, 200, 50, "СТАРТ"};
    btn[1]  = {300, 170, 200, 50, "ПОМОЩЬ"};
    btn[2]  = {300, 240, 200, 50, "ВЫХОД"};

    int count_btn2 = 1;
    Button2 btn2[count_btn2];
    btn2[0]  = {300, 170, 200, 50, "ТЫ ПОБЕДИЛ!!!"};

    int count_btn3 = 1;
    Button3 btn3[count_btn3];
    btn3[0]  = {300, 170, 200, 50, "ЗАНОВО"};

        int popadanie = 0;
        char str[50];
    HDC tank2_right = txLoadImage("TankNPC/TankNPCright.bmp");
    HDC tank2_left = txLoadImage("TankNPC/TankNPCleft.bmp");
    HDC su100bul_image = txLoadImage("Bul/SU100bul.bmp");
    HDC su100_image = txLoadImage("TankNPC/SU_100image.bmp");
    HDC fon_fail = txLoadImage("fon/fon_fail.bmp");

     int count_100 = 5;
     SU_100 su100 [count_100];
     su100[0] = {su100_image, 0, -250, 3, 75, 125, true};
     su100[1] = {su100[0].image, 300, -300, 4, 75, 125, true};
     su100[2] = {su100[0].image, 450, -350, 5, 75, 125, true};
     su100[3] = {su100[0].image, 600, -400, 2, 75, 125, true};
     su100[4] = {su100[0].image, 150, -410, 4, 75, 125, true};

    int count_su100bul = 5;
    SU_100_BUL su100bul [count_su100bul];
    su100bul[0] = {su100bul_image, 800, 500, 0, 12, 22, false};
    su100bul[1] = {su100bul[0].image, 800, 500, 0, 12, 22, false};
    su100bul[2] = {su100bul[0].image, 800, 500, 0, 12, 22, false};
    su100bul[3] = {su100bul[0].image, 800, 500, 0, 12, 22, false};
    su100bul[4] = {su100bul[0].image, 800, 500, 0, 12, 22, false};

        int count_tank2 = 2;
        Tank tank2[count_tank2];
        tank2[0] = {tank2_right, tank2_left, tank2_right, tank2_right, 0, 90, 11, 100, 200, true};
        tank2[1] = {tank2[0].right, tank2[0].left, tank2[0].right, tank2[0].right, 500, 0, 10, 100, 200, true};


    HDC boom = txLoadImage("Tanks/boom.bmp");
    HDC fon_help = txLoadImage("fon/fon_help1.bmp");
    HDC fon1 = txLoadImage("fon/fon1.bmp");
    HDC E100fon = txLoadImage("fon/E100fon.bmp");
    Tank tank1 = {txLoadImage("Tanks/tank1Right.bmp"), txLoadImage("Tanks/tank1Left.bmp"), txLoadImage("Tanks/tank1Up.bmp"), tank1.right, 600, 500, 10, 100, 200, true};
    Bul bul = {txLoadImage("Bul/Bul.bmp"), 800, 550, 0, 20, 14, false};


    while(PAGE != "exit")
    {
       txSetFillColor(TX_BLACK);
       txClear();
       txBegin();
                                                    //немного читкодов

        //перейти в меню
        if(GetAsyncKeyState('Z'))
        {
         PAGE = "menu";
        }
        //перейти на 1й уровень
        if(GetAsyncKeyState('1'))
        {
         PAGE = "game1";
        }
        //перейти на 2й уровень
        if(GetAsyncKeyState('2'))
        {
         PAGE = "game2";;
        }
        //выйти из игры совсем
        if(GetAsyncKeyState('V'))
        {
         PAGE = "exit";
        }
        //попадание = 10
        if(GetAsyncKeyState('N'))
        {
         popadanie = 10;
        }
                                                   //уровни и меню
        //если "пэйдж" = заново{заново}
        if(PAGE == "zanovo")
        {
         txBitBlt(txDC(), 0, 0, 800, 600, fon_fail);

          for(int i=0; i<count_btn3; i++)
            {
                btn3[i].draw();
            }

            //кнопка "ЗАНОВО"
            if( txMouseButtons() == 1 &&
                txMouseX() > btn3[0].x && txMouseX() < btn3[0].x + btn3[0].w &&
                txMouseY() > btn3[0].y && txMouseY() < btn3[0].y + btn3[0].h )
            {
                PAGE = "game1";
                popadanie = 0;
            }
        }
         // если "пэйдж" = меню{меню}
        if(PAGE == "menu")
        {
            if(GetAsyncKeyState (VK_ESCAPE))
            {
                PAGE = "exit";
            }
            txBitBlt(txDC(), 0, 0, 800, 600, E100fon);

            for(int i=0; i<count_btn; i++)
            {
                btn[i].draw();
            }

            if( txMouseButtons() == 1 &&
                txMouseX() > btn[0].x && txMouseX() < btn[0].x + btn[0].w &&
                txMouseY() > btn[0].y && txMouseY() < btn[0].y + btn[0].h )
            {
                PAGE = "game1";
            }
            if( txMouseButtons() == 1 &&
                txMouseX() > btn[1].x && txMouseX() < btn[1].x + btn[1].w &&
                txMouseY() > btn[1].y && txMouseY() < btn[1].y + btn[1].h )
            {
                PAGE = "help";
            }
            if( txMouseButtons() == 1 &&
                txMouseX() > btn[2].x && txMouseX() < btn[2].x + btn[2].w &&
                txMouseY() > btn[2].y && txMouseY() < btn[2].y + btn[2].h )
            {
                PAGE = "exit";
            }
        }
         // если "пэйдж" = хэлп{помощь}
        if(PAGE == "help")
        {
            txBitBlt(txDC(), 0, 0, 800, 600, fon_help);

            txSetColor(TX_RED);
            txDrawText(0, 100, 800, 600, "Ну смотри,\n"
                                        "W=вверх, \n"
                                        "A=влево, \n"
                                        "D=вправо, \n"
                                        "ПРОБЕЛ=стрелять, \n"
                                        "стрелять можно только вверх.\n"
                                        "Когда уничтожил 5 танков на первом уровне,\n"
                                        "тогда вас перебросит на второй уровень.\n"
                                        "Что бы победить на втором уровне и пройти игру,\n"
                                        "вам нужно уничтожить 10 танков противника."
                                        "Все танки существуют в реальном мире,"
                                        "лишь танк игрока так и небыл реализован.");
            if(GetAsyncKeyState (VK_ESCAPE))
            {
                PAGE = "menu";
            }
        }
         // если "пэйдж" = гейм[уровень 1]
        if(PAGE == "game1")
        {
            txBitBlt(txDC(), 0, 0, 800, 600, fon1);
            bul.draw();
            tank1.draw();
            if(GetAsyncKeyState (VK_ESCAPE))
                {
                    PAGE = "menu";
                }

            for(int i=0; i<count_tank2; i++)
            {
                tank2[i].draw();
            }

            //ифы и управление для E 100
            if(GetAsyncKeyState('W'))
            {
                tank1.image = tank1.up;
                tank1.y = 400;
            }

            if(GetAsyncKeyState('A'))
            {
                tank1.image = tank1.left;
                tank1.x -= tank1.v;
                tank1.y = 500;
            }

            if(GetAsyncKeyState('D'))
            {
                tank1.image = tank1.right;
                tank1.x += tank1.v;
                tank1.y = 500;
            }

            if(tank1.x<0)
            {
                tank1.x=0;
            }

            if(tank1.x>800-tank1.w)
            {
                tank1.x=800-tank1.w;
            }

            if(tank1.y<0)
            {
                tank1.y=0;
            }

            if(tank1.y>600-tank1.h)
            {
                tank1.y=600-tank1.h;
            }
       //ифы для танка2 и снаряда
            for(int i=0; i<count_tank2; i++)
            {
                tank2[i].x += tank2[i].v;
                if(tank2[i].x>1100)
                {
                    tank2[i].v = -tank2[i].v;
                    tank2[i].image = tank2[i].left;
                }

                if(tank2[i].x<-300)
                {
                    tank2[i].v = -tank2[i].v;
                    tank2[i].image = tank2[i].right;
                }
            }

            if(GetAsyncKeyState(VK_SPACE) && tank1.image == tank1.up)
            {
                bul.x = tank1.x+tank1.h/2-bul.w/2;
                bul.y = tank1.y-bul.h;
                bul.visible = true;
                bul.v = 35;
            }

            if(bul.visible)
            {
                bul.y -= bul.v;
            }

            for(int i=0; i<count_tank2; i++)
            {
                if(bul.x>tank2[i].x && bul.x<tank2[i].x+tank2[i].w && bul.y>tank2[i].y && bul.y<tank2[i].y+tank2[i].h)
                {
                    bul.visible = false;
                    bul.x = tank1.x+tank1.h/2-bul.w/2;
                    bul.y = tank1.y-bul.h;
                    tank2[i].visible = false;
                    tank2[i].x = 1000;
                    txSleep(50);
                    popadanie += 1;
                    tank2[i].visible = true;
                }
            }

            if(popadanie == 5)
            {
            popadanie = 0;
            PAGE = "game2";

            }


            sprintf(str, "Число попаданий - %d", popadanie);
            txTextOut(0, 400, str);
        }
         //если "пейдж" = гейм2{уровень 2]
        if(PAGE == "game2")
        {
            txBitBlt(txDC(), 0, 0, 800, 600, fon1);
            tank1.draw();
            bul.draw();

        for(int i=0; i<count_100; i++)
        {
            if(GetAsyncKeyState (VK_ESCAPE))
                {
                    PAGE = "game1";
                    bul.visible = false;
                    bul.x = tank1.x+tank1.h/2-bul.w/2;
                    bul.y = tank1.y-bul.h;
                    su100[i].visible = false;
                    su100[i].y = -300;
                    txSleep(50);
                    su100[i].visible = true;
                    popadanie = 0;
                }

            if(PAGE == "game1")
            {
            su100[i].y = -300;
            su100bul[i].x = su100[i].x+su100[i].w/2;
            su100bul[i].y = su100[i].y+su100[i].h;
            su100bul[i].visible = true;

            }
        }


            //ифы и управление для E 100
            if(GetAsyncKeyState('W'))
            {
                tank1.image = tank1.up;
                tank1.y = 400;
            }

            if(GetAsyncKeyState('A'))
            {
                tank1.image = tank1.left;
                tank1.x -= tank1.v;
                tank1.y = 500;
            }

            if(GetAsyncKeyState('D'))
            {
                tank1.image = tank1.right;
                tank1.x += tank1.v;
                tank1.y = 500;
            }

            if(tank1.x<0)
            {
                tank1.x=0;
            }

            if(tank1.x>800-tank1.w)
            {
                tank1.x=800-tank1.w;
            }

            if(tank1.y<0)
            {
                tank1.y=0;
            }

            if(tank1.y>600-tank1.h)
            {
            tank1.y=600-tank1.h;
            }

            if(GetAsyncKeyState(VK_SPACE) && tank1.image == tank1.up)
            {
                bul.x = tank1.x+tank1.h/2-bul.w/2;
                bul.y = tank1.y-bul.h;
                bul.visible = true;
                bul.v = 35;
            }

            if(bul.visible)
            {
                bul.y -= bul.v;
            }

            //ифы для су 100
            for(int i=0; i<count_100; i++)
            {
                //рисуется
                su100[i].draw();
                su100bul[i].draw();
                su100[i].y += su100[i].v;

                //если в него попали
                if(bul.x>su100[i].x && bul.x<su100[i].x+su100[i].w && bul.y>su100[i].y && bul.y<su100[i].y+su100[i].h)
                {
                    bul.visible = false;
                    bul.x = tank1.x+tank1.h/2-bul.w/2;
                    bul.y = tank1.y-bul.h;
                    su100[i].visible = false;
                    su100[i].y = -300;
                    txSleep(50);
                    popadanie += 1;
                    su100[i].visible = true;
                }

                //что бы он остановился и поехал заново
                if(su100[i].y<-130)
                {
                 su100[i].v = 4;

                }

                //ифы для снаряда
                for(int i=0; i<count_su100bul; i++)
                {
                    //видимость и скорость снаряда
                    if(su100[i].y>60 && !su100bul[i].visible)
                    {
                        su100[i].v = 0;
                        su100bul[i].x = su100[i].x+su100[i].w/2;
                        su100bul[i].y = su100[i].y+su100[i].h;
                        su100bul[i].visible = true;
                        su100bul[i].v = 5;
                    }

                    if(su100bul[i].visible)
                    {
                        su100bul[i].y += su100bul[i].v;
                    }
                }
              }

            //если су 100 попал + что бы снаряд вернулся
            for(int i=0; i<count_su100bul; i++)
                {
            //если су 100 попал в е100
            if(su100bul[i].x>tank1.x && su100bul[i].x<tank1.x+tank1.w && su100bul[i].y>tank1.y && su100bul[i].y<tank1.y+tank1.h)
            {
             PAGE = "zanovo";
            }

            //что бы снаряд вернулся
            if(su100bul[i].y>1150)
            {
                su100[i].v = 0;
                su100bul[i].x = su100[i].x+su100[i].w/2;
                su100bul[i].y = su100[i].y+su100[i].h;
                su100bul[i].visible = false;

            }

                }

            //если попадание = 10.{ты победил}
            if(popadanie == 10)
            {
            txBitBlt(txDC(), 0, 0, 800, 600, E100fon);

            for(int i=0; i<count_btn2; i++)
            {
                btn2[i].draw();
            }

            //кнопка "ПОБЕДА"
            if( txMouseButtons() == 1 &&
                txMouseX() > btn2[0].x && txMouseX() < btn2[0].x + btn2[0].w &&
                txMouseY() > btn2[0].y && txMouseY() < btn2[0].y + btn2[0].h )
            {
                PAGE = "menu";
                popadanie = 0;
            }

            }
            sprintf(str, "Число попаданий - %d", popadanie);
            txTextOut(0, 400, str);
        }

        txEnd();
        txSleep(15);
            }

    txTextCursor (false);
    txDisableAutoPause();
    return 0;
    }


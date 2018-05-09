#include "Inputs.h"
#include <Sounds.h>
float mx,my;
Inputs::Inputs()
{
    Wwidth = GetSystemMetrics(SM_CXSCREEN);
    Wheight= GetSystemMetrics(SM_CYSCREEN);
    credit = 0;
    jump=1;
    kunaisound=1;
}

Inputs::~Inputs()
{
    //dtor
}
void Inputs::KeyEnv(Parallax *Bk1,float speed)
{
    switch (wParam)
    {
        case VK_LEFT:
            break;
        case VK_RIGHT:
                Bk1->Direction = 1;
                Bk1->Xmin += speed;
                Bk1->Xmax += speed;
            break;
        case VK_UP:
                Bk1->Xmin += speed;
                Bk1->Xmax += speed;
            break;
        case VK_DOWN:
                Bk1->Direction = 10;
            break;
        case VK_SPACE:
                Bk1->Xmin += speed;
                Bk1->Xmax += speed;
            break;
    }
}
void Inputs::KeyPressed(Parallax *parallax){
    switch (wParam)
    {
    case VK_RETURN:
        if(helpflag == 0 || help == 1 && newGame1==1 && newGame2==1 && newGame3==1 && endGame==1){
             menu = 0;
             credit = 1;
        }
        break;
    case 0x4E:
            if(helpflag == 1 && newGame1==1 && newGame2==1 && newGame3==1){
                bgGame1 = 0;
                newGame1 = 0;
            }
        break;
    case 0x48:
        if(newGame1==1 && newGame2==1 && newGame3==1)
            help = 0;
        break;
    case 0x51:
            if(helpflag == 1 && newGame1==1 && newGame2==1 && newGame3==1){
                quit = 0;
            }
        break;

    }
}
void Inputs::KeyPressed(Player *Player)
{ Sounds *snds;
    switch (wParam)
    {
        case VK_LEFT:
            Player->actionTrigger1 = 2;
            Player->Player_x -= 0.02;
            break;
        case VK_RIGHT:
            Player->actionTrigger = 1;
            Player->actionTrigger1 = 1;
            Player->Player_x += 0.02;
            break;
        case VK_UP:
            Player->actionTrigger = 3;

            break;
        case VK_DOWN:
            break;
        case VK_HOME:
            break;
        case VK_END:
            break;
        case VK_SPACE:
            Player->actionTrigger = 4;
            Player->actionTrigger1 = 4;
            Player->actionTrigger2 = 4;
           break;
    }
}
void Inputs::KeyUp(Player *Player)
{
    switch (wParam)
    {
        case VK_LEFT:
            break;
        case VK_RIGHT:
            Player->actionTrigger = 1;
            break;
        case VK_UP:
            jump=1;
            break;
        case VK_DOWN:
            Player->actionTrigger = 10;
            Player->actionTrigger1 = 10;
            break;
        case VK_HOME:
            break;
        case VK_END:
            break;
        case VK_SPACE:
            kunaisound=1;
           break;
    }
}
void Inputs::MouseEventDown(Parallax *Prlx, double x,double y)
{
    mx=(float)(x-Wwidth/2)/450*(Wwidth/Wheight);   // for x-coordinate of mouse click
    my=(float)(Wheight/2-y)/400*(Wwidth/Wheight);   // for y-coordinate of mouse click
    switch (wParam)
    {
        case MK_LBUTTON:
            if(mx>=0.71&&mx<=2.11&&my>=0.42&&my<=0.69 && menuflag == 0)
            {
                bgGame1 = 0;
                newGame1=0;
            }
            if(mx>=0.69&&mx<=2.12&&my>=0.03&&my<=0.29 && menuflag == 0 )
            {
                help=0;
            }
            if(mx>=0.70 && mx<=2.12 && my>=-0.37 && my<=-0.11 && menuflag == 0)
            {
                quit=0;
            }
        break;
        case MK_RBUTTON:
        break;
        case MK_MBUTTON:
        break;
        default:
        break;
    }
}

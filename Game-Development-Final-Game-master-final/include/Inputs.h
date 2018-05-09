#ifndef INPUTS_H
#define INPUTS_H
#include <windows.h>
#include <Parallax.h>
#include <Player.h>
#include <stdlib.h>
class Inputs
{
    public:
        Inputs();
        virtual ~Inputs();

        void KeyPressed(Player *);
        void KeyEnv(Parallax *,float);
        void KeyUp(Player *);
        void KeyPressed(Parallax *);
        void MouseEventDown(Parallax *,double ,double);

        int jump,kunaisound;
        int credit = 0, story = 1, menu = 1, menuflag = 1, help = 1, helpflag =1, newGame1 = 1, bgGame1 = 1, newGame2 = 1, bgGame2 = 1, newGame3 = 1, bgGame3 = 1, pause = 1, quit = 1, endGame = 1;
        float Wwidth, Wheight;
        WPARAM wParam;
    protected:

    private:
};

#endif // INPUTS_H

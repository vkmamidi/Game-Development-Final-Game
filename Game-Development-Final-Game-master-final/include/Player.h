#ifndef PLAYER_H
#define PLAYER_H
#include <TextureLoader.h>
#include <Timer.h>
#include <stdlib.h>
#define GRAVITY 0.02
class Player
{
    public:
        Player();
        virtual ~Player();

        float Player_size[3]={1.5,1.5,1.5};
        float Player_size_Idle[3]={0.50,0.50,0.7};
        float Player_x;
        float Player_y;
        float Vertices[4][3] ={ {0.0, 0.0, -1.5},{1.5, 0.0, -1.5},{1.5,1.5, -1.5},{0.0, 1.5, -1.5}};
        int delay = 0;
        int actionTrigger = 10;
        int actionTrigger1 = 10;
        int actionTrigger2 = 10;
        float dy;

        void drawPlayer();
        void playerInit();

        void Action(int);
        void Action1(int);
        void Action3(int);

    protected:

    private:
};

#endif // PLAYER_H

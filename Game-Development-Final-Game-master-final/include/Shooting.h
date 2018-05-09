#ifndef SHOOTING_H
#define SHOOTING_H


class Shooting
{
    public:
        Shooting();
        virtual ~Shooting();

        float Player_size[3]={0.3,0.3,0.3};
        float Player_size_Idle[3]={0.50,0.50,0.7};
        float Player_x;
        float Player_y;
        float Vertices[4][3] ={ {0.0, 0.0, -1.5},{0.3, 0.0, -1.5},{0.3,0.3, -1.5},{0.0, 0.3, -1.5}};
        int delay = 0;
        int actionTrigger = 10;
        float dy;
        void drawPlayer();
        void playerInit();
        void Action();
    protected:

    private:
};

#endif // SHOOTING_H

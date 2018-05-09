#ifndef VILLAIN_H
#define VILLAIN_H


class Villain
{
    public:
        Villain();
        virtual ~Villain();

        float Player_size[3]={3.0,3.0,1.5};
        float Player_size_Idle[3]={0.50,0.50,0.7};
        float Player_x;
        float Player_y;
        float Vertices[4][3] ={ {0.0, 0.0, -1.5},{3.0, 0.0, -1.5},{3.0,3.0, -1.5},{0.0, 3.0, -1.5}};
        int delay = 0;
        int actionTrigger = 10;

        void drawPlayer();
        void playerInit();

        void Action(int);
    protected:

    private:
};

#endif // VILLAIN_H

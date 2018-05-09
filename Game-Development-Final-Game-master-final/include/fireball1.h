#ifndef FIREBALL1_H
#define FIREBALL1_H


class fireBall1
{
    public:
        fireBall1();
        virtual ~fireBall1();

        float Player_size[3]={0.8,0.8,0.8};
        float Player_x;
        float Player_y;
        float Vertices[4][3] ={ {0.0, 0.0, -1.5},{0.8, 0.0, -1.5},{0.8,0.8, -1.5},{0.0, 0.8, -1.5}};
        void drawPlayer();
        void playerInit();
        void Action();

    protected:

    private:
};

#endif // FIREBALL1_H

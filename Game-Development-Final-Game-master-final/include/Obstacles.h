#ifndef OBSTACLES_H
#define OBSTACLES_H


class Obstacles
{
    public:
        Obstacles();
        virtual ~Obstacles();

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

#endif // OBSTACLES_H

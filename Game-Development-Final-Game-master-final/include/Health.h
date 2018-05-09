#ifndef HEALTH_H
#define HEALTH_H


class Health
{
    public:
        Health();
        virtual ~Health();

        float Player_size[3]={0.5,0.5,1.2};
        float Player_x = -2.6;
        float Player_y = 0.9;
        float Player_x1 = 1.8;
        float Player_y1 = 0.9;
        float Vertices[4][3] ={ {0.0, 0.0, -1.5},{1.5, 0.0, -1.5},{1.5,1.2, -1.5},{0.0, 1.2, -1.5}};
        void drawPlayer();
        void playerInit();
        void Action(int);
        void Action1(int);

    protected:

    private:
};

#endif // HEALTH_H

#ifndef SOUNDS_H
#define SOUNDS_H
#include <Sounds/irrKlang.h>

#include <stdlib.h>
#include <iostream>

#pragma comment(lib, "irrKlang.lib")
using namespace irrklang;
using namespace std;

class Sounds
{
    public:
        Sounds();
        virtual ~Sounds();

        int soundinit();
        void playmusic(char *);
        void PlaySound(char *);
        void pausemusic(char *);
        void running();
        void stop();
        void stop1();
        void kunai();
        void lvl2();
        void stop2();
        void stop3();
        void stop4();
        void lvl1();
        void menu();
        void stop5();
        void lvlcomplete();
        void stop6();
        void lvlcomplete2();
        void thunder();
        void stop7();
    protected:

    private:
};

#endif // SOUNDS_H

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

    protected:

    private:
};

#endif // SOUNDS_H

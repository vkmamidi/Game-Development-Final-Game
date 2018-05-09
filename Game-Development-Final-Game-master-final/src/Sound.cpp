#include "Sounds.h"


ISoundEngine* engine = createIrrKlangDevice();


Sounds::Sounds()
{
    //ctor
}

Sounds::~Sounds()
{
    //dtor
}

int Sounds::soundinit()
{
    if(!engine)
    {
        cout<<"could not startup engine";
        return 0;
    }
    return 1;
}


void Sounds::playmusic(char * File)
{
    engine->play2D(File,true);
}

void Sounds::PlaySound(char * File)
{
    engine->play2D(File,false,false);
}

void Sounds::pausemusic(char * File)
{
    engine->play2D(File,false);
}

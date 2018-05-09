#include "Sounds.h"
#include <Timer.h>


ISoundEngine* engine = createIrrKlangDevice();
ISoundSource* running2 = engine->addSoundSourceFromFile("finalboss1.wav");
ISoundSource* running3 = engine->addSoundSourceFromFile("kunai.wav");
ISoundSource* running4 = engine->addSoundSourceFromFile("lvl2 background.wav");
ISoundSource* running5 = engine->addSoundSourceFromFile("menu.wav");
ISoundSource* running6 = engine->addSoundSourceFromFile("lvl1 background.wav");
ISoundSource* running7 = engine->addSoundSourceFromFile("levelcomplete.wav");
ISoundSource* running8 = engine->addSoundSourceFromFile("levelcomplete1.wav");
ISoundSource* running9 = engine->addSoundSourceFromFile("thunder.wav");





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
    Timer *Time;
    Time->Start();
    if(!engine)
    {
        cout<<"could not startup engine";
        return 0;
    }
    return 1;
}
void Sounds::stop6()
{
    engine->removeSoundSource(running8);
}

void Sounds::stop7()
{
    engine->removeSoundSource(running9);
}


void Sounds::stop5()
{
    engine->removeSoundSource(running7);
}

void Sounds::stop1()
{
    engine->removeSoundSource(running3);
}
void Sounds::stop2()
{
    engine->removeSoundSource(running4);
}
void Sounds::stop()
{
    engine->removeSoundSource(running2);
}
void Sounds::stop3()
{
    engine->removeSoundSource(running5);
}
void Sounds::stop4()
{
    engine->removeSoundSource(running6);
}


void Sounds::thunder()
{
    running9->setDefaultVolume(0.5f);
    engine->play2D(running9,true);
}

void Sounds::menu()
{
    running4->setDefaultVolume(0.5f);
    engine->play2D(running5,true);
}
void Sounds::lvlcomplete()
{
    //running4->setDefaultVolume(0.5f);
    engine->play2D(running7,true);
}
void Sounds::lvlcomplete2()
{
    //running4->setDefaultVolume(0.5f);
    engine->play2D(running8,true);
}
void Sounds::lvl1()
{
    running6->setDefaultVolume(0.1f);
    engine->play2D(running6,true);
}

void Sounds::lvl2()
{
    running4->setDefaultVolume(0.5f);
    engine->play2D(running4,true);
}
void Sounds::kunai()
{
    //running3->setDefaultVolume(0.1f);
    engine->play2D(running3,false);
}
void Sounds::running()
{
    running2->setDefaultVolume(0.5f);
    engine->play2D(running2,true);

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
    engine->play2D(File,false,false);
}

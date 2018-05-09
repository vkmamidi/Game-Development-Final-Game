#include "Villain.h"
#include <TextureLoader.h>
#include <Timer.h>

Timer *T1 = new Timer();

TextureLoader stndTtexv[10];
TextureLoader shootflipTtex[10];
Villain::Villain()
{
    //ctor
}

Villain::~Villain()
{
    //dtor
}


void Villain::playerInit()
{
    T1->Start();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    stndTtexv[0].BindTexture("images/ninja/png/Idleflip__000.png");
    stndTtexv[1].BindTexture("images/ninja/png/Idleflip__001.png");
    stndTtexv[2].BindTexture("images/ninja/png/Idleflip__002.png");
    stndTtexv[3].BindTexture("images/ninja/png/Idleflip__003.png");
    stndTtexv[4].BindTexture("images/ninja/png/Idleflip__004.png");
    stndTtexv[5].BindTexture("images/ninja/png/Idleflip__005.png");
    stndTtexv[6].BindTexture("images/ninja/png/Idleflip__006.png");
    stndTtexv[7].BindTexture("images/ninja/png/Idleflip__007.png");
    stndTtexv[8].BindTexture("images/ninja/png/Idleflip__008.png");
    stndTtexv[9].BindTexture("images/ninja/png/Idleflip__009.png");

    shootflipTtex[0].BindTexture("images/ninja/png/Throwflip__000.png");
    shootflipTtex[1].BindTexture("images/ninja/png/Throwflip__001.png");
    shootflipTtex[2].BindTexture("images/ninja/png/Throwflip__002.png");
    shootflipTtex[3].BindTexture("images/ninja/png/Throwflip__003.png");
    shootflipTtex[4].BindTexture("images/ninja/png/Throwflip__004.png");
    shootflipTtex[5].BindTexture("images/ninja/png/Throwflip__005.png");
    shootflipTtex[6].BindTexture("images/ninja/png/Throwflip__006.png");
    shootflipTtex[7].BindTexture("images/ninja/png/Throwflip__007.png");
    shootflipTtex[8].BindTexture("images/ninja/png/Throwflip__008.png");
    shootflipTtex[9].BindTexture("images/ninja/png/Throwflip__009.png");

}

void Villain::Action(int action)
{
     switch(action)
    {
        case 10:
            glPushMatrix();
                Player_size[0] = Player_size_Idle[0];
                Player_size[1] = Player_size_Idle[1];
                Player_x = 1.2;
                Player_y = -1.5;

                if(T1->GetTicks()>50)
                {
                    delay++;
                    T1->Reset();
                }
                delay = delay%10;
                stndTtexv[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
        break;
        case 1:
            glPushMatrix();
                Player_size[0] = Player_size_Idle[0];
                Player_size[1] = Player_size_Idle[1];
                Player_x = 1.2;
                Player_y = -1.5;

                if(T1->GetTicks()>50)
                {
                    delay++;
                    T1->Reset();
                }
                delay = delay%10;
                shootflipTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
        break;
    }
}

void Villain::drawPlayer()
{
    glScaled(Player_size[0],Player_size[1],Player_size[2]);
    glBegin(GL_QUADS);
          glTexCoord2f(0.0f, 1.0f);
          glVertex3f(Vertices[0][0],Vertices[0][1],Vertices[0][2]);
          glTexCoord2f(1.0f, 1.0f);
          glVertex3f(Vertices[1][0],Vertices[1][1],Vertices[1][2]);
          glTexCoord2f(1.0f, 0.0f);
          glVertex3f(Vertices[2][0],Vertices[2][1],Vertices[2][2]);
          glTexCoord2f(0.0f, 0.0f);
          glVertex3f(Vertices[3][0],Vertices[3][1],Vertices[3][2]);
      glEnd();
}


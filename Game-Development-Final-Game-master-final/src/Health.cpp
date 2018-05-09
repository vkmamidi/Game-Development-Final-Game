#include "Health.h"
#include <TextureLoader.h>
#include <stdlib.h>

TextureLoader h[4];

Health::Health()
{
    //ctor
}

Health::~Health()
{
    //dtor
}

void Health::playerInit()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    h[3].BindTexture("images/h3.jpg");
    h[2].BindTexture("images/h2.jpg");
    h[1].BindTexture("images/h1.jpg");
    h[0].BindTexture("images/h0.jpg");
}

void Health::Action(int action)
{
    switch(action){
    case 3:
        glPushMatrix();
            h[0].Binder();
            glTranslated(Player_x,Player_y,-2.0);
            drawPlayer();
        glPopMatrix();
        break;
    case 2:
        glPushMatrix();
            h[1].Binder();
            glTranslated(Player_x,Player_y,-2.0);
            drawPlayer();
        glPopMatrix();
        break;
    case 1:
        glPushMatrix();
            h[2].Binder();
            glTranslated(Player_x,Player_y,-2.0);
            drawPlayer();
        glPopMatrix();
        break;
    case 0:
        glPushMatrix();
            h[3].Binder();
            glTranslated(Player_x,Player_y,-2.0);
            drawPlayer();
        glPopMatrix();
        break;

    }
}
void Health::Action1(int action)
{
    switch(action){
    case 3:
        glPushMatrix();
            h[0].Binder();
            glTranslated(Player_x1,Player_y1,-2.0);
            drawPlayer();
        glPopMatrix();
        break;
    case 2:
        glPushMatrix();
            h[1].Binder();
            glTranslated(Player_x1,Player_y1,-2.0);
            drawPlayer();
        glPopMatrix();
        break;
    case 1:
        glPushMatrix();
            h[2].Binder();
            glTranslated(Player_x1,Player_y1,-2.0);
            drawPlayer();
        glPopMatrix();
        break;
    case 0:
        glPushMatrix();
            h[3].Binder();
            glTranslated(Player_x1,Player_y1,-2.0);
            drawPlayer();
        glPopMatrix();
        break;

    }
}

void Health::drawPlayer()
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


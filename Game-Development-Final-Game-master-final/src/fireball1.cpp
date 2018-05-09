#include "fireBall1.h"
#include <TextureLoader.h>

TextureLoader fire_1;
fireBall1::fireBall1()
{
    //ctor
}

fireBall1::~fireBall1()
{
    //dtor
}

void fireBall1::playerInit()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    fire_1.BindTexture("images/fire1.png");
}

void fireBall1::Action()
{
    glPushMatrix();
        fire_1.Binder();
        glTranslated(Player_x,Player_y,-2.0);
        drawPlayer();
    glPopMatrix();
}


void fireBall1::drawPlayer()
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

#include "Obstacles.h"
#include <TextureLoader.h>
#include <stdlib.h>

TextureLoader obstacle;

Obstacles::Obstacles()
{
    //ctor
}

Obstacles::~Obstacles()
{
    //dtor
}

void Obstacles::playerInit()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    obstacle.BindTexture("images/5.png");
}

void Obstacles::Action()
{
    glPushMatrix();
        obstacle.Binder();
        glTranslated(Player_x,Player_y,-2.0);
        drawPlayer();
    glPopMatrix();
}

void Obstacles::drawPlayer()
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

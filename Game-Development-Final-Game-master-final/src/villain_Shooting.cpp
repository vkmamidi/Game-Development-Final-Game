#include "villain_Shooting.h"
#include <TextureLoader.h>
TextureLoader kunaiv;
villain_Shooting::villain_Shooting()
{
    //ctor
}

villain_Shooting::~villain_Shooting()
{
    //dtor
}

void villain_Shooting::playerInit()
{
    Player_y = -0.8;
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    kunaiv.BindTexture("images/ninja/png/S.png");
}

void villain_Shooting::Action()
{
    glPushMatrix();
        Player_size[0] = Player_size_Idle[0];
        Player_size[1] = Player_size_Idle[1];
        kunaiv.Binder();
        glTranslated(Player_x,Player_y,-2.0);
        drawPlayer();
    glPopMatrix();
}

void villain_Shooting::drawPlayer()
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

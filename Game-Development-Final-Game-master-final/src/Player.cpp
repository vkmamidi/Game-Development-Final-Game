#include "Player.h"
#include <Shooting.h>

Shooting *shoot = new Shooting();

Timer *T = new Timer();

TextureLoader stndTtex[10];
TextureLoader runTtex[10],runflipTtex[10];
TextureLoader slideTtex[10];
TextureLoader jumpTtex[10];
TextureLoader shootTtex[10];
TextureLoader DeadTtex[10];

Player::Player()
{
    Player_x = -1.2;
    Player_y = -1.5;
}

Player::~Player()
{
    //dtor
    free(T);
}
void Player::playerInit()
{
    T->Start();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    stndTtex[0].BindTexture("images/ninja/png/Idle__000.png");
    stndTtex[1].BindTexture("images/ninja/png/Idle__001.png");
    stndTtex[2].BindTexture("images/ninja/png/Idle__002.png");
    stndTtex[3].BindTexture("images/ninja/png/Idle__003.png");
    stndTtex[4].BindTexture("images/ninja/png/Idle__004.png");
    stndTtex[5].BindTexture("images/ninja/png/Idle__005.png");
    stndTtex[6].BindTexture("images/ninja/png/Idle__006.png");
    stndTtex[7].BindTexture("images/ninja/png/Idle__007.png");
    stndTtex[8].BindTexture("images/ninja/png/Idle__008.png");
    stndTtex[9].BindTexture("images/ninja/png/Idle__009.png");

    jumpTtex[0].BindTexture("images/ninja/png/Jump__000.png");
    jumpTtex[1].BindTexture("images/ninja/png/Jump__001.png");
    jumpTtex[2].BindTexture("images/ninja/png/Jump__002.png");
    jumpTtex[3].BindTexture("images/ninja/png/Jump__003.png");
    jumpTtex[4].BindTexture("images/ninja/png/Jump__004.png");
    jumpTtex[5].BindTexture("images/ninja/png/Jump__005.png");
    jumpTtex[6].BindTexture("images/ninja/png/Jump__006.png");
    jumpTtex[7].BindTexture("images/ninja/png/Jump__007.png");
    jumpTtex[8].BindTexture("images/ninja/png/Jump__008.png");
    jumpTtex[9].BindTexture("images/ninja/png/Jump__009.png");

    runTtex[0].BindTexture("images/ninja/png/Run__000.png");
    runTtex[1].BindTexture("images/ninja/png/Run__001.png");
    runTtex[2].BindTexture("images/ninja/png/Run__002.png");
    runTtex[3].BindTexture("images/ninja/png/Run__003.png");
    runTtex[4].BindTexture("images/ninja/png/Run__004.png");
    runTtex[5].BindTexture("images/ninja/png/Run__005.png");
    runTtex[6].BindTexture("images/ninja/png/Run__006.png");
    runTtex[7].BindTexture("images/ninja/png/Run__007.png");
    runTtex[8].BindTexture("images/ninja/png/Run__008.png");
    runTtex[9].BindTexture("images/ninja/png/Run__009.png");

    shootTtex[0].BindTexture("images/ninja/png/Throw__000.png");
    shootTtex[1].BindTexture("images/ninja/png/Throw__001.png");
    shootTtex[2].BindTexture("images/ninja/png/Throw__002.png");
    shootTtex[3].BindTexture("images/ninja/png/Throw__003.png");
    shootTtex[4].BindTexture("images/ninja/png/Throw__004.png");
    shootTtex[5].BindTexture("images/ninja/png/Throw__005.png");
    shootTtex[6].BindTexture("images/ninja/png/Throw__006.png");
    shootTtex[7].BindTexture("images/ninja/png/Throw__007.png");
    shootTtex[8].BindTexture("images/ninja/png/Throw__008.png");
    shootTtex[9].BindTexture("images/ninja/png/Throw__009.png");

    DeadTtex[0].BindTexture("images/ninja/png/Dead__000.png");
    DeadTtex[1].BindTexture("images/ninja/png/Dead__001.png");
    DeadTtex[2].BindTexture("images/ninja/png/Dead__002.png");
    DeadTtex[3].BindTexture("images/ninja/png/Dead__003.png");
    DeadTtex[4].BindTexture("images/ninja/png/Dead__004.png");
    DeadTtex[5].BindTexture("images/ninja/png/Dead__005.png");
    DeadTtex[6].BindTexture("images/ninja/png/Dead__006.png");
    DeadTtex[7].BindTexture("images/ninja/png/Dead__007.png");
    DeadTtex[8].BindTexture("images/ninja/png/Dead__008.png");
    DeadTtex[9].BindTexture("images/ninja/png/Dead__009.png");

    runflipTtex[0].BindTexture("images/ninja/png/Runflip__000.png");
    runflipTtex[1].BindTexture("images/ninja/png/Runflip__001.png");
    runflipTtex[2].BindTexture("images/ninja/png/Runflip__002.png");
    runflipTtex[3].BindTexture("images/ninja/png/Runflip__003.png");
    runflipTtex[4].BindTexture("images/ninja/png/Runflip__004.png");
    runflipTtex[5].BindTexture("images/ninja/png/Runflip__005.png");
    runflipTtex[6].BindTexture("images/ninja/png/Runflip__006.png");
    runflipTtex[7].BindTexture("images/ninja/png/Runflip__007.png");
    runflipTtex[8].BindTexture("images/ninja/png/Runflip__008.png");
    runflipTtex[9].BindTexture("images/ninja/png/Runflip__009.png");

}

void Player::Action(int action)
{
    switch(action)
    {
        case 10:
            glPushMatrix();
                Player_size[0] = Player_size_Idle[0];
                Player_size[1] = Player_size_Idle[1];
                Player_x = -1.2;
                Player_y = -1.5;

                if(T->GetTicks()>50)
                {
                    delay++;
                    T->Reset();
                }
                delay = delay%10;
                stndTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
            break;
        case 1:
            glPushMatrix();

                Player_x = -1.2;
                Player_y = -1.5;

                if(T->GetTicks()>50)
                {
                    delay++;
                    T->Reset();
                }
                delay = delay%10;
                runTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
            break;
         case 3:
            glPushMatrix();
                Player_x = -1.2;
                Player_y = -1.5;
                if(T->GetTicks() >= 100)
                {
                    delay++;
                    T->Reset();
                }
                delay  = delay %10;
                if(delay <9){
                    jumpTtex[delay].Binder();
                    Player_y = Player_y+ (delay/10) +0.4 + 0.5;
                    glTranslated(Player_x,Player_y+GRAVITY,-2.0);
                    drawPlayer();
                }else if(delay >= 9 && delay <= 9){
                    jumpTtex[delay].Binder();
               //     Player_y = Player_y - (delay/10);
                    glTranslated(Player_x,Player_y-GRAVITY,-2.0);
                    drawPlayer();
                }
                Player_x = -1.2;
                Player_y = -1.5;
                glTranslated(Player_x,Player_y,-2.0);
            glPopMatrix();
            break;
        case 4:
            glPushMatrix();
                Player_size[0] = Player_size_Idle[0];
                Player_size[1] = Player_size_Idle[1];
                Player_x = -1.2;
                Player_y = -1.5;

                if(T->GetTicks()>50)
                {
                    delay++;
                    T->Reset();
                }
                delay = delay%10;
                shootTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
            break;
        case 20:
            glPushMatrix();
                Player_size[0] = Player_size_Idle[0];
                Player_size[1] = Player_size_Idle[1];
                Player_x = -1.2;
                Player_y = -1.5;

                if(T->GetTicks()>50)
                {
                    delay++;
                    T->Reset();
                }
                delay = delay%10;
                DeadTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
            break;
    }
}

void Player::Action1(int action)
{
    switch(action)
    {
        case 10:
            glPushMatrix();
                Player_size[0] = Player_size_Idle[0];
                Player_size[1] = Player_size_Idle[1];
                if(T->GetTicks()>50)
                {
                    delay++;
                    T->Reset();
                }
                delay = delay%10;
                stndTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
            break;
        case 1:
            glPushMatrix();
                if(T->GetTicks()>50)
                {
                    delay++;
                    T->Reset();
                }
                delay = delay%10;
                runTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
            break;
        case 2:
            glPushMatrix();
                if(T->GetTicks()>50)
                {
                    delay++;
                    T->Reset();
                }
                delay = delay%10;
                runflipTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
            break;
        case 20:
            glPushMatrix();
                Player_size[0] = Player_size_Idle[0];
                Player_size[1] = Player_size_Idle[1];
                if(T->GetTicks()>50)
                {
                    delay++;
                    T->Reset();
                }
                delay = delay%10;
                DeadTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
            break;
    }
}



void Player::Action3(int action){
    switch(action)
    {
        case 10:
            glPushMatrix();
                Player_size[0] = Player_size_Idle[0];
                Player_size[1] = Player_size_Idle[1];
                Player_x = -3.0;
                Player_y = -1.5;

                if(T->GetTicks()>50)
                {
                    delay++;
                    T->Reset();
                }
                delay = delay%10;
                stndTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
        break;
        case 4:
            glPushMatrix();
                Player_size[0] = Player_size_Idle[0];
                Player_size[1] = Player_size_Idle[1];
                Player_x = -3.0;
                Player_y = -1.5;

                if(T->GetTicks()>50)
                {
                    delay++;
                    T->Reset();
                }
                delay = delay%10;
                shootTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
        break;
        case 20:
            glPushMatrix();
                Player_size[0] = Player_size_Idle[0];
                Player_size[1] = Player_size_Idle[1];
                Player_x = -3.0;
                Player_y = -1.5;

                if(T->GetTicks()>50)
                {
                    delay++;
                    T->Reset();
                }
                delay = delay%10;
                DeadTtex[delay].Binder();
                glTranslated(Player_x,Player_y,-2.0);
                drawPlayer();
            glPopMatrix();
        break;
    }
}



void Player::drawPlayer()
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

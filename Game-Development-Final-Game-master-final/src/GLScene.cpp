#include <loadShaders.h>
#include <particle.h>
#include "GLScene.h"
#include <Parallax.h>
#include <Player.h>
#include <GLLight.h>
#include <Inputs.h>
#include <Shooting.h>
#include <Obstacles.h>
#include <Health.h>
#include <fireBall1.h>
#include <fireBall2.h>
#include <Villain.h>
#include <villain_Shooting.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <string>
#include <Sounds.h>
#include <cstdio>

using namespace std;
int initobsflag = 0, vcount = 0, pcount = 0,cpo = 0,cko = 0,deadcounter = 0, deadcounter1 = 0, cpf1 = 0, cpf2 = 0, ckk = 0,cp1k = 0,cp2k = 0;
int boss=1;
int thunder=1;
int fireplayer=1;
int lvlcomplete=1;
int lvlcomplete2=1;
int endgame=1;
int menu=1;
int lvl1=1;
float score = 0;
float a = 4.0;
char *str;
int fire1=1;
int playershoot=1;
int lvl2=1;
int villianshoot=1;
float speed = 0.002;
float counter = 0.0;
Inputs *KbMs = new Inputs();
Parallax *Prlx = new Parallax();
Player *ply = new Player();
Shooting *shooting = new Shooting();
Obstacles *obs = new Obstacles();
Health *health = new Health();
fireBall1 *fb1 = new fireBall1();
fireBall2 *fb2 = new fireBall2();
Villain *vln = new Villain();
villain_Shooting *vlnshoot = new villain_Shooting();
Sounds *snds = new Sounds();
particle *part = new particle();
loadShaders *shader = new loadShaders();
loadShaders *shaderT = new loadShaders();

int deadstart = 0,killp2 = 0;
float rand_obst, rand_x, rand_y;


GLScene::GLScene()
{
    ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    ScreenHeight= GetSystemMetrics(SM_CYSCREEN);
}

GLScene::~GLScene()
{
    //dtor
}


int collision_kunai_obstacle(float ox, float kx){
    if(fabs(ox - kx) <= 0.5){
        return 1;
    }else{
        return 0;
    }
}

// return 0 = no collision
// return 1 = yes collision
int collision_Player_obstacle(float ox, float oy, float px){
    if(ox <= -0.7 && ox>=-1.0 && ply->actionTrigger != 3){
        return 1;
    }else{
        return 0;
    }
}

int collision_Player_fireBall1(float bx, float by, float px, float py){
    if(fabs(bx - px) <=0.5 && fabs(by-py)<=0.5){
        return 1;
    }
    return 0;
}


int collision_Player_fireBall2(float bx, float by, float px, float py){
    if(fabs(bx - px) <=0.5 && fabs(by-py)<=0.5){
            return 1;
    }
    return 0;
}
/**********************************/

//ckk = collision_kunai_kunai(vln->Player_x,shooting->Player_x);
//cp1k = collision_Player1_kunai(ply->Player_x,vlnshoot->Player_x);
//cp2k = collision_Player2_kunai(vln->Player_x,shooting->Player_x);

int collision_kunai_kunai(float k1x,float k2x){
    if(fabs(k1x - k2x +0.5) <=0.5){
        return 1;
    }
    return 0;
}
int collision_Player1_kunai(float px, float vlx){
    if(vlx < -0.9){
        return 1;
    }
    return 0;
}

int collision_Player2_kunai(float px, float sx){
    if(sx > 0.999){
        return 1;
    }
    return 0;
}

/*********************************/


void drawBitmapText(char *string,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}





float RandomNumber(float Min, float Max)
{
    return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}

GLvoid GLScene::ReSizeGLScene(GLsizei Width, GLsizei Height)		// Resize And Initialize The GL Window
{

GLfloat aspectRatio = (GLfloat)Width / (GLfloat)Height;

    ScreenWidth = Width;
    ScreenHeight= Height;

    glViewport(0, 0, Width, Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspectRatio, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
    glLoadIdentity();									// Reset The Modelview Matrix
}

int GLScene::WindowMsg(HWND hWnd,UINT uMsg, WPARAM wParam,LPARAM lParam)
{
    switch (uMsg)									// Check For Windows Messages
	{
		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
		    KbMs->wParam = wParam;
//		    KbMs->KeyEnv(Prlx,0.008);
		    KbMs->KeyPressed(ply);
		    KbMs->KeyPressed(Prlx);
            return 0;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			KbMs->wParam = wParam;
			KbMs->KeyUp(ply);
			return 0;								// Jump Back
		}

		case WM_LBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->MouseEventDown(Prlx,LOWORD(lParam),HIWORD(lParam));
            return 0;								// Jump Back
        }

   		case WM_RBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->MouseEventDown(Prlx,LOWORD(lParam),HIWORD(lParam));
            return 0;								// Jump Back
        }

          case WM_MBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->MouseEventDown(Prlx,LOWORD(lParam),HIWORD(lParam));
            return 0;								// Jump Back
        }

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
        {
//            KbMs->MouseEventUp();
            return 0;								// Jump Back
        }

        case WM_MOUSEMOVE:
        {
//             KbMs->MouseMove(Mdl, LOWORD(lParam),HIWORD(lParam));
             return 0;								// Jump Back
        }

        case WM_MOUSEWHEEL:
        {
//            KbMs->MouseWheel(Mdl,(double)GET_WHEEL_DELTA_WPARAM(wParam));
            return 0;								// Jump Back
        }

		case WM_SIZE:								// Resize The OpenGL Window
		{
                                                    // LoWord=Width, HiWord=Height
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));
			return 0;								// Jump Back
		}
	}
}

GLint GLScene::InitGL()									// All Setup For OpenGL Goes Here
{
    srand(time(NULL));
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	GLLight Light(GL_LIGHT0);

	//glewInit();


rand_obst = 22;
    rand_x = 3.0;
    rand_y =  -1.35;
    obs->Player_y = rand_y;
    obs->Player_x = rand_x;
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
//	GLLight Light(GL_LIGHT0);
    glewInit();
	KbMs->credit = 0;
	Prlx->PrlxInit("images/Credit.jpg");
	snds->menu();
	shooting->playerInit();
	ply->playerInit();
	health->playerInit();
	fb1->playerInit();
	fb2->playerInit();
	snds->soundinit();
	fb1->Player_x = RandomNumber(-2.0,0.0);
	fb1->Player_y = 1.5;
	fb2->Player_x = RandomNumber(0.0,2.10);
	fb2->Player_y = 1.5;
	vln->playerInit();
    vlnshoot->playerInit();

    shader->initShader("v.vs","f1.fs");
    shaderT->initShader("v1.vs","f.fs");
	return TRUE;										// Initialization Went OK
}

GLint GLScene::DrawGLScene()							// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix
    glColor3f(1.0f, 0.0f, 0.0f);//needs to be called before RasterPos
    glPushMatrix();
        glScalef(3.33,3.33,1.0);
        Prlx->DrawSquare(ScreenWidth,ScreenHeight);
    glPopMatrix();

    if(KbMs->credit == 1 && counter<10){
        Prlx->Xmax =  1.0f;
        Prlx->Xmin =  0.0f;
        Prlx->Ymax =  0.0f;
        Prlx->Ymin =  1.0f;
        Prlx->PrlxInit("images/story.jpg");
        counter++;
    }

    if(KbMs->credit == 1 && counter >= 10){
        if(KbMs->menu == 0){
            Prlx->Xmax =  1.0f;
            Prlx->Xmin =  0.0f;
            Prlx->Ymax =  0.0f;
            Prlx->Ymin =  1.0f;

            Prlx->PrlxInit("images/Game_menu.jpg");
            if(menu==0)
            {
                menu=1;
                snds->menu();
            }
            KbMs->menu = 1;
            KbMs->menuflag = 0;
            KbMs->helpflag = 1;
        }
        if(KbMs->help == 0){
            Prlx->Xmax =  1.0f;
            Prlx->Xmin =  0.0f;
            Prlx->Ymax =  0.0f;
            Prlx->Ymin =  1.0f;
            Prlx->PrlxInit("images/help.jpg");
            KbMs->helpflag = 0;
            KbMs->menuflag = 1;
            KbMs->help = 1;
        }
        if(KbMs->quit == 0){
            Prlx->Xmax =  1.0f;
            Prlx->Xmin =  0.0f;
            Prlx->Ymax =  0.0f;
            Prlx->Ymin =  1.0f;
            KbMs->newGame1 = 1;
            KbMs->newGame2 = 1;
            KbMs->newGame3 = 1;
            Prlx->PrlxInit("images/quit1.jpg");
            KbMs->quit = 1;
            KbMs->menuflag = 1;
        }
        // level 1
        if(KbMs->bgGame1 == 0){
            counter = 51.0;
            Prlx->PrlxInit("images/level1.jpg");
            KbMs->bgGame1 = 1;
            // level 2
        }if(KbMs->bgGame2 == 0 && KbMs->bgGame1 == 1){

            if(counter < 202 && counter >= 200){
                Prlx->Xmax =  1.0f;
                if(lvlcomplete==1)
                {
                   lvlcomplete=0;
                    snds->pausemusic("levelcomplete.wav");
                }

                Prlx->Xmin =  0.0f;
                Prlx->Ymax =  0.0f;
                Prlx->Ymin =  1.0f;
                Prlx->PrlxInit("images/complete.jpg");
            }if(counter >= 202 && counter < 203){
                Prlx->Xmax =  1.0f;
                Prlx->Xmin =  0.0f;
                Prlx->Ymax =  0.0f;
                Prlx->Ymin =  1.0f;
                Prlx->PrlxInit("images/next_level.jpg");
            }
            if(counter >= 203){
                Prlx->Xmax =  1.0f;
                Prlx->Xmin =  0.0f;
                Prlx->Ymax =  0.0f;
                Prlx->Ymin =  1.0f;
                //snds->stop5();
                Prlx->PrlxInit("images/stage2.jpg");
                KbMs->bgGame2 = 1;
            }
            // level 3
        }if(KbMs->bgGame3 == 0 && KbMs->bgGame2 == 1){
            if(counter < 302 && counter >=300){
                Prlx->Xmax =  1.0f;
                snds->stop7();
                if(lvlcomplete2==1)
                {
                    lvlcomplete2=0;
                    snds->pausemusic("levelcomplete.wav");
                }
                Prlx->Xmin =  0.0f;
                Prlx->Ymax =  0.0f;
                Prlx->Ymin =  1.0f;
                Prlx->PrlxInit("images/complete.jpg");
            }if(counter >= 302 && counter < 303){
                Prlx->Xmax =  1.0f;
                Prlx->Xmin =  0.0f;
                Prlx->Ymax =  0.0f;
                Prlx->Ymin =  1.0f;
                Prlx->PrlxInit("images/next_level.jpg");
            }
            else if(counter >= 303){
                Prlx->Xmax =  1.0f;
                Prlx->Xmin =  0.0f;
                Prlx->Ymax =  0.0f;
                //snds->stop6();
                Prlx->Ymin =  1.0f;
                Prlx->PrlxInit("images/dojo.jpg");
                KbMs->bgGame3 = 1;
            }
        }
        glPushMatrix();
            glScalef(3.33,3.33,1.0);
            Prlx->DrawSquare(ScreenWidth,ScreenHeight);
        glPopMatrix();
    }
    if(KbMs->newGame1 == 0 && KbMs->bgGame1 == 1 && KbMs->credit == 1 && counter <200){
        KbMs->KeyEnv(Prlx,speed);
        menu=1;
        snds->stop3();
        ply->Action(ply->actionTrigger);
        health->Action(deadcounter);
        if(lvl1==1)
        {
            lvl1=0;
            snds->lvl1();
        }
        char b[500];
        sprintf (b, "%f", score);
        str = b;
        drawBitmapText(str,1.2,0.65,-2.0);
        score++;

        // perform jump operation
        if(ply->actionTrigger == 3){
            if(ply->delay < 9){
                if(KbMs->jump==1 )
            {   KbMs->jump=0;
                snds->pausemusic("smw_jump.wav");
            }
                ply->actionTrigger = 3;
            }else{
                ply->actionTrigger = 1;
            }
        }

        // shoot kunai
        if(ply->actionTrigger == 4){
                if(KbMs->kunaisound==1)
                {
                    KbMs->kunaisound=0;
                    snds->kunai();
                }
            if(shooting->Player_x <= 1.8 ){
                shooting->Player_x += 0.025;
                shooting->Action();
            }else{
                ply->actionTrigger = 1;
                shooting->Player_x = -0.3;
            }
        }
        if(cko==1)
                {
                    //snds->stop1();
                    snds->pausemusic("Smash.wav");
                }
        if(rand_obst < 50){
            if(obs->Player_x >= -3.0){
                if(initobsflag == 0 ){
                    obs->playerInit();
                    initobsflag = 1;
                }

                if(cpo == 0 && cko == 0){
                    obs->Player_x -= 0.01;
                    obs->Action();
                }else{
                    // player dead game end
                    if(cko==1 ){
                        deadcounter++;
                        if(deadcounter >= 4){
                            ply->actionTrigger = 20;
                            deadstart ++;
                            if(deadstart == 2){
                                speed = 0;
                                Prlx->PrlxInit("images/end.jpg");
                                glPushMatrix();
                                    glScalef(3.33,3.33,1.0);
                                    Prlx->DrawSquare(ScreenWidth,ScreenHeight);
                                glPopMatrix();
                                KbMs->newGame1 = 1;
                                KbMs->endGame = 0;

                            }
                        }
                    }
                    rand_obst = (float)((rand() % 100) + 1);
                    obs->Player_x = rand_x;
                }
            }else{
                rand_obst = (float)((rand() % 100) + 1);
                obs->Player_x = rand_x;
            }
        }else{
            rand_obst = (float)((rand() % 100) + 1);
            obs->Player_x = rand_x;
        }
        if(ply->actionTrigger == 4){
            cpo = collision_kunai_obstacle(obs->Player_x,shooting->Player_x);
        }
        cko = collision_Player_obstacle(obs->Player_x,obs->Player_y,ply->Player_x);
        counter += 0.1;
    }
    // end game
    if(KbMs->endGame == 0){
        ply->actionTrigger = 10;
        speed =0;
        Prlx->Xmax =  1.0f;
        Prlx->Xmin =  0.0f;
        Prlx->Ymax =  0.0f;
        Prlx->Ymin =  1.0f;
        char b[500];
        sprintf (b, "%f", score);
        str = b;
        drawBitmapText(str,1.5,2.0,-2.0);
        Prlx->PrlxInit("images/end.jpg");

        KbMs->endGame = 5;
    }

    if(counter >= 200 && counter < 203){
        lvl1=1;
        snds->stop4();
        KbMs->bgGame2 = 0;
        KbMs->newGame1 = 1;
        KbMs->newGame2 = 0;
        deadcounter = 0;
        deadstart = 0;
        ply->actionTrigger1 = 10;
        counter +=0.1;
        score = 0;
    }


    // 2nd level
    if((counter>=203 && counter <300)  && KbMs->credit == 1 && KbMs->bgGame2 == 1 && KbMs->newGame2 == 0){
        ply->Action1(ply->actionTrigger1);
        health->Action(deadcounter);
        if(thunder==1)
        {   thunder=0;
            snds->thunder();
        }

        glPushMatrix();
            glUseProgram(shaderT->program);
            glTranslated(0.7,-1.5,1.0);
            part->generateParticle();
            part->drawParticle();
            part->lifeTime();
            glUseProgram(0);
        glPopMatrix();

        char b[500];
        sprintf (b, "%f", score);
        str = b;
        drawBitmapText(str,1.2,0.65,-2.0);
        score++;

        if(lvl2==1)
        {
            lvl2=0;
            snds->lvl2();
        }
        if(ply->actionTrigger1 == 1 && ply->Player_x <= 3.0){
            ply->Player_x += 0.005;
        }
        if(ply->actionTrigger1 == 2 && ply->Player_x >= -3.0){
            ply->Player_x -= 0.005;
        }
        if(fb1->Player_y >= -1.5 && cpf1 == 0 || fb2->Player_y >= -1.5 && cpf2 == 0){
            fb1->Action();
            if(fire1==1)
            {
                fire1=0;
            snds->pausemusic("fireball.wav");
            }

            fb1->Player_y -= 0.005;
            fb2->Action();
            fb2->Player_y -= 0.005;
        }else{
            fire1=1;
            fb1->Player_x = RandomNumber(-2.0,0);
            fb1->Player_y = fb2->Player_y = 1.5;
        }
        if(cpf1==1)
        {
            if(fireplayer==1)
            {
                fireplayer=0;
                snds->pausemusic("fireplayer.wav");
            }
        }

        if(cpf2==1)
        {
            if(fireplayer==1)
            {
                fireplayer=0;
                snds->pausemusic("fireplayer.wav");
            }
        }

        if(cpf1==1)
        {
            fireplayer=1;
        }
        if(cpf2==1)
        {
            fireplayer=1;
        }
        if(cpf1 == 1 || cpf2 == 1){


            deadcounter++;
            if(deadcounter>=3){
                ply->actionTrigger1 = 20;
                deadstart++;
                if(deadstart == 2){

                if(endgame==1)
        {
            endgame=0;
            snds->pausemusic("gameover.wav");
        }
                Prlx->PrlxInit("images/end.jpg");
                glPushMatrix();
                    glScalef(3.33,3.33,1.0);
                    Prlx->DrawSquare(ScreenWidth,ScreenHeight);
                glPopMatrix();
                KbMs->newGame2 = 1;
                KbMs->endGame = 0;
                if(endgame == 0)
                {   snds->stop7();
                    snds->stop2();
                }
                }
            }
            fb1->Player_x = RandomNumber(-2.0,0);
            fb1->Player_y = fb2->Player_y = 1.5;
        }
        cpf1 = collision_Player_fireBall1(fb1->Player_x,fb1->Player_y,ply->Player_x,ply->Player_y);
        cpf2 = collision_Player_fireBall2(fb2->Player_x,fb2->Player_y,ply->Player_x,ply->Player_y);
        counter+=0.1;

        GLint loc1 = glGetUniformLocation(shaderT->program,"Scale");
        glUseProgram(shaderT->program);
        if(loc1 != -1){
            glUniform1f(loc1,a);
        }
        glUseProgram(0);
        if(a>360.0){
            a = 0.0;
        }else{
            a += 0.1;
        }


       // counter += 0.01;

    }

    if(counter >= 300 && counter < 303){
        snds->stop2();
        KbMs->bgGame3 = 0;
        KbMs->bgGame2 = 1;
        KbMs->newGame1 = 1;
        KbMs->newGame2 = 1;
        KbMs->newGame3 = 0;
        deadcounter = 0;
        deadstart = 0;
        ply->actionTrigger2 = 10;
        ply->actionTrigger2 = 10;
        rand_obst = rand() % 100;
        shooting->Player_x = -0.9;
        vlnshoot->Player_x = 1.0;
        counter +=0.1;
        score = 0;
    }


    // 3nd level
    if(counter>=303 && KbMs->credit == 1 && KbMs->bgGame3 == 1 && KbMs->newGame3 == 0){
        ply->Action3(ply->actionTrigger2);
        health->Action(deadcounter);
        health->Action1(deadcounter1);
        if(boss==1)
        {
            boss=0;
        snds->running();
        }
        char b[500];
            sprintf (b, "%f", score);
            str = b;
            drawBitmapText(str,1.2,0.65,-2.0);

        if(rand_obst <= 25 || ply->actionTrigger2 == 4){
            if(cp2k == 1){
                score++;
                killp2++;
                if(killp2 == 6){
                    deadcounter1++;
                    health->Action1(deadcounter1);
                }else if(killp2 == 9){
                    deadcounter1++;
                    health->Action1(deadcounter1);
                }else if(killp2 == 12){
                    deadcounter1++;
                    health->Action1(deadcounter1);
                    KbMs->endGame = 0;
                if(KbMs->endGame == 0)
                {
                    snds->stop();
                }
                if(endgame==1)
                {
                    endgame=0;
                    snds->pausemusic("gameover.wav");
                }
                    KbMs->newGame3 = 1;
                }
            }
            if(cp1k == 1){
                deadcounter = 3;
                health->Action(deadcounter);
                KbMs->endGame = 0;
                if(KbMs->endGame == 0)
                {
                    snds->stop();
                }
                if(endgame==1)
                {
                    endgame=0;
                    snds->pausemusic("gameover.wav");
                }
                KbMs->newGame3 = 1;
            }
            if(ckk == 1){
                ply->actionTrigger2 = 10;
                shooting->Player_x = -0.9;
                vln->Action(10);
                vlnshoot->Player_x = 1.0;
                playershoot=1;
                villianshoot=1;
                rand_obst = 51;
                vcount = 0;
            }
            if(ply->actionTrigger2 == 4 ){
                if(shooting->Player_x < 1.2){
                        shooting->Action();
                        if(playershoot==1)
                        {
                            playershoot=0;
                            snds->pausemusic("kunai.wav");
                        }
                        shooting->Player_x +=0.0095;
                }else{

                    ply->actionTrigger2 = 10;
                    shooting->Player_x = -0.9;
                    pcount = 0;
                }
            }
          if(rand_obst <= 25){
                if(vlnshoot->Player_x >= -1.6){
                    if(vcount < 500){
                        vln->Action(1);
                        if(villianshoot==1)
                        {
                            villianshoot=0;
                            snds->pausemusic("bossthrow.wav");
                        }

                        }else{
                        vln->Action(10);
                    }
                    vlnshoot->Action();
                    vlnshoot->Player_x -= 0.008;
                    vcount += 1;
                }else{
                    vlnshoot->Player_x = 1.0;
                    vcount = 0;
                }
            }
        }if(rand_obst > 25){
            vln->Action(10);
            vlnshoot->Player_x = 1.0;
            rand_obst = RandomNumber(15,10000);
            cout<<rand_obst<<endl;
        }if(ply->actionTrigger2 != 4){
            ply->Action3(10);
            shooting->Player_x = -0.9;
        }

        ckk = collision_kunai_kunai(vlnshoot->Player_x,shooting->Player_x);
        cp1k = collision_Player1_kunai(ply->Player_x,vlnshoot->Player_x);
        cp2k = collision_Player2_kunai(vln->Player_x,shooting->Player_x);
    }
    glDisable(GL_TEXTURE);
  	return TRUE;
  	return TRUE;										// Keep Going
}

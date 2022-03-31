#include<windows.h>
#include <GL/glut.h>
#include <math.h>

static float cld1, cld5, cld6=-1;
static float cld3=-1;
static float cld7=-1;

static float sx=.49;
static float sy=.96;
static float sz=1;

static float sm1=.968;
static float sm2=.913;
static float sm3=.145;

static float	tx	=  0;
static float	ty	=  0;
static float	tx1	=  0;
static float	ty1	=  0;
static float road1_1=1;
static float road1_1C1=1;///red car

static float road1_2C1=-1;
static float road1_2C2=-1;

static float road2_1C1=1;
static float road2_1C2=1;
static float road2_2C1=-1;
static float road2_2C2=-1;

static float boat_=-1;

void Initialize( )
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}


void DrawCircle(float radius,float cx, float cy)
{
    int i=0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * 3.1416 * i / 100;
			float x=radius*cos(angle);
			float y=1.7*radius*sin(angle);
			glVertex2f (x+cx, y+cy);

		}

	glEnd();
}

///--------------------------------Moving objects-----------------------------------------------
void sun_moon()
{
///sky-------------------------------------------------------
///glColor3f(0.49, .96, 1);
///glColor3f(0.105, .023, .212);///night
glColor3f(sx, sy, sz);
glBegin(GL_QUADS);
 glVertex3f(-1, -0.35, 0.0);
 glVertex3f(-1, 1, 0.0);
 glVertex3f(1, 1, 0.0);
 glVertex3f(1, -0.35, 0.0);
glEnd();

///sun
glColor3f(sm1, sm2, sm3);
DrawCircle(.06,-.677,.78);

}
void cloud1()
{
    glColor3f(0.686, 0.8, 0.8);
    DrawCircle(.03,-.765,.750);
    DrawCircle(.03,-.715,.750);
    DrawCircle(.03,-.740,.770);
    DrawCircle(.03,-.740,.730);
}
void cloud3()
{
    glColor3f(0.686, 0.8, 0.8);
    DrawCircle(.03, .765, .750);
    DrawCircle(.03, .715, .750);
    DrawCircle(.03, .740, .770);
    DrawCircle(.03, .740, .730);
}
void cloud4()
{
    glColor3f(0.686, 0.8, 0.8);
    DrawCircle(.03, -.475, .650);
    DrawCircle(.03, -.425, .650);
    DrawCircle(.03, -.450, .670);
    DrawCircle(.03, -.450, .630);
}
void cloud5()
{
    glColor3f(0.686, 0.8, 0.8);
    DrawCircle(.03, .375, .650);
    DrawCircle(.03, .325, .650);
    DrawCircle(.03, .350, .670);
    DrawCircle(.03, .350, .630);
}
void cloud6()
{
    glColor3f(0.686, 0.8, 0.8);
    DrawCircle(.03, -.315, .850);
    DrawCircle(.03, -.265, .850);
    DrawCircle(.03, -.290, .870);
    DrawCircle(.03, -.290, .830);
}
void cloud7()
{
    glColor3f(0.686, 0.8, 0.8);
    DrawCircle(.03, .555, .850);
    DrawCircle(.03, .505, .850);
    DrawCircle(.03, .530, .870);
    DrawCircle(.03, .530, .830);
}
void window1()
{
  glColor3f(tx, ty, 0);
    glBegin(GL_QUADS);
     glVertex3f(-.130, .17, 0.0);
     glVertex3f(-.130, .2, 0.0);
     glVertex3f(-.11, .2, 0.0);
     glVertex3f(-.11, 0.17, 0.0);
    glEnd();

    ///window_func
glColor3f(tx, tx, 0);
    glBegin(GL_QUADS);
     glVertex3f(-.120, -.19, 0.0);
     glVertex3f(-.120, -.16, 0.0);
     glVertex3f(-.100, -.16, 0.0);
     glVertex3f(-.100, -.19, 0.0);
    glEnd();

///building-3
glColor3f(tx, tx, 0);
    glBegin(GL_QUADS);
     glVertex3f(-.610, .17, 0.0);
     glVertex3f(-.610, .2, 0.0);
     glVertex3f(-.590, .2, 0.0);
     glVertex3f(-.590, 0.17, 0.0);
    glEnd();
glColor3f(tx, tx, 0);
    glBegin(GL_QUADS);
     glVertex3f(-.630, -.07, 0.0);
     glVertex3f(-.630, -.04, 0.0);
     glVertex3f(-.610, -.04, 0.0);
     glVertex3f(-.610, -.07, 0.0);
    glEnd();

}
void window2()
{
  glColor3f(tx, ty, 0);
    glBegin(GL_QUADS);
     glVertex3f(-.090, -.01, 0.0);
     glVertex3f(-.090, .02, 0.0);
     glVertex3f(-.070, .02, 0.0);
     glVertex3f(-.070, -0.01, 0.0);
    glEnd();
glColor3f(tx, ty, 0);
    glBegin(GL_QUADS);
     glVertex3f(.090, -.01, 0.0);
     glVertex3f(.090, .02, 0.0);
     glVertex3f(.115, .02, 0.0);
     glVertex3f(.115, -0.01, 0.0);
    glEnd();

glColor3f(tx, ty, 0);
    glBegin(GL_QUADS);
     glVertex3f(.090, -.10, 0.0);
     glVertex3f(.090, -.13, 0.0);
     glVertex3f(.115, -.13, 0.0);
     glVertex3f(.115, -0.10, 0.0);
    glEnd();

glColor3f(tx, ty, 0);
    glBegin(GL_QUADS);
     glVertex3f(.205, -.04, 0.0);
     glVertex3f(.205, -.07, 0.0);
     glVertex3f(.230, -.07, 0.0);
     glVertex3f(.230, -0.04, 0.0);
    glEnd();

glColor3f(tx, ty, 0);
    glBegin(GL_QUADS);
     glVertex3f(.205, -.28, 0.0);
     glVertex3f(.205, -.31, 0.0);
     glVertex3f(.230, -.31, 0.0);
     glVertex3f(.230, -0.28, 0.0);
    glEnd();

glColor3f(tx, ty, 0);
    glBegin(GL_QUADS);
     glVertex3f(.150, -.22, 0.0);
     glVertex3f(.150, -.25, 0.0);
     glVertex3f(.175, -.25, 0.0);
     glVertex3f(.175, -0.22, 0.0);
    glEnd();
}
void topCircle()
{
  glColor3f(tx1, ty1, 0);
  DrawCircle(.00295,-.465,.700);


}
///cars-----------------------------------------------------------------------------------
///-------------------<<<<<ROAD-1>>>>>-----------------------
void Road1_1Car1()
{
    ///road-1(right to left),car-1-------------------
    ///lower body
    glColor3f(0.858, .294, .07);
    glBegin(GL_QUADS);
     glVertex3f(.65, -.3675, 0.0);
     glVertex3f(.65, -.3425, 0.0);
     glVertex3f(.7, -.3425, 0.0);
     glVertex3f(.7, -0.3675, 0.0);
    glEnd();
        ///upper body
    glColor3f(0.909, .611, .490);
    glBegin(GL_QUADS);
     glVertex3f(.662, -.3425, 0.0);
     glVertex3f(.67, -.3255, 0.0);
     glVertex3f(.688, -.3255, 0.0);
     glVertex3f(.694, -0.3425, 0.0);
    glEnd();
        ///wheels
    glColor3f(.0, .0, .0);DrawCircle(.007,.66,-.366);
    glColor3f(.0, .0, .0);DrawCircle(.007,.69,-.366);
       ///window-border
    glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.662, -.3425, 0.0);glVertex3f(.67, -.3255, 0.0);glEnd();
    glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.67, -.3255, 0.0);glVertex3f(.688, -.3255, 0.0);glEnd();
    glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.688, -.3255, 0.0);glVertex3f(.694, -0.3425, 0.0);glEnd();
    ///body-border
    glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.65, -.3675, 0.0);glVertex3f(.65, -.3425, 0.0);glEnd();
    glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.65, -.3425, 0.0);glVertex3f(.7, -.3425, 0.0);glEnd();
    glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.7, -.3425, 0.0);glVertex3f(.7, -0.3675, 0.0);glEnd();
    glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.65, -.3675, 0.0);glVertex3f(.7, -0.3675, 0.0);glEnd();
       ///window/door
    glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.678, -.3425, 0.0);glVertex3f(.678, -.3255, 0.0);glEnd();///window
    glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.678, -.3425, 0.0);glVertex3f(.678, -.3655, 0.0);glEnd();///door
    ///------------------------
}

void Road1_1Car2()
{
    ///road-1(right to left),car-2------------------
    ///lower body
glColor3f(0.113, .239, .380);
glBegin(GL_QUADS);
 glVertex3f(.05, -.3675, 0.0);
 glVertex3f(.05, -.3425, 0.0);
 glVertex3f(.1, -.3425, 0.0);
 glVertex3f(.1, -0.3675, 0.0);
glEnd();
    ///upper body
glColor3f(0.929, .929, .705);
glBegin(GL_QUADS);
 glVertex3f(.062, -.3425, 0.0);
 glVertex3f(.07, -.3255, 0.0);
 glVertex3f(.088, -.3255, 0.0);
 glVertex3f(.094, -0.3425, 0.0);
glEnd();
    ///wheels
glColor3f(.0, .0, .0);DrawCircle(.007,.06,-.366);
glColor3f(.0, .0, .0);DrawCircle(.007,.09,-.366);
   ///window-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.062, -.3425, 0.0);glVertex3f(.07, -.3255, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.07, -.3255, 0.0);glVertex3f(.088, -.3255, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.088, -.3255, 0.0);glVertex3f(.094, -0.3425, 0.0);glEnd();
///body-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.05, -.3675, 0.0);glVertex3f(.05, -.3425, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.05, -.3425, 0.0);glVertex3f(.1, -.3425, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.1, -.3425, 0.0);glVertex3f(.1, -0.3675, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.05, -.3675, 0.0);glVertex3f(.1, -0.3675, 0.0);glEnd();
   ///window/door
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.078, -.3425, 0.0);glVertex3f(.078, -.3255, 0.0);glEnd();///window
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.078, -.3425, 0.0);glVertex3f(.078, -.3655, 0.0);glEnd();///door
///-----------------
}

void Road1_1Car3()
{
    ///road-1(right to left),car-3(Truck)------------------
    ///body-1
glColor3f(0.243, .607, .709);
glBegin(GL_QUADS);
 glVertex3f(-.6, -.3675, 0.0);
 glVertex3f(-.6, -.3185, 0.0);
 glVertex3f(-.548, -.3185, 0.0);
 glVertex3f(-.548, -0.3675, 0.0);
glEnd();
   ///body1-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.6, -.3675, 0.0);glVertex3f(-.6, -.3185, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(-.6, -.3185, 0.0);glVertex3f(-.548, -.3185, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.548, -.3185, 0.0);glVertex3f(-.548, -0.3675, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.6, -.3675, 0.0);glVertex3f(-.548, -0.3675, 0.0);glEnd();
    ///body-2
glColor3f(0.301, .317, .4);
glBegin(GL_QUADS);
 glVertex3f(-.62, -.3675, 0.0);
 glVertex3f(-.62, -.3185, 0.0);
 glVertex3f(-.605, -.3185, 0.0);
 glVertex3f(-.605, -0.3675, 0.0);
glEnd();
   ///body2-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.62, -.3675, 0.0);glVertex3f(-.62, -.3185, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(-.62, -.3185, 0.0);glVertex3f(-.605, -.3185, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.605, -.3185, 0.0);glVertex3f(-.605, -0.3675, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.62, -.3675, 0.0);glVertex3f(-.605, -0.3675, 0.0);glEnd();
    ///body-1+body-2
glColor3f(0.0, .0, .0);
glBegin(GL_QUADS);
 glVertex3f(-.606, -.3645, 0.0);
 glVertex3f(-.606, -.3545, 0.0);
 glVertex3f(-.6, -.3545, 0.0);
 glVertex3f(-.6, -0.3645, 0.0);
glEnd();
    ///body-3
glColor3f(0.474, .513, .709);
glBegin(GL_QUADS);
 glVertex3f(-.63, -.3675, 0.0);
 glVertex3f(-.63, -.3425, 0.0);
 glVertex3f(-.62, -.3325, 0.0);
 glVertex3f(-.62, -0.3675, 0.0);
glEnd();
   ///body3-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.63, -.3675, 0.0);glVertex3f(-.63, -.3425, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(-.63, -.3425, 0.0);glVertex3f(-.62, -.3325, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.62, -.3325, 0.0);glVertex3f(-.62, -0.3675, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.63, -.3675, 0.0);glVertex3f(-.62, -0.3675, 0.0);glEnd();
    ///wheel
glColor3f(.0, .0, .0);DrawCircle(.007,-.62,-.366);
glColor3f(.0, .0, .0);DrawCircle(.007,-.556,-.366);
glColor3f(.0, .0, .0);DrawCircle(.007,-.570,-.366);
///-----------------------------
}

void Road1_2Car1()
{
    ///road-1(left to right),car-1(School bus)------------------
    ///body-1
glColor3f(0.721, .721, .086);
glBegin(GL_QUADS);
 glVertex3f(-.3, -.4025, 0.0);
 glVertex3f(-.3, -.3525, 0.0);
 glVertex3f(-.238, -.3525, 0.0);
 glVertex3f(-.238, -0.4025, 0.0);
glEnd();
   ///body1-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.3, -.4025, 0.0);glVertex3f(-.3, -.3525, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(-.3, -.3525, 0.0);glVertex3f(-.238, -.3525, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.238, -.3525, 0.0);glVertex3f(-.238, -0.4025, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.3, -.4025, 0.0);glVertex3f(-.238, -0.4025, 0.0);glEnd();

    ///body-2
glColor3f(0.768, .768, .385);
glBegin(GL_QUADS);
 glVertex3f(-.238, -.4025, 0.0);
 glVertex3f(-.238, -.3725, 0.0);
 glVertex3f(-.22, -.38, 0.0);
 glVertex3f(-.22, -0.4025, 0.0);
glEnd();
   ///body2-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.238, -.4025, 0.0);glVertex3f(-.238, -.3725, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(-.238, -.3725, 0.0);glVertex3f(-.22, -.38, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.22, -.38, 0.0);glVertex3f(-.22, -0.4025, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.238, -.4025, 0.0);glVertex3f(-.22, -0.4025, 0.0);glEnd();
    ///door
glColor3f(0.811, .811, .533);
glBegin(GL_QUADS);
 glVertex3f(-.250, -.4025, 0.0);
 glVertex3f(-.250, -.3625, 0.0);
 glVertex3f(-.242, -.3625, 0.0);
 glVertex3f(-.242, -0.4025, 0.0);
glEnd();
   ///door-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.250, -.4025, 0.0);glVertex3f(-.250, -.3625, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(-.250, -.3625, 0.0);glVertex3f(-.242, -.3625, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.242, -.3625, 0.0);glVertex3f(-.242, -0.4025, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.250, -.4025, 0.0);glVertex3f(-.242, -0.4025, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.246, -.4025, 0.0);glVertex3f(-.246, -0.3625, 0.0);glEnd();///door-divider

    ///window
glColor3f(0.878, .901, .701);
glBegin(GL_QUADS);
 glVertex3f(-.295, -.3785, 0.0);
 glVertex3f(-.295, -.36, 0.0);
 glVertex3f(-.255, -.36, 0.0);
 glVertex3f(-.255, -0.3785, 0.0);
glEnd();
   ///window-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.295, -.3785, 0.0);glVertex3f(-.295, -.36, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(-.295, -.36, 0.0);glVertex3f(-.255, -.36, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.255, -.36, 0.0);glVertex3f(-.255, -0.3785, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.295, -.3785, 0.0);;glVertex3f(-.255, -0.3785, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.2817, -.3785, 0.0);;glVertex3f(-.2817, -0.36, 0.0);glEnd();///divider-1
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.2684, -.3785, 0.0);;glVertex3f(-.2684, -0.36, 0.0);glEnd();///divider-2
   ///wheel
glColor3f(.0, .0, .0);DrawCircle(.007,-.23,-.4015);
glColor3f(.0, .0, .0);DrawCircle(.007,-.285,-.4015);
///-----------------------------
}

void Road1_2Car2()
{
    ///road-1(left to right),car-2------------------
    ///lower body
glColor3f(0.337, .819, .164);
glBegin(GL_QUADS);
 glVertex3f(.35, -.4025, 0.0);
 glVertex3f(.35, -.3775, 0.0);
 glVertex3f(.4, -.3775, 0.0);
 glVertex3f(.4, -0.4025, 0.0);
glEnd();
    ///upper body
glColor3f(0.929, .929, .705);
glBegin(GL_QUADS);
 glVertex3f(.356, -.3775, 0.0);
 glVertex3f(.362, -.3605, 0.0);
 glVertex3f(.38, -.3605, 0.0);
 glVertex3f(.388, -0.3775, 0.0);
glEnd();
    ///wheels
glColor3f(.0, .0, .0);DrawCircle(.007,.36,-.4015);
glColor3f(.0, .0, .0);DrawCircle(.007,.39,-.4015);
   ///window-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.356, -.3775, 0.0);glVertex3f(.362, -.3605, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.362, -.3605, 0.0);glVertex3f(.38, -.3605, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.38, -.3605, 0.0);glVertex3f(.388, -0.3775, 0.0);glEnd();
///body-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.35, -.4025, 0.0);glVertex3f(.35, -.3775, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.35, -.3775, 0.0);glVertex3f(.4, -.3775, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.4, -.3775, 0.0);glVertex3f(.4, -0.4025, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.35, -.4025, 0.0);glVertex3f(.4, -0.4025, 0.0);glEnd();
   ///window/door
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.372, -.3775, 0.0);glVertex3f(.372, -.3605, 0.0);glEnd();///window
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.372, -.4, 0.0);glVertex3f(.372, -.3775, 0.0);glEnd();///door
///-----------------------------------
}
///--------------<<<<<<ROAD-2>>>>>>----------------------
void Road2_1Car1()
{
    ///road-2(right to left),car-1(truck)------------------
///body-1
glColor3f(0.721, .396, .070);
glBegin(GL_QUADS);
 glVertex3f(.5, -.925, 0.0);
 glVertex3f(.5, -.845, 0.0);
 glVertex3f(.6, -.845, 0.0);
 glVertex3f(.6, -0.925, 0.0);
glEnd();
   ///body1-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.5, -.925, 0.0);glVertex3f(.5, -.845, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.5, -.845, 0.0);glVertex3f(.6, -.845, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.6, -.845, 0.0);glVertex3f(.6, -0.925, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.5, -.925, 0.0);glVertex3f(.6, -0.925, 0.0);glEnd();
    ///body-2
glColor3f(0.301, .317, .4);
glBegin(GL_QUADS);
 glVertex3f(.465, -.925, 0.0);
 glVertex3f(.465, -.845, 0.0);
 glVertex3f(.49, -.845, 0.0);
 glVertex3f(.49, -0.925, 0.0);
glEnd();
   ///body2-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.465, -.925, 0.0);glVertex3f(.465, -.845, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.465, -.845, 0.0);glVertex3f(.49, -.845, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.49, -.845, 0.0);glVertex3f(.49, -0.925, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.465, -.925, 0.0);glVertex3f(.49, -0.925, 0.0);glEnd();
    ///body-1+body-2
glColor3f(0.0, .0, .0);
glBegin(GL_QUADS);
 glVertex3f(.49, -.915, 0.0);
 glVertex3f(.49, -.895, 0.0);
 glVertex3f(.5, -.895, 0.0);
 glVertex3f(.5, -0.915, 0.0);
glEnd();
    ///body-3
glColor3f(0.474, .513, .709);
glBegin(GL_QUADS);
 glVertex3f(.445, -.925, 0.0);
 glVertex3f(.445, -.88, 0.0);
 glVertex3f(.465, -.87, 0.0);
 glVertex3f(.465, -0.925, 0.0);
glEnd();
   ///body3-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.445, -.925, 0.0);glVertex3f(.445, -.88, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.445, -.88, 0.0);glVertex3f(.465, -.87, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.465, -.87, 0.0);glVertex3f(.465, -0.925, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.445, -.925, 0.0);glVertex3f(.465, -0.925, 0.0);glEnd();
    ///wheel
glColor3f(.0, .0, .0);DrawCircle(.009,.465,-.923);
glColor3f(.0, .0, .0);DrawCircle(.009,.59,-.923);
glColor3f(.0, .0, .0);DrawCircle(.009,.57,-.923);
///-----------------------------
}

void Road2_1Car2()
{
    ///road-2(right to left),car-2------------------
    ///lower body
glColor3f(0.458, .458, .458);
glBegin(GL_QUADS);
 glVertex3f(-.35, -.925, 0.0);
 glVertex3f(-.35, -.885, 0.0);
 glVertex3f(-.27, -.885, 0.0);
 glVertex3f(-.27, -0.925, 0.0);
glEnd();
    ///upper body
glColor3f(0.819, .819, .819);
glBegin(GL_QUADS);
 glVertex3f(-.33, -.885, 0.0);
 glVertex3f(-.324, -.865, 0.0);
 glVertex3f(-.288, -.865, 0.0);
 glVertex3f(-.280, -0.885, 0.0);
glEnd();
    ///wheels
glColor3f(.0, .0, .0);DrawCircle(.009,-.335,-.923);
glColor3f(.0, .0, .0);DrawCircle(.009,-.285,-.923);
   ///window-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.33, -.885, 0.0);glVertex3f(-.324, -.865, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(-.324, -.865, 0.0);glVertex3f(-.288, -.865, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.288, -.865, 0.0);glVertex3f(-.280, -0.885, 0.0);glEnd();
///body-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.35, -.925, 0.0);glVertex3f(-.35, -.885, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(-.35, -.885, 0.0);glVertex3f(-.27, -.885, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.27, -.885, 0.0);glVertex3f(-.27, -0.925, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.35, -.925, 0.0);glVertex3f(-.27, -0.925, 0.0);glEnd();
   ///window/door
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.305, -.885, 0.0);glVertex3f(-.305, -.865, 0.0);glEnd();///window
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.305, -.915, 0.0);glVertex3f(-.305, -.885, 0.0);glEnd();///door
///-----------------
}

void Road2_2Car1()
{
    ///road-2(left to right),car-1------------------
    ///lower body
glColor3f(0.278, .067, .067);
glBegin(GL_QUADS);
 glVertex3f(-.76, -.975, 0.0);
 glVertex3f(-.76, -.935, 0.0);
 glVertex3f(-.68, -.935, 0.0);
 glVertex3f(-.68, -0.975, 0.0);
glEnd();
    ///upper body
glColor3f(0.819, .819, .819);
glBegin(GL_QUADS);
 glVertex3f(-.75, -.935, 0.0);
 glVertex3f(-.742, -.915, 0.0);
 glVertex3f(-.706, -.915, 0.0);
 glVertex3f(-.70, -0.935, 0.0);
glEnd();
    ///wheels
glColor3f(.0, .0, .0);DrawCircle(.009,-.745,-.973);
glColor3f(.0, .0, .0);DrawCircle(.009,-.697,-.973);
   ///window-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.75, -.935, 0.0);glVertex3f(-.742, -.915, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(-.742, -.915, 0.0);glVertex3f(-.706, -.915, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.706, -.915, 0.0);glVertex3f(-.70, -0.935, 0.0);glEnd();
///body-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.76, -.975, 0.0);glVertex3f(-.76, -.935, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(-.76, -.935, 0.0);glVertex3f(-.68, -.935, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.68, -.935, 0.0);glVertex3f(-.68, -0.975, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.76, -.975, 0.0);glVertex3f(-.68, -0.975, 0.0);glEnd();
   ///window/door
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.725, -.935, 0.0);glVertex3f(-.725, -.915, 0.0);glEnd();///window
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(-.725, -.965, 0.0);glVertex3f(-.725, -.915, 0.0);glEnd();///door
///-----------------------------------
}

void Road2_2Car2()
{
    ///road-2(left to right),car-2------------------
    ///lower body
glColor3f(0.113, .549, .513);
glBegin(GL_QUADS);
 glVertex3f(.1, -.975, 0.0);
 glVertex3f(.1, -.935, 0.0);
 glVertex3f(.18, -.935, 0.0);
 glVertex3f(.18, -0.975, 0.0);
glEnd();
    ///upper body
glColor3f(0.819, .819, .819);
glBegin(GL_QUADS);
 glVertex3f(.11, -.935, 0.0);
 glVertex3f(.118, -.915, 0.0);
 glVertex3f(.154, -.915, 0.0);
 glVertex3f(.16, -0.935, 0.0);
glEnd();
    ///wheels
glColor3f(.0, .0, .0);DrawCircle(.009,.115,-.973);
glColor3f(.0, .0, .0);DrawCircle(.009,.163,-.973);
   ///window-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.11, -.935, 0.0);glVertex3f(.118, -.915, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.118, -.915, 0.0);glVertex3f(.154, -.915, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.154, -.915, 0.0);glVertex3f(.16, -0.935, 0.0);glEnd();
///body-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.1, -.975, 0.0);glVertex3f(.1, -.935, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.1, -.935, 0.0);glVertex3f(.18, -.935, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.18, -.935, 0.0);glVertex3f(.18, -0.975, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.18, -0.975, 0.0);glVertex3f(.1, -.975, 0.0);glEnd();
   ///window/door
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.135, -.935, 0.0);glVertex3f(.135, -.915, 0.0);glEnd();///window
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.135, -.965, 0.0);glVertex3f(.135, -.915, 0.0);glEnd();///door
///-----------------------------------
}
///--------------------------------------<<<<<Boat>>>>>-----------------------------------------------------------
void boat()
{
        ///upper body
glColor3f(.301, .658, .631);
glBegin(GL_QUADS);
 glVertex3f(.09, -.7, 0.0);
 glVertex3f(.09, -.65, 0.0);
 glVertex3f(.155, -.6, 0.0);
 glVertex3f(.2, -.66, 0.0);
glEnd();
   ///upper_body-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.09, -.7, 0.0);glVertex3f(.09, -.65, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.09, -.65, 0.0);glVertex3f(.155, -.6, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.155, -.6, 0.0);glVertex3f(.2, -.66, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.09, -.7, 0.0);glVertex3f(.2, -.66, 0.0);glEnd();

    ///window
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_TRIANGLES);
 glVertex3f(.13, -.65, 0.0);
 glVertex3f(.155, -.615, 0.0);
 glVertex3f(.17, -.635, 0.0);
glEnd();
   ///window-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.13, -.65, 0.0);glVertex3f(.155, -.615, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.155, -.615, 0.0);glVertex3f(.17, -.635, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.17, -.635, 0.0);glVertex3f(.13, -.65, 0.0);glEnd();


    ///lower body
glColor3f(0.458, .458, .458);
glBegin(GL_QUADS);
 glVertex3f(.05, -.705, 0.0);
 glVertex3f(.049, -.695, 0.0);
 glVertex3f(.215, -.63, 0.0);
 glVertex3f(.2, -.705, 0.0);
glEnd();
   ///lower_body-border
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.05, -.705, 0.0);glVertex3f(.049, -.695, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES); glVertex3f(.049, -.695, 0.0);glVertex3f(.215, -.63, 0.0);glEnd();
glColor3f(.0, .0, .0);glBegin(GL_LINES);glVertex3f(.215, -.63, 0.0);glVertex3f(.2, -.705, 0.0);glEnd();

///boat end-------------------------------------------------------------------------------------------------------
}
///------------------------------------------------Movement_end------------------------------------------------

void Draw()
{
glClear(GL_COLOR_BUFFER_BIT);

///sky-------------------------------------------------------
sun_moon();
///sun


///road1----------------------------------------------------
glColor3f(0.22, .23, .231);
glBegin(GL_QUADS);
 glVertex3f(-1, -0.42, 0.0);
 glVertex3f(-1, -0.35, 0.0); ///-.35 base for building
 glVertex3f(1, -0.35, 0.0);
 glVertex3f(1, -0.42, 0.0);
glEnd();
    ///road divider (y=-.385)
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-1, -.385, 0.0);glVertex3f(-.97, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.9, -.385, 0.0);glVertex3f(-.87, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.8, -.385, 0.0);glVertex3f(-.77, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.7, -.385, 0.0);glVertex3f(-.67, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.6, -.385, 0.0);glVertex3f(-.57, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.5, -.385, 0.0);glVertex3f(-.47, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.4, -.385, 0.0);glVertex3f(-.37, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.3, -.385, 0.0);glVertex3f(-.27, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.2, -.385, 0.0);glVertex3f(-.17, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.1, -.385, 0.0);glVertex3f(-.07, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.0, -.385, 0.0);glVertex3f(.03, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.1, -.385, 0.0);glVertex3f(.13, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.2, -.385, 0.0);glVertex3f(.23, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.3, -.385, 0.0);glVertex3f(.33, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.4, -.385, 0.0);glVertex3f(.43, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.5, -.385, 0.0);glVertex3f(.53, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.6, -.385, 0.0);glVertex3f(.63, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.7, -.385, 0.0);glVertex3f(.73, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.8, -.385, 0.0);glVertex3f(.83, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.9, -.385, 0.0);glVertex3f(.93, -.385, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.99, -.385, 0.0);glVertex3f(1, -.385, 0.0);glEnd();


///road2-----------------------------------------------------
glColor3f(0.22, .23, .231);
glBegin(GL_QUADS);
 glVertex3f(-1, -1, 0.0);
 glVertex3f(-1, -0.9, 0.0);
 glVertex3f(1, -0.9, 0.0);
 glVertex3f(1, -1, 0.0);
glEnd();
    ///road divider (y=-.95)
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-1, -.95, 0.0);glVertex3f(-.95, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.9, -.95, 0.0);glVertex3f(-.85, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.8, -.95, 0.0);glVertex3f(-.75, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.7, -.95, 0.0);glVertex3f(-.65, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.6, -.95, 0.0);glVertex3f(-.55, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.5, -.95, 0.0);glVertex3f(-.45, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.4, -.95, 0.0);glVertex3f(-.35, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.3, -.95, 0.0);glVertex3f(-.25, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.2, -.95, 0.0);glVertex3f(-.15, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(-.1, -.95, 0.0);glVertex3f(-.05, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.0, -.95, 0.0);glVertex3f(.05, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.1, -.95, 0.0);glVertex3f(.15, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.2, -.95, 0.0);glVertex3f(.25, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.3, -.95, 0.0);glVertex3f(.35, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.4, -.95, 0.0);glVertex3f(.45, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.5, -.95, 0.0);glVertex3f(.55, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.6, -.95, 0.0);glVertex3f(.65, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.7, -.95, 0.0);glVertex3f(.75, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.8, -.95, 0.0);glVertex3f(.85, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.9, -.95, 0.0);glVertex3f(.95, -.95, 0.0);glEnd();
glColor3f(1, 1, 1);glBegin(GL_LINES);glVertex3f(.995, -.95, 0.0);glVertex3f(1, -.95, 0.0);glEnd();

///river--------------------------------------------------------
glColor3f(0.21, .51, .65);
glBegin(GL_QUADS);
 glVertex3f(-1, -0.9, 0.0);
 glVertex3f(-1, -0.42, 0.0);
 glVertex3f(1, -0.42, 0.0);
 glVertex3f(1, -0.9, 0.0);
glEnd();
///------------------------------------------------------------------------------------
            ///buildings////
///building-1 width=.117(.065,.052)----------------------------------------------------
    ///side-1
glColor3f(0.5, .55, .5);
glBegin(GL_QUADS);
 glVertex3f(-1, -.35, 0.0);
 glVertex3f(-1, 0.44, 0.0);
 glVertex3f(-.935, 0.42, 0.0);
 glVertex3f(-.935, -0.35, 0.0);
glEnd();
        ///side-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-1, -.35, 0.0);glVertex3f(-1, 0.44, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-1, 0.44, 0.0);glVertex3f(-.935, 0.42, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.935, 0.42, 0.0);glVertex3f(-.935, -0.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-1, -.35, 0.0);glVertex3f(-.935, -0.35, 0.0);glEnd();
    ///side-2
glColor3f(0.5, .35, .5);
glBegin(GL_QUADS);
 glVertex3f(-.935, -.35, 0.0);
 glVertex3f(-.935, 0.42, 0.0);
 glVertex3f(-.883, 0.44, 0.0);
 glVertex3f(-.883, -0.35, 0.0);
glEnd();
        ///side-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.935, -.35, 0.0);glVertex3f(-.935, 0.42, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.935, 0.42, 0.0);glVertex3f(-.883, 0.44, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.883, 0.44, 0.0);glVertex3f(-.883, -0.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.935, -.35, 0.0);glVertex3f(-.883, -0.35, 0.0);glEnd();
    ///roof-1
glColor3f(0.1, .35, .5);
glBegin(GL_TRIANGLES);
 glVertex3f(-1, 0.44, 0.0);
 glVertex3f(-.930, 0.55, 0.0);
 glVertex3f(-.935, 0.42, 0.0);
glEnd();
    ///roof-2
glColor3f(0.168, .478, .67);
glBegin(GL_TRIANGLES);
 glVertex3f(-.935, 0.42, 0.0);
 glVertex3f(-.930, 0.55, 0.0);
 glVertex3f(-.883, 0.44, 0.0);
glEnd();

///building-2 width=.182()/height=.285()---------------------------------------------
    ///block-1 ///in the middle of side-2 of b-1=.909
glColor3f(0.5, .55, .5);
glBegin(GL_QUADS);
 glVertex3f(-.909, -.35, 0.0);
 glVertex3f(-.909, .185, 0.0);
 glVertex3f(-.727, 0.185, 0.0);
 glVertex3f(-.727, -0.35, 0.0);
glEnd();
        ///block-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.909, -.35, 0.0);glVertex3f(-.909, .185, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.909, .185, 0.0);glVertex3f(-.727, 0.185, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.727, 0.185, 0.0);glVertex3f(-.727, -0.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.909, -.35, 0.0);glVertex3f(-.727, -0.35, 0.0);glEnd();
    ///block-1 side-1
glColor3f(0.25, .25, .25);
glBegin(GL_QUADS);
 glVertex3f(-.909, -.35, 0.0);
 glVertex3f(-.909, .185, 0.0);
 glVertex3f(-.889, 0.185, 0.0);
 glVertex3f(-.889, -0.35, 0.0);
glEnd();
    ///block-1 side-2
glColor3f(0.25, .25, .25);
glBegin(GL_QUADS);
 glVertex3f(-.707, -.35, 0.0);
 glVertex3f(-.707, .185, 0.0);
 glVertex3f(-.727, 0.185, 0.0);
 glVertex3f(-.727, -0.35, 0.0);
glEnd();
    ///details line-1
glColor3f(.160, .160, .160);
glBegin(GL_LINES);
 glVertex3f(-.909, -0.0905, 0.0);
 glVertex3f(-.727, -0.0905, 0.0);
glEnd();
    ///details line-1
glColor3f(.160, .160, .160);
glBegin(GL_LINES);
 glVertex3f(-.909, -0.0665, 0.0);
 glVertex3f(-.727, -0.0665, 0.0);
glEnd();
    ///details line-2
glColor3f(.160, .160, .160);
glBegin(GL_LINES);
 glVertex3f(-.909, .185, 0.0);
 glVertex3f(-.727, .185, 0.0);
glEnd();
    ///details line-2
glColor3f(.160, .160, .160);
glBegin(GL_LINES);
 glVertex3f(-.909, 0.161, 0.0);
 glVertex3f(-.727, 0.161, 0.0);
glEnd();
    ///block-2 ///in the middle of block-1, center-.818
glColor3f(0.2, .35, .5);
glBegin(GL_QUADS);
 glVertex3f(-.858, .185, 0.0);
 glVertex3f(-.858, .350, 0.0);
 glVertex3f(-.758, .350, 0.0);
 glVertex3f(-.758, .185, 0.0);
glEnd();
        ///block-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.858, .185, 0.0);glVertex3f(-.858, .350, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.858, .350, 0.0);glVertex3f(-.758, .350, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.758, .350, 0.0);glVertex3f(-.758, .185, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.858, .185, 0.0);glVertex3f(-.758, .185, 0.0);glEnd();
    ///block-3 ///in the middle of block-2, center-.808
glColor3f(0.4, .35, .5);
glBegin(GL_QUADS);
 glVertex3f(-.828, .350, 0.0);
 glVertex3f(-.828, .515, 0.0);
 glVertex3f(-.788, .515, 0.0);
 glVertex3f(-.788, .350, 0.0);
glEnd();
        ///block-3-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.828, .350, 0.0);glVertex3f(-.828, .515, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.828, .515, 0.0);glVertex3f(-.788, .515, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.788, .515, 0.0);glVertex3f(-.788, .350, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.828, .350, 0.0);glVertex3f(-.788, .350, 0.0);glEnd();
    ///block-3--roof
glColor3f(0.6, .35, .5);
glBegin(GL_TRIANGLES);
 glVertex3f(-.828, .515, 0.0);
 glVertex3f(-.808, .555, 0.0);
 glVertex3f(-.788, .515, 0.0);
glEnd();
        ///block-3--roof-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.828, .515, 0.0);glVertex3f(-.808, .555, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.808, .555, 0.0);glVertex3f(-.788, .515, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.788, .515, 0.0);glVertex3f(-.828, .515, 0.0);glEnd();

    ///top line-1
glColor3f(.0, .0, .0);
glBegin(GL_LINES);
 glVertex3f(-.808, 0.555, 0.0);
 glVertex3f(-.808, 0.655, 0.0);
glEnd();

///building-3 ,0.027 beside of b-2, width=.15()/height=.()---------------------------------------------
        ///upper-block-2,side-1
glColor3f(0.7, .35, .65);
glBegin(GL_QUADS);
 glVertex3f(-.690, .380, 0.0);
 glVertex3f(-.690, .400, 0.0);
 glVertex3f(-.640, 0.425, 0.0);
 glVertex3f(-.640, 0.400, 0.0);
glEnd();
        ///upper-block-2,side-2
glColor3f(0.9, .55, .65);
glBegin(GL_QUADS);
 glVertex3f(-.640, .400, 0.0);
 glVertex3f(-.640, .425, 0.0);
 glVertex3f(-.570, 0.425, 0.0);
 glVertex3f(-.570, 0.400, 0.0);
glEnd();
    ///lower-block-1,side-1
glColor3f(0.5, .55, .5);
glBegin(GL_QUADS);
 glVertex3f(-.700, -.35, 0.0);
 glVertex3f(-.700, .375, 0.0);
 glVertex3f(-.650, 0.400, 0.0);
 glVertex3f(-.650, -0.35, 0.0);
glEnd();
        ///side-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.700, -.35, 0.0);glVertex3f(-.700, .375, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.700, .375, 0.0);glVertex3f(-.650, 0.400, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, 0.400, 0.0);glVertex3f(-.650, -0.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.700, -.35, 0.0);glVertex3f(-.650, -0.35, 0.0);glEnd();
    ///lower-block-1,side-2
glColor3f(0.1, .75, .65);
glBegin(GL_QUADS);
 glVertex3f(-.650, -.35, 0.0);
 glVertex3f(-.650, .400, 0.0);
 glVertex3f(-.550, 0.400, 0.0);
 glVertex3f(-.550, -0.35, 0.0);
glEnd();
        ///side-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, -.35, 0.0);glVertex3f(-.650, .400, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, .400, 0.0);glVertex3f(-.550, 0.400, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.550, 0.400, 0.0);glVertex3f(-.550, -0.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, -.35, 0.0);glVertex3f(-.550, -0.35, 0.0);glEnd();
///side-2 window
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, .35, 0.0);glVertex3f(-.550, .35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, .32, 0.0);glVertex3f(-.550, .32, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, .29, 0.0);glVertex3f(-.550, .29, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, .26, 0.0);glVertex3f(-.550, .26, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, .23, 0.0);glVertex3f(-.550, .23, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, .2, 0.0);glVertex3f(-.550, .2, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, .17, 0.0);glVertex3f(-.550, .17, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, .14, 0.0);glVertex3f(-.550, .14, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, .11, 0.0);glVertex3f(-.550, .11, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, .08, 0.0);glVertex3f(-.550, .08, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, .05, 0.0);glVertex3f(-.550, .05, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, .02, 0.0);glVertex3f(-.550, .02, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, -.01, 0.0);glVertex3f(-.550, -.01, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, -.04, 0.0);glVertex3f(-.550, -.04, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, -.07, 0.0);glVertex3f(-.550, -.07, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, -.10, 0.0);glVertex3f(-.550, -.10, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, -.13, 0.0);glVertex3f(-.550, -.13, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, -.16, 0.0);glVertex3f(-.550, -.16, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, -.19, 0.0);glVertex3f(-.550, -.19, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, -.22, 0.0);glVertex3f(-.550, -.22, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, -.25, 0.0);glVertex3f(-.550, -.25, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, -.28, 0.0);glVertex3f(-.550, -.28, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.650, -.31, 0.0);glVertex3f(-.550, -.31, 0.0);glEnd();

///window_func
glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(-.620, .23, 0.0);
     glVertex3f(-.620, .26, 0.0);
     glVertex3f(-.600, .26, 0.0);
     glVertex3f(-.600, 0.23, 0.0);
    glEnd();

glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(-.585, -.07, 0.0);
     glVertex3f(-.585, -.04, 0.0);
     glVertex3f(-.565, -.04, 0.0);
     glVertex3f(-.565, -.07, 0.0);
    glEnd();



///building-4 ,0.05 beside of b-3, width=.()/height=.()---------------------------------------------
        ///block-1
glColor3f(0.9, .55, .65);
glBegin(GL_QUADS);
 glVertex3f(-.51, -.35, 0.0);
 glVertex3f(-.495, .300, 0.0);
 glVertex3f(-.435, 0.300, 0.0);
 glVertex3f(-.420, -.35, 0.0);
glEnd();
        ///side-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.51, -.35, 0.0);glVertex3f(-.495, .300, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.495, .300, 0.0);glVertex3f(-.435, 0.300, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.435, 0.300, 0.0);glVertex3f(-.420, -.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.51, -.35, 0.0);glVertex3f(-.420, -.35, 0.0);glEnd();
        ///in_between-1
glColor3f(0.5, .55, .5);
glBegin(GL_QUADS);
 glVertex3f(-.495, .300, 0.0);
 glVertex3f(-.505, .320, 0.0);
 glVertex3f(-.425, .320, 0.0);
 glVertex3f(-.435, .300, 0.0);
glEnd();
        ///inBetween-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.495, .300, 0.0);glVertex3f(-.505, .320, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.505, .320, 0.0);glVertex3f(-.425, .320, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.425, .320, 0.0);glVertex3f(-.435, .300, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.495, .300, 0.0);glVertex3f(-.435, .300, 0.0);glEnd();
        ///in_between-2
glColor3f(0.1, .75, .65);
glBegin(GL_QUADS);
 glVertex3f(-.490, .320, 0.0);
 glVertex3f(-.500, .340, 0.0);
 glVertex3f(-.430, .340, 0.0);
 glVertex3f(-.440, .320, 0.0);
glEnd();
        ///inBetween-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.490, .320, 0.0);glVertex3f(-.500, .340, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.500, .340, 0.0);glVertex3f(-.430, .340, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.430, .340, 0.0);glVertex3f(-.440, .320, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.490, .320, 0.0);glVertex3f(-.440, .320, 0.0);glEnd();
        ///block-2
glColor3f(0.9, .55, .65);
glBegin(GL_QUADS);
 glVertex3f(-.480, .340, 0.0);
 glVertex3f(-.480, .455, 0.0);
 glVertex3f(-.450, 0.455, 0.0);
 glVertex3f(-.450, .340, 0.0);
glEnd();
        ///side-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.480, .340, 0.0);glVertex3f(-.480, .455, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.480, .455, 0.0);glVertex3f(-.450, 0.455, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.450, 0.455, 0.0);glVertex3f(-.450, .340, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.480, .340, 0.0);glVertex3f(-.450, .340, 0.0);glEnd();
        ///in_between-3
glColor3f(0.5, .55, .5);
glBegin(GL_QUADS);
 glVertex3f(-.480, .455, 0.0);
 glVertex3f(-.490, .470, 0.0);
 glVertex3f(-.440, .470, 0.0);
 glVertex3f(-.450, .455, 0.0);
glEnd();
        ///inBetween-3-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.480, .455, 0.0);glVertex3f(-.490, .470, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.490, .470, 0.0);glVertex3f(-.440, .470, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.440, .470, 0.0);glVertex3f(-.450, .455, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.480, .455, 0.0);glVertex3f(-.450, .455, 0.0);glEnd();
        ///block-3
glColor3f(0.6, .25, .65);
glBegin(GL_QUADS);
 glVertex3f(-.475, .470, 0.0);
 glVertex3f(-.475, .535, 0.0);
 glVertex3f(-.455, 0.535, 0.0);
 glVertex3f(-.455, .470, 0.0);
glEnd();
        ///side-3-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.475, .470, 0.0);glVertex3f(-.475, .535, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.475, .535, 0.0);glVertex3f(-.455, 0.535, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.455, 0.535, 0.0);glVertex3f(-.455, .470, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.475, .470, 0.0);glVertex3f(-.455, .470, 0.0);glEnd();
        ///block-4
glColor3f(0.2, .85, .25);
glBegin(GL_QUADS);
 glVertex3f(-.470, .535, 0.0);
 glVertex3f(-.470, .625, 0.0);
 glVertex3f(-.460, 0.625, 0.0);
 glVertex3f(-.460, .535, 0.0);
glEnd();
        ///side-4-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.470, .535, 0.0);glVertex3f(-.470, .625, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.470, .625, 0.0);glVertex3f(-.460, 0.625, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.460, 0.625, 0.0);glVertex3f(-.460, .535, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.470, .535, 0.0);glVertex3f(-.460, .535, 0.0);glEnd();
    ///top line-1
glColor3f(.0, .0, .0);
glBegin(GL_LINES);
 glVertex3f(-.465, 0.625, 0.0);
 glVertex3f(-.465, 0.700, 0.0);
glEnd();

///building-5 ,0.03 beside of b-4(-.420), width=.()/height=.()---------------------------------------------
        ///upper-side-1
glColor3f(0.5, .55, .5);
glBegin(GL_QUADS);
 glVertex3f(-.390, -.10, 0.0);
 glVertex3f(-.390, .02, 0.0);
 glVertex3f(-.345, 0.03, 0.0);
 glVertex3f(-.345, -.10, 0.0);
glEnd();
        ///us-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.390, -.10, 0.0);glVertex3f(-.390, .02, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.390, .02, 0.0);glVertex3f(-.345, 0.03, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.345, 0.03, 0.0);glVertex3f(-.345, -.10, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.390, -.10, 0.0);glVertex3f(-.345, -.10, 0.0);glEnd();
        ///upper-side-2
glColor3f(0.5, .15, .25);
glBegin(GL_QUADS);
 glVertex3f(-.345, -.10, 0.0);
 glVertex3f(-.345, .03, 0.0);
 glVertex3f(-.310, 0.02, 0.0);
 glVertex3f(-.310, -.10, 0.0);
glEnd();
        ///us-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.345, -.10, 0.0);glVertex3f(-.345, .03, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.345, .03, 0.0);glVertex3f(-.310, 0.02, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.310, 0.02, 0.0);glVertex3f(-.310, -.10, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.345, -.10, 0.0);glVertex3f(-.310, -.10, 0.0);glEnd();

        ///upper-side-3
glColor3f(0.4, .55, .5);
glBegin(GL_QUADS);
 glVertex3f(-.270, .03, 0.0);
 glVertex3f(-.270, .12, 0.0);
 glVertex3f(-.230, 0.12, 0.0);
 glVertex3f(-.230, .03, 0.0);
glEnd();
        ///us-3-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.270, .03, 0.0);glVertex3f(-.270, .12, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.270, .12, 0.0);glVertex3f(-.230, 0.12, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.230, 0.12, 0.0);glVertex3f(-.230, .03, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.270, .03, 0.0);glVertex3f(-.230, .03, 0.0);glEnd();
        ///upper-side-4
glColor3f(0.94, 45, .95);
glBegin(GL_QUADS);
 glVertex3f(-.230, .03, 0.0);
 glVertex3f(-.230, .12, 0.0);
 glVertex3f(-.210, 0.11, 0.0);
 glVertex3f(-.210, .03, 0.0);
glEnd();
        ///us-4-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.230, .03, 0.0);glVertex3f(-.230, .12, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.230, .12, 0.0);glVertex3f(-.210, 0.11, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.210, 0.11, 0.0);glVertex3f(-.210, .03, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.230, .03, 0.0);glVertex3f(-.210, .03, 0.0);glEnd();
        ///upper-triangle-1
glColor3f(0.168, .478, .67);
glBegin(GL_TRIANGLES);
 glVertex3f(-.270, .12, 0.0);
 glVertex3f(-.235, .15, 0.0);
 glVertex3f(-.230, 0.12, 0.0);
glEnd();
        ///ut-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.270, .12, 0.0);glVertex3f(-.235, .15, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.235, .15, 0.0);glVertex3f(-.230, 0.12, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.230, 0.12, 0.0);glVertex3f(-.270, .12, 0.0);glEnd();
        ///upper-triangle-2
glColor3f(0.1, .35, .5);
glBegin(GL_TRIANGLES);
 glVertex3f(-.230, .12, 0.0);
 glVertex3f(-.235, .15, 0.0);
 glVertex3f(-.210, 0.11, 0.0);
glEnd();
        ///ut-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.230, .12, 0.0);glVertex3f(-.235, .15, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.235, .15, 0.0);glVertex3f(-.210, 0.11, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.210, 0.11, 0.0);glVertex3f(-.230, .12, 0.0);glEnd();

        ///lower-side-1
glColor3f(0.1, .75, .65);
glBegin(GL_QUADS);
 glVertex3f(-.390, -.35, 0.0);
 glVertex3f(-.390, -.10, 0.0);
 glVertex3f(-.300, -0.07, 0.0);
 glVertex3f(-.300, -.35, 0.0);
glEnd();
        ///ls-4-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.390, -.35, 0.0);glVertex3f(-.390, -.10, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.390, -.10, 0.0);glVertex3f(-.300, -0.07, 0.0);glEnd();
        ///lower-side-2
glColor3f(0.3, .75, .65);
glBegin(GL_QUADS);
 glVertex3f(-.300, -.35, 0.0);
 glVertex3f(-.300, .03, 0.0);
 glVertex3f(-.230, 0.06, 0.0);
 glVertex3f(-.230, -.35, 0.0);
glEnd();
        ///ls-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.300, -0.07, 0.0);glVertex3f(-.300, .03, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.300, .03, 0.0);glVertex3f(-.230, 0.06, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.230, 0.06, 0.0);glVertex3f(-.230, -.35, 0.0);glEnd();
        ///lower-side-3
glColor3f(0.2, .85, .25);
glBegin(GL_QUADS);
 glVertex3f(-.230, -.35, 0.0);
 glVertex3f(-.230, .06, 0.0);
 glVertex3f(-.210, .06, 0.0);
 glVertex3f(-.210, -.35, 0.0);
glEnd();
        ///ls-3-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.230, -.35, 0.0);glVertex3f(-.230, .06, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.230, .06, 0.0);glVertex3f(-.210, .06, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.210, .06, 0.0);glVertex3f(-.210, -.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.230, -.35, 0.0);glVertex3f(-.210, -.35, 0.0);glEnd();

///-------------in_between building-----------------
///building-7 , width=.()/height=.()---------------------------------------------
        ///side-1
glColor3f(0.2, .55, .35);
glBegin(GL_QUADS);
 glVertex3f(-.120, -.35, 0.0);
 glVertex3f(-.120, .50, 0.0);
 glVertex3f(.08, 0.50, 0.0);
 glVertex3f(.08, -.35, 0.0);
glEnd();
        ///s-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, -.35, 0.0);glVertex3f(-.120, .50, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, .50, 0.0);glVertex3f(.08, 0.50, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.08, 0.50, 0.0);glVertex3f(.08, -.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, -.35, 0.0);glVertex3f(.08, -.35, 0.0);glEnd();

///side-1 window
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, .45, 0.0);glVertex3f(.08, .45, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, .40, 0.0);glVertex3f(.08, .40, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, .35, 0.0);glVertex3f(.08, .35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, .30, 0.0);glVertex3f(.08, .30, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, .25, 0.0);glVertex3f(.08, .25, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, .20, 0.0);glVertex3f(.08, .20, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, .15, 0.0);glVertex3f(.08, .15, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, .10, 0.0);glVertex3f(.08, .10, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, .05, 0.0);glVertex3f(.08, .05, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, .0, 0.0);glVertex3f(.08, .0, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, -.05, 0.0);glVertex3f(.08, -.05, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, -.10, 0.0);glVertex3f(.08, -.10, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, -.15, 0.0);glVertex3f(.08, -.15, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, -.20, 0.0);glVertex3f(.08, -.20, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, -.25, 0.0);glVertex3f(.08, -.25, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.120, -.30, 0.0);glVertex3f(.08, -.30, 0.0);glEnd();

///-------------------------------------------------

///building-6 , width=.()/height=.()---------------------------------------------
        ///side-1
glColor3f(0.5, .55, .5);
glBegin(GL_QUADS);
 glVertex3f(-.210, -.35, 0.0);
 glVertex3f(-.210, .32, 0.0);
 glVertex3f(-.170, 0.33, 0.0);
 glVertex3f(-.170, -.35, 0.0);
glEnd();
        ///side-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.210, -.35, 0.0);glVertex3f(-.210, .32, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.210, .32, 0.0);glVertex3f(-.170, 0.33, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, 0.33, 0.0);glVertex3f(-.170, -.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.210, -.35, 0.0);glVertex3f(-.170, -.35, 0.0);glEnd();
    ///side-2
glColor3f(0.7, .75, .65);
glBegin(GL_QUADS);
 glVertex3f(-.170, -.35, 0.0);
 glVertex3f(-.170, .33, 0.0);
 glVertex3f(-.050, .33, 0.0);
 glVertex3f(-.050, -0.35, 0.0);
glEnd();
        ///side-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, -.35, 0.0);glVertex3f(-.170, .33, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, .33, 0.0);glVertex3f(-.050, .33, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.050, .33, 0.0);glVertex3f(-.050, -0.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, -.35, 0.0);glVertex3f(-.050, -0.35, 0.0);glEnd();

        ///side-2-Window
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, .29, 0.0);glVertex3f(-.050, .29, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, .26, 0.0);glVertex3f(-.050, .26, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, .23, 0.0);glVertex3f(-.050, .23, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, .2, 0.0);glVertex3f(-.050, .2, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, .17, 0.0);glVertex3f(-.050, .17, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, .14, 0.0);glVertex3f(-.050, .14, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, .11, 0.0);glVertex3f(-.050, .11, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, .08, 0.0);glVertex3f(-.050, .08, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, .05, 0.0);glVertex3f(-.050, .05, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, .02, 0.0);glVertex3f(-.050, .02, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, -.01, 0.0);glVertex3f(-.050, -.01, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, -.04, 0.0);glVertex3f(-.050, -.04, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, -.07, 0.0);glVertex3f(-.050, -.07, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, -.10, 0.0);glVertex3f(-.050, -.10, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, -.13, 0.0);glVertex3f(-.050, -.13, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, -.16, 0.0);glVertex3f(-.050, -.16, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, -.19, 0.0);glVertex3f(-.050, -.19, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, -.22, 0.0);glVertex3f(-.050, -.22, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, -.25, 0.0);glVertex3f(-.050, -.25, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, -.28, 0.0);glVertex3f(-.050, -.28, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.170, -.31, 0.0);glVertex3f(-.050, -.31, 0.0);glEnd();

///windows_func
glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(-.150, -.16, 0.0);
     glVertex3f(-.150, -.13, 0.0);
     glVertex3f(-.130, -.13, 0.0);
     glVertex3f(-.130, -.16, 0.0);
    glEnd();

///-------------in_between building-----------------
///building-9 , width=.()/height=.()---------------------------------------------
        ///lower-side-1
glColor3f(0.2, .55, .35);
glBegin(GL_QUADS);
 glVertex3f(.200, -.35, 0.0);
 glVertex3f(.200, .19, 0.0);
 glVertex3f(.235, 0.20, 0.0);
 glVertex3f(.235, -.35, 0.0);
glEnd();
        ///ls-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.200, -.35, 0.0);glVertex3f(.200, .19, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.200, .19, 0.0);glVertex3f(.235, 0.20, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, 0.20, 0.0);glVertex3f(.235, -.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.200, -.35, 0.0);glVertex3f(.235, -.35, 0.0);glEnd();
        ///lower-side-2
glColor3f(0.5, .75, .35);
glBegin(GL_QUADS);
 glVertex3f(.235, -.35, 0.0);
 glVertex3f(.235, .20, 0.0);
 glVertex3f(.500, 0.20, 0.0);
 glVertex3f(.500, -.35, 0.0);
glEnd();
///l-side-2 window
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, .17, 0.0);glVertex3f(.500, .17, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, .14, 0.0);glVertex3f(.500, .14, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, .11, 0.0);glVertex3f(.500, .11, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, .08, 0.0);glVertex3f(.500, .08, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, .05, 0.0);glVertex3f(.500, .05, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, .02, 0.0);glVertex3f(.500, .02, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, -.01, 0.0);glVertex3f(.500, -.01, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, -.04, 0.0);glVertex3f(.500, -.04, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, -.07, 0.0);glVertex3f(.500, -.07, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, -.10, 0.0);glVertex3f(.500, -.10, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, -.13, 0.0);glVertex3f(.500, -.13, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, -.16, 0.0);glVertex3f(.500, -.16, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, -.19, 0.0);glVertex3f(.500, -.19, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, -.22, 0.0);glVertex3f(.500, -.22, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, -.25, 0.0);glVertex3f(.500, -.25, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, -.28, 0.0);glVertex3f(.500, -.28, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, -.31, 0.0);glVertex3f(.500, -.31, 0.0);glEnd();


        ///ls-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, -.35, 0.0);glVertex3f(.235, .20, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, .20, 0.0);glVertex3f(.500, 0.20, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.500, 0.20, 0.0);glVertex3f(.500, -.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.235, -.35, 0.0);glVertex3f(.500, -.35, 0.0);glEnd();
        ///upper-side-1
glColor3f(0.35, .25, .35);
glBegin(GL_QUADS);
 glVertex3f(.265, .20, 0.0);
 glVertex3f(.265, .36, 0.0);
 glVertex3f(.295, .38, 0.0);
 glVertex3f(.295, .20, 0.0);
glEnd();
        ///us-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.265, .20, 0.0);glVertex3f(.265, .36, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.265, .36, 0.0);glVertex3f(.295, .38, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.295, .38, 0.0);glVertex3f(.295, .20, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.265, .20, 0.0);glVertex3f(.295, .20, 0.0);glEnd();
        ///upper-side-2
glColor3f(0.85, .25, .35);
glBegin(GL_QUADS);
 glVertex3f(.295, .20, 0.0);
 glVertex3f(.295, .38, 0.0);
 glVertex3f(.415, .38, 0.0);
 glVertex3f(.415, .20, 0.0);
glEnd();
        ///us-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.295, .20, 0.0);glVertex3f(.295, .38, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.295, .38, 0.0);glVertex3f(.415, .38, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.415, .38, 0.0);glVertex3f(.415, .20, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.295, .20, 0.0);glVertex3f(.415, .20, 0.0);glEnd();
        ///upper-upper-side-1
glColor3f(0.45, .525, .835);
glBegin(GL_QUADS);
 glVertex3f(.315, .38, 0.0);
 glVertex3f(.315, .40, 0.0);
 glVertex3f(.325, .41, 0.0);
 glVertex3f(.325, .38, 0.0);
glEnd();
        ///uus-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.315, .38, 0.0);glVertex3f(.315, .40, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.315, .40, 0.0);glVertex3f(.325, .41, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.325, .41, 0.0);glVertex3f(.325, .38, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.315, .38, 0.0);glVertex3f(.325, .38, 0.0);glEnd();
        ///upper-upper-side-2
glColor3f(0.75, .525, .35);
glBegin(GL_QUADS);
 glVertex3f(.325, .38, 0.0);
 glVertex3f(.325, .41, 0.0);
 glVertex3f(.385, .41, 0.0);
 glVertex3f(.385, .38, 0.0);
glEnd();
        ///uus-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.325, .38, 0.0);glVertex3f(.325, .41, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.325, .41, 0.0);glVertex3f(.385, .41, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.385, .41, 0.0);glVertex3f(.385, .38, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.325, .38, 0.0);glVertex3f(.385, .38, 0.0);glEnd();
///-------------------------------------------------

///building-8 ,0.05 beside of b-6 width=.()/height=.()---------------------------------------------
         ///upper-side-1
glColor3f(0.5, .55, .5);
glBegin(GL_QUADS);
 glVertex3f(.02, .08, 0.0);
 glVertex3f(.02, .185, 0.0);
 glVertex3f(.090, 0.17, 0.0);
 glVertex3f(.090, .08, 0.0);
glEnd();
        ///us-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.02, .08, 0.0);glVertex3f(.02, .185, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.02, .185, 0.0);glVertex3f(.090, 0.17, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.090, 0.17, 0.0);glVertex3f(.090, .08, 0.0);glEnd();
         ///upper-side-2
glColor3f(0.7, .75, .65);
glBegin(GL_QUADS);
 glVertex3f(.090, .08, 0.0);
 glVertex3f(.090, .17, 0.0);
 glVertex3f(.220, 0.17, 0.0);
 glVertex3f(.220, .08, 0.0);
glEnd();
        ///us-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.090, .08, 0.0);glVertex3f(.090, .17, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.090, .17, 0.0);glVertex3f(.220, 0.17, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.220, 0.17, 0.0);glVertex3f(.220, .08, 0.0);glEnd();

    ///roof-1
glColor3f(0.168, .478, .67);
glBegin(GL_TRIANGLES);
 glVertex3f(.02, .185, 0.0);
 glVertex3f(.140, 0.23, 0.0);
 glVertex3f(.090, 0.17, 0.0);
glEnd();
        ///r-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.02, .185, 0.0);glVertex3f(.140, 0.23, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.140, 0.23, 0.0);glVertex3f(.090, 0.17, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.090, 0.17, 0.0);glVertex3f(.02, .185, 0.0);glEnd();
    ///roof-2
glColor3f(0.1, .35, .5);
glBegin(GL_TRIANGLES);
 glVertex3f(.090, .17, 0.0);
 glVertex3f(.140, 0.23, 0.0);
 glVertex3f(.220, 0.17, 0.0);
glEnd();
        ///r-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.090, .17, 0.0);glVertex3f(.140, 0.23, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.140, 0.23, 0.0);glVertex3f(.220, 0.17, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.220, 0.17, 0.0);glVertex3f(.090, .17, 0.0);glEnd();

        ///lower-side-1
glColor3f(0.329, .447, .761);
glBegin(GL_QUADS);
 glVertex3f(-.020, -.35, 0.0);
 glVertex3f(-.020, .10, 0.0);
 glVertex3f(.070, 0.08, 0.0);
 glVertex3f(.070, -.35, 0.0);
glEnd();
        ///ls-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.020, -.35, 0.0);glVertex3f(-.020, .10, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.020, .10, 0.0);glVertex3f(.070, 0.08, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.070, 0.08, 0.0);glVertex3f(.070, -.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(-.020, -.35, 0.0);glVertex3f(.070, -.35, 0.0);glEnd();
        ///lower-side-2
glColor3f(0.59, .447, .761);
glBegin(GL_QUADS);
 glVertex3f(.070, -.35, 0.0);
 glVertex3f(.070, .08, 0.0);
 glVertex3f(.250, 0.08, 0.0);
 glVertex3f(.250, -.35, 0.0);
glEnd();

///window


glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(.150, -.01, 0.0);
     glVertex3f(.150, .02, 0.0);
     glVertex3f(.175, .02, 0.0);
     glVertex3f(.175, -0.01, 0.0);
    glEnd();

glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(.205, -.01, 0.0);
     glVertex3f(.205, .02, 0.0);
     glVertex3f(.230, .02, 0.0);
     glVertex3f(.230, -0.01, 0.0);
    glEnd();

///1
glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(.090, -.04, 0.0);
     glVertex3f(.090, -.07, 0.0);
     glVertex3f(.115, -.07, 0.0);
     glVertex3f(.115, -0.04, 0.0);
    glEnd();

glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(.150, -.04, 0.0);
     glVertex3f(.150, -.07, 0.0);
     glVertex3f(.175, -.07, 0.0);
     glVertex3f(.175, -0.04, 0.0);
    glEnd();



    ///2


glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(.150, -.10, 0.0);
     glVertex3f(.150, -.13, 0.0);
     glVertex3f(.175, -.13, 0.0);
     glVertex3f(.175, -0.10, 0.0);
    glEnd();

glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(.205, -.10, 0.0);
     glVertex3f(.205, -.13, 0.0);
     glVertex3f(.230, -.13, 0.0);
     glVertex3f(.230, -0.10, 0.0);
    glEnd();


    ///3
glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(.090, -.16, 0.0);
     glVertex3f(.090, -.19, 0.0);
     glVertex3f(.115, -.19, 0.0);
     glVertex3f(.115, -0.16, 0.0);
    glEnd();

glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(.150, -.16, 0.0);
     glVertex3f(.150, -.19, 0.0);
     glVertex3f(.175, -.19, 0.0);
     glVertex3f(.175, -0.16, 0.0);
    glEnd();

glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(.205, -.16, 0.0);
     glVertex3f(.205, -.19, 0.0);
     glVertex3f(.230, -.19, 0.0);
     glVertex3f(.230, -0.16, 0.0);
    glEnd();

///4
glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(.090, -.22, 0.0);
     glVertex3f(.090, -.25, 0.0);
     glVertex3f(.115, -.25, 0.0);
     glVertex3f(.115, -0.22, 0.0);
    glEnd();


glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(.205, -.22, 0.0);
     glVertex3f(.205, -.25, 0.0);
     glVertex3f(.230, -.25, 0.0);
     glVertex3f(.230, -0.22, 0.0);
    glEnd();

///5
glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(.090, -.28, 0.0);
     glVertex3f(.090, -.31, 0.0);
     glVertex3f(.115, -.31, 0.0);
     glVertex3f(.115, -0.28, 0.0);
    glEnd();

glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
     glVertex3f(.150, -.28, 0.0);
     glVertex3f(.150, -.31, 0.0);
     glVertex3f(.175, -.31, 0.0);
     glVertex3f(.175, -0.28, 0.0);
    glEnd();



        ///ls-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.070, -.35, 0.0);glVertex3f(.070, .08, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.070, .08, 0.0);glVertex3f(.250, 0.08, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.250, 0.08, 0.0);glVertex3f(.250, -.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.070, -.35, 0.0);glVertex3f(.250, -.35, 0.0);glEnd();

///building-10 ,<beside b-9> width=.()/height=.()---------------------------------------------
    ///top line-1
glColor3f(.0, .0, .0);
glBegin(GL_LINES);
 glVertex3f(.589, 0.395, 0.0);
 glVertex3f(.589, 0.435, 0.0);
glEnd();
    ///roof-1
glColor3f(0.1, .35, .5);
glBegin(GL_TRIANGLES);
 glVertex3f(.565, .360, 0.0);
 glVertex3f(.589, 0.395, 0.0);
 glVertex3f(.595, .355, 0.0);
glEnd();
        ///r-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.565, .360, 0.0);glVertex3f(.589, 0.395, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.589, 0.395, 0.0);glVertex3f(.595, .355, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.595, .355, 0.0);glVertex3f(.565, .360, 0.0);glEnd();
    ///roof-2
glColor3f(0.168, .478, .67);
glBegin(GL_TRIANGLES);
 glVertex3f(.595, .355, 0.0);
 glVertex3f(.589, 0.395, 0.0);
 glVertex3f(.605, 0.360, 0.0);
glEnd();
        ///r-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.595, .355, 0.0);glVertex3f(.589, 0.395, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.589, 0.395, 0.0);glVertex3f(.605, 0.360, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.605, 0.360, 0.0);glVertex3f(.595, .355, 0.0);glEnd();
           ///top-1
glColor3f(.628, .203, .549);
glBegin(GL_QUADS);
 glVertex3f(.565, .275, 0.0);
 glVertex3f(.565, .360, 0.0);
 glVertex3f(.595, .355, 0.0);
 glVertex3f(.595, .275, 0.0);
glEnd();
        ///t-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.565, .275, 0.0);glVertex3f(.565, .360, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.565, .360, 0.0);glVertex3f(.595, .355, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.595, .355, 0.0);glVertex3f(.595, .275, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.565, .275, 0.0);glVertex3f(.595, .275, 0.0);glEnd();
          ///top-2
glColor3f(.568, .403, .533);
glBegin(GL_QUADS);
 glVertex3f(.595, .275, 0.0);
 glVertex3f(.595, .355, 0.0);
 glVertex3f(.605, 0.360, 0.0);
 glVertex3f(.605, .275, 0.0);
glEnd();
        ///t-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.595, .275, 0.0);glVertex3f(.595, .355, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.595, .355, 0.0);glVertex3f(.605, 0.360, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.605, 0.360, 0.0);glVertex3f(.605, .275, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.595, .275, 0.0);glVertex3f(.605, .275, 0.0);glEnd();

           ///upper-middle-side-1
glColor3f(.228, .223, .249);
glBegin(GL_QUADS);
 glVertex3f(.555, .26, 0.0);
 glVertex3f(.555, .275, 0.0);
 glVertex3f(.595, 0.275, 0.0);
 glVertex3f(.595, .26, 0.0);
glEnd();
          ///upper-middle-side-2
glColor3f(.228, .223, .249);
glBegin(GL_QUADS);
 glVertex3f(.595, .26, 0.0);
 glVertex3f(.595, .275, 0.0);
 glVertex3f(.615, 0.280, 0.0);
 glVertex3f(.615, .26, 0.0);
glEnd();
           ///upper-side-1
glColor3f(.628, .203, .549);
glBegin(GL_QUADS);
 glVertex3f(.515, .12, 0.0);
 glVertex3f(.555, .26, 0.0);
 glVertex3f(.595, 0.26, 0.0);
 glVertex3f(.610, .12, 0.0);
glEnd();
        ///us-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.515, .12, 0.0);glVertex3f(.555, .26, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.555, .26, 0.0);glVertex3f(.595, 0.26, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.595, 0.26, 0.0);glVertex3f(.610, .12, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.515, .12, 0.0);glVertex3f(.610, .12, 0.0);glEnd();
          ///upper-side-2
glColor3f(.568, .403, .533);
glBegin(GL_QUADS);
 glVertex3f(.610, .12, 0.0);
 glVertex3f(.595, .26, 0.0);
 glVertex3f(.615, 0.265, 0.0);
 glVertex3f(.665, .12, 0.0);
glEnd();
        ///us-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.610, .12, 0.0);glVertex3f(.595, .26, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.595, .26, 0.0);glVertex3f(.615, 0.265, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.615, 0.265, 0.0);glVertex3f(.665, .12, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.610, .12, 0.0);glVertex3f(.665, .12, 0.0);glEnd();

          ///middle-middle-side-1
glColor3f(.305, .392, .509);
glBegin(GL_QUADS);
 glVertex3f(.515, .11, 0.0);
 glVertex3f(.515, .13, 0.0);
 glVertex3f(.610, 0.12, 0.0);
 glVertex3f(.610, .11, 0.0);
glEnd();
          ///middle-middle-side-2
glColor3f(.164, .380, .678);
glBegin(GL_QUADS);
 glVertex3f(.610, .11, 0.0);
 glVertex3f(.610, .12, 0.0);
 glVertex3f(.665, 0.13, 0.0);
 glVertex3f(.665, .11, 0.0);
glEnd();

          ///middle-side-1
glColor3f(.749, .667, .733);
glBegin(GL_QUADS);
 glVertex3f(.515, .02, 0.0);
 glVertex3f(.515, .12, 0.0);
 glVertex3f(.610, 0.11, 0.0);
 glVertex3f(.610, .02, 0.0);
glEnd();
        ///ms-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.515, .02, 0.0);glVertex3f(.515, .12, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.515, .12, 0.0);glVertex3f(.610, 0.11, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.610, 0.11, 0.0);glVertex3f(.610, .02, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.515, .02, 0.0);glVertex3f(.610, .02, 0.0);glEnd();

          ///middle-side-2
glColor3f(.28, .203, .549);
glBegin(GL_QUADS);
 glVertex3f(.610, .02, 0.0);
 glVertex3f(.610, .11, 0.0);
 glVertex3f(.665, 0.12, 0.0);
 glVertex3f(.665, .02, 0.0);
glEnd();
        ///ms-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.610, .02, 0.0);glVertex3f(.610, .11, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.610, .11, 0.0);glVertex3f(.665, 0.12, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.665, 0.12, 0.0);glVertex3f(.665, .02, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.610, .02, 0.0);glVertex3f(.665, .02, 0.0);glEnd();


         ///lower-side-1
glColor3f(.568, .263, .502);
glBegin(GL_QUADS);
 glVertex3f(.500, -.35, 0.0);
 glVertex3f(.500, .03, 0.0);
 glVertex3f(.610, 0.02, 0.0);
 glVertex3f(.610, -.35, 0.0);
glEnd();
        ///ls-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.500, -.35, 0.0);glVertex3f(.500, .03, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.500, .03, 0.0);glVertex3f(.610, 0.02, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.610, 0.02, 0.0);glVertex3f(.610, -.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.500, -.35, 0.0);glVertex3f(.610, -.35, 0.0);glEnd();
         ///lower-side-2
glColor3f(.568, .403, .533);
glBegin(GL_QUADS);
 glVertex3f(.610, -.35, 0.0);
 glVertex3f(.610, .02, 0.0);
 glVertex3f(.680, 0.03, 0.0);
 glVertex3f(.680, -.35, 0.0);
glEnd();
        ///ls-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.610, -.35, 0.0);glVertex3f(.610, .02, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.610, .02, 0.0);glVertex3f(.680, 0.03, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.680, 0.03, 0.0);glVertex3f(.680, -.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.610, -.35, 0.0);glVertex3f(.680, -.35, 0.0);glEnd();

///-------------in_between building-----------------
///building-12 , width=.()/height=.()---------------------------------------------
    ///top-1
glColor3f(0.1, .35, .5);
glBegin(GL_QUADS);
 glVertex3f(.840, .30, 0.0);
 glVertex3f(.840, .35, 0.0);
 glVertex3f(.890, .35, 0.0);
 glVertex3f(.890, .30, 0.0);
glEnd();
    ///top-2
glColor3f(0.9, .35, .5);
glBegin(GL_QUADS);
 glVertex3f(.890, .30, 0.0);
 glVertex3f(.890, .35, 0.0);
 glVertex3f(.945, .33, 0.0);
 glVertex3f(.945, .30, 0.0);
glEnd();
    ///side-1
glColor3f(0.1, .75, .65);
glBegin(GL_QUADS);
 glVertex3f(.800, -.35, 0.0);
 glVertex3f(.800, .30, 0.0);
 glVertex3f(.930, .31, 0.0);
 glVertex3f(.930, -0.35, 0.0);
glEnd();
        ///side-1-border
glColor3f(0.054, .388, .337);glBegin(GL_LINES);glVertex3f(.800, -.35, 0.0);glVertex3f(.800, .30, 0.0);glEnd();
glColor3f(0.054, .388, .337);glBegin(GL_LINES);glVertex3f(.800, .30, 0.0);glVertex3f(.930, .31, 0.0);glEnd();
glColor3f(0.054, .388, .337);glBegin(GL_LINES);glVertex3f(.930, .31, 0.0);glVertex3f(.930, -0.35, 0.0);glEnd();
glColor3f(.054, .388, .337);glBegin(GL_LINES);glVertex3f(.800, -.35, 0.0);glVertex3f(.930, -0.35, 0.0);glEnd();
        ///side-2
glColor3f(0.5, .55, .5);
glBegin(GL_QUADS);
 glVertex3f(.930, -.35, 0.0);
 glVertex3f(.930, .31, 0.0);
 glVertex3f(1, 0.29, 0.0);
 glVertex3f(1, -.35, 0.0);
glEnd();
        ///side-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.930, -.35, 0.0);glVertex3f(.930, .31, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.930, .31, 0.0);glVertex3f(1, 0.29, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(1, 0.29, 0.0);glVertex3f(1, -.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.930, -.35, 0.0);glVertex3f(1, -.35, 0.0);glEnd();


///-------------------------------------------------

///building-11 , width=.()/height=.()---------------------------------------------
    ///side-1
glColor3f(0.7, .75, .65);
glBegin(GL_QUADS);
 glVertex3f(.685, -.35, 0.0);
 glVertex3f(.685, .21, 0.0);
 glVertex3f(.775, .22, 0.0);
 glVertex3f(.775, -0.35, 0.0);
glEnd();

///side-1 window
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, .17, 0.0);glVertex3f(.775, .17, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, .14, 0.0);glVertex3f(.775, .14, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, .11, 0.0);glVertex3f(.775, .11, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, .08, 0.0);glVertex3f(.775, .08, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, .05, 0.0);glVertex3f(.775, .05, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, .02, 0.0);glVertex3f(.775, .02, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, -.01, 0.0);glVertex3f(.775, -.01, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, -.04, 0.0);glVertex3f(.775, -.04, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, -.07, 0.0);glVertex3f(.775, -.07, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, -.10, 0.0);glVertex3f(.775, -.10, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, -.13, 0.0);glVertex3f(.775, -.13, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, -.16, 0.0);glVertex3f(.775, -.16, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, -.19, 0.0);glVertex3f(.775, -.19, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, -.22, 0.0);glVertex3f(.775, -.22, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, -.25, 0.0);glVertex3f(.775, -.25, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, -.28, 0.0);glVertex3f(.775, -.28, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, -.31, 0.0);glVertex3f(.775, -.31, 0.0);glEnd();

        ///side-1-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, -.35, 0.0);glVertex3f(.685, .21, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, .21, 0.0);glVertex3f(.775, .22, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.775, .22, 0.0);glVertex3f(.775, -0.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.685, -.35, 0.0);glVertex3f(.775, -0.35, 0.0);glEnd();


        ///side-2
glColor3f(0.5, .55, .5);
glBegin(GL_QUADS);
 glVertex3f(.775, -.35, 0.0);
 glVertex3f(.775, .22, 0.0);
 glVertex3f(.825, 0.21, 0.0);
 glVertex3f(.825, -.35, 0.0);
glEnd();
        ///side-2-border
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.775, -.35, 0.0);glVertex3f(.775, .22, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.775, .22, 0.0);glVertex3f(.825, 0.21, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.825, 0.21, 0.0);glVertex3f(.825, -.35, 0.0);glEnd();
glColor3f(.270, .270, .270);glBegin(GL_LINES);glVertex3f(.775, -.35, 0.0);glVertex3f(.825, -.35, 0.0);glEnd();




///----------------------------------------------Moving-------------------------------------------------
///-----------------------------cloud-------------------------------
///cloud_1_5_6
///1
glPushMatrix();
glTranslatef(cld1,0,0);
cloud1();
glPopMatrix();
///5
glPushMatrix();
glTranslatef(cld5,0,0);
cloud5();
glPopMatrix();
///6
glPushMatrix();
glTranslatef(cld6,0,0);
cloud6();
glPopMatrix();

///cloud_3_7
///3
glPushMatrix();
glTranslatef(cld3,0,0);
cloud3();
glPopMatrix();
///7
glPushMatrix();
glTranslatef(cld7,0,0);
cloud7();
glPopMatrix();

///window1,2
glPushMatrix();
glColor3f(tx, ty, 0);
window1();
window2();
glPopMatrix();
///topCircle
glPushMatrix();
glColor3f(tx1, ty1, 0);
topCircle();
glPopMatrix();

///---------------------------------------<<<<<<<<<<<<<Road-1>>>>>>>>>>>>----------------------------------------
///Move car Road1-1Car2&3
glPushMatrix();
glTranslatef(road1_1,0,0);
Road1_1Car2();
Road1_1Car3();
glPopMatrix();
///Move car Road1-1Car1
glPushMatrix();
glTranslatef(road1_1C1,0,0);
Road1_1Car1();
glPopMatrix();

///Move car Road1-2Car1
glPushMatrix();
glTranslatef(road1_2C1,0,0);
Road1_2Car1();
glPopMatrix();
///Move car Road1-2Car2
glPushMatrix();
glTranslatef(road1_2C2,0,0);
Road1_2Car2();
glPopMatrix();
///---------------------------------------<<<<<<<<<<<<<Road-2>>>>>>>>>>>>----------------------------------------
///Move car Road2-1Car1
glPushMatrix();
glTranslatef(road2_1C1,0,0);
Road2_1Car1();
glPopMatrix();
///Move car Road2-1Car2
glPushMatrix();
glTranslatef(road2_1C2,0,0);
Road2_1Car2();
glPopMatrix();

///Move car Road2-2Car1
glPushMatrix();
glTranslatef(road2_2C1,0,0);
Road2_2Car1();
glPopMatrix();
///Move car Road2-2Car2
glPushMatrix();
glTranslatef(road2_2C2,0,0);
Road2_2Car2();
glPopMatrix();
///---------------------------------------<<<<<<<<<<<<<Boat>>>>>>>>>>>>----------------------------------------
glPushMatrix();
glTranslatef(boat_,0,0);
boat();
glPopMatrix();
///end----------------------------------------------------------------------------------
///-------------------------------------------------------------------------------------

glFlush();
///---------------------------------------<<<<<<<<<<<<<Cloud>>>>>>>>>>>>----------------------------------------
///for cloud_1_5_6
if(cld1<=1.8){cld1=cld1+0.00003;}
else{cld1=-.7;}
glutPostRedisplay();
///5
if(cld5<=1){cld5=cld5+0.00003;}
else{cld5=-1.2;}
glutPostRedisplay();
///6
if(cld6<=1.5){cld6=cld6+0.00003;}
else{cld6=-1;}
glutPostRedisplay();

///3
if(cld3<=.6){cld3=cld3+0.00003;}
else{cld3=-1.7;}
glutPostRedisplay();
///7
if(cld7<=.8){cld7=cld7+0.00003;}
else{cld7=-1.4;}
glutPostRedisplay();

///---------------------------------------<<<<<<<<<<<<<Road-1>>>>>>>>>>>>----------------------------------------
///for Road1-1Car2&3
if(road1_1>=-1.5){road1_1=road1_1-0.00039;}
else{road1_1=1.6;}
glutPostRedisplay();
///for Road1-1Car1(red car)
if(road1_1C1>=-1.7){road1_1C1=road1_1C1-0.00038;}
else{road1_1C1=1;}
glutPostRedisplay();

///for Road1-2Car1(School Bus)
if(road1_2C1<=1.3)
{road1_2C1=road1_2C1+0.00037;}
else{road1_2C1=-1;}
glutPostRedisplay();
///for Road1-2Car2
if(road1_2C2<=1){road1_2C2=road1_2C2+0.00039;}
else{road1_2C2=-1.4;}
glutPostRedisplay();

///---------------------------------------<<<<<<<<<<<<<Road-2>>>>>>>>>>>>----------------------------------------
///for Road2-1Car1
if(road2_1C1>=-1.7){road2_1C1=road2_1C1-0.00038;}
else{road2_1C1=1;}
glutPostRedisplay();
///for Road2-1Car2
if(road2_1C2>=-1.3){road2_1C2=road2_1C2-0.00039;}
else{road2_1C2=1.4;}
glutPostRedisplay();

///for Road2-2Car1
if(road2_2C1<=1.8){road2_2C1=road2_2C1+0.00039;}
else{road2_2C1=-1;}
glutPostRedisplay();
///for Road2-2Car2
if(road2_2C2<=1){road2_2C2=road2_2C2+0.00037;}
else{road2_2C2=-1.2;}
glutPostRedisplay();

///---------------------------------------<<<<<<<<<<<<<Boat>>>>>>>>>>>>----------------------------------------
if(boat_<=1){boat_=boat_+0.000090;}
else{boat_=-1.2;}
glutPostRedisplay();
///-----------------------------------End of Draw---------------------------------------
}

void spe_key(int key, int x, int y)
{///glColor3f(0.49, .96, 1);
///glColor3f(0.105, .023, .212);///night

	switch (key) {

		case GLUT_KEY_LEFT:
				tx1 =0;
				ty1 =0;

				glutPostRedisplay();
				break;

		case GLUT_KEY_RIGHT:
				tx1 =1;
				ty1 =1;
				glutPostRedisplay();
				break;

        case GLUT_KEY_DOWN:
                tx =0;
				ty =0;
				sx=.49;
				sy=.96;
				sz=1;
				sm1=.968;
				sm2=.913;
				sm3=.145;
				glutPostRedisplay();
				break;


		case GLUT_KEY_UP:
                tx =1;
				ty =1;
				sx=.105;
				sy=.023;
				sz=.212;
				sm1=.98;
				sm2=.98;
				sm3=.98;
				glutPostRedisplay();
				break;
	  default:
			break;
	}
}


int main(int iArgc , char** cppArgv)
{
glutInit(&iArgc , cppArgv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1080,850);
glutInitWindowPosition(450,100);
glutCreateWindow("Skyscrapper");
Initialize();
glutDisplayFunc(Draw);
glutSpecialFunc(spe_key);
glutMainLoop();
return 0;
}

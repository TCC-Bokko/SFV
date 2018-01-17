
//#include "Objects.h"//incluir clases de cada objeto
#include <stdlib.h>
#include "gl/glut.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
//#include "glm.h"
//#include "assert.h"
//#include "MenuItems.h"
//#include "Misc.h"
//#include "Controls.h"
//#include "Collision.h"
//#include "IMGLoader.h"
#include "Objeto.h"
#include "Ball.h"
#include "PSystem.h"
#include "Pared.h"

using namespace Physics;

//#define WINDOW_NAME "Ping Pong"

//	<Prototypes>
void display(void);
void myReshape(int w, int h);
void camera();
void mouseFunc(int button, int state, int x, int y);
void idleFunc();

int gravityIsOn;
float gravity;
float friction;
//pixel *img;

Objeto * ball;
Pared* wall;
Objeto * ball2;
PSystem * ps; 
PSystem * ps2;
void initializeVariables()
{
	gravity = 1;
	// <Racket>
	//gameIsPaused = 1;
	gravityIsOn = 1;


	//img = NULL;
	//exitMenu = 0;

	friction = 0.10;

	//ARREGLAR QUE SOLO SE GENEREN PARTICULAS EN EL CUADRANTE I (Meter valores negativos por ahí)
	//METER GRAVEDAD a bolas
	//QUE afecte la masa (menos masa más fácil mover)

	// Ball
	ball = new Ball(Punto(12.5, 40, 1), Vector(0, 0, 0), 0.01f, 1.0f);
	ps = new PSystem(Punto(5, 0, 0), 10, Vector(3, 3, 3), 0.2f, false, false); //Lugar, nº particulas, velocidad por eje, masa, gravedad, debug
	ps2 = new PSystem(Punto(0, 5, 0), 1000, Vector(5, 5, 5), 0.5f, false, false);
	ball2 = new Ball(Punto(0, 0, 5), Vector(2, 0, 0), 0.01f, 1.0f);
	wall = new Pared(Punto(11, 7, 1), 10, 15, 0.8f);
}

int main(int argc, char *argv[])
{
	//setUpScreen();
	initializeVariables();
	int my_window;
	//mainMenu(); //Setup the main menu
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600); //Original 640x480
	my_window = glutCreateWindow("Freeglut 3D-project");
	//glutCreateWindow(WINDOW_NAME);
	glutReshapeFunc(myReshape);

	glutDisplayFunc(display);

	glClearColor(0.36, 0.14, 0.57, 0);

	/*glutSpecialFunc(kbSpecialFunc);
	glutKeyboardFunc(kbDown);
	glutKeyboardUpFunc(kbUp);*/
	glutIdleFunc(idleFunc);
	//glutMouseFunc(mouseFunc);

	//pauseGame();

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();

	return 0;
}

void camera()
{
	// CON ESTA CONFIGURACION LA POSICION DE LOS OBJETOS ES 
	// X: (-) Izq, (+) Der
	// Z: (-) Abj, (+) Arriba
	// Y: (-) Se aleja, (+) Se acerca
	gluLookAt(0.0, 0.0, 100.0, //EYE (Especifica la posición del ojo)
		0.0, 0.0, 0.0,		 //Center (Especifica la posición del punto de referencia)
		0, 1.0, 0);		 //UP (Especifica la dirección del vector UP)


	glutPostRedisplay();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));


	//checkKeyPressed();

	/*if (gameIsPaused)
	{
		printMenu();
		glFlush();
		glutSwapBuffers();
		return;
	}*/

	//ACTORES DE LA ESCENA
	camera();
	ball->draw();
	//ball2->draw();
	//ps->draw();
	//wall->draw();
	//ps2->draw();

	//drawShadows();
	//drawTable();
	//drawPlane();


	// Luces de la escena
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat d[] = { 0.7f,0.5f,0.5f,1.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
	GLfloat a[] = { 0.3f,0.3f,0.3f,1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat s[] = { 1.0f,1.0f,1.0f,1.0f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, s);
	GLfloat p[] = { 25.0f, 25.0f, 25.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, p);
	//drawRacket(racket.location[0], racket.location[1], racket.location[2]);



	//glutSetCursor(GLUT_CURSOR_NONE); //a la mierda el cursor del raton

	glFlush();

	glutSwapBuffers();

	return;
}

void myReshape(int width, int height)
{
	if (height == 0)
	{
		height = 1;
	}

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();



	/*if (gameIsPaused)
	{
		gluOrtho2D(0.0, 768.0, 0.0, 480.0);
		glutReshapeWindow(640, 480);
	}*/
	//else
	//{
		gluPerspective(45.0f, ((GLfloat)width) / ((GLfloat)height + 40), 0.01f, 100.0f);
		glutReshapeWindow(768, 480);
	//}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

float forces(int i, int j)
{
	if (!1) //
		return(0.0);
	else if (j == 1)
		return(-gravity);
	else
		return(0.0);
}

float forces222(int i, int j, float velocity)
{
	float frict = 0.3;
	if (velocity > 0)
	{
		frict = -friction;
	}
	else if (velocity < 0)
	{
		frict = friction;
	}


	if (j == 1)
	{
		return((-(gravity - frict)));
	}

	return(frict);
}


/**
* Text book Example on particle physics (Interactive Computer Graphics A Top Down Approach, fith edition PG 574),
* adapted to work with spheres & incorparate better collision detection
*/
void idleFunc()
{
	static float lastTime = 0.0f, presentTime = 0.0f;
	int i = 0, j;
	double dt;

	presentTime = glutGet(GLUT_ELAPSED_TIME);

	dt = 0.001*(presentTime - lastTime); // Sec to MiliSec

	ball->update(dt);
	ball2->update(dt);
	ps->update(dt);
	ps2->update(dt);


	//Actualización de la posición de las particulas en cada eje
/*	for (GLint particle = 0; particle < 10; particle++) {
		for (GLint axys = 0; axys < 3; axys++) {
			//guarda la posicion como antigua
			sisImpact.particles[particle].oldLocation[axys] = sisImpact.particles[particle].location[axys];
			//Calcular la nueva posicion
			sisImpact.particles[particle].location[axys] += dt*sisImpact.particles[particle].velocity[axys];
			//aplica las fuerzas
			sisImpact.particles[particle].velocity[axys] += dt*forces222(i, axys, sisImpact.particles[particle].velocity[j]) / sisImpact.particles[particle].mass;
		}
	}

	racket.velocity[0] *= 0.9;
	racket.velocity[2] *= 0.9;*/


	//collisionDetection();
	//racketCollision();





	/*if (ball.velocity[2] > 0)
	{
	if (ball.location[2] > racket.location[2] - 10 && ball.location[2] < racket.location[2] + 10)
	{
	if (racket.location[1] < ball.location[1])
	{
	racket.location[1] = ball.location[1];
	}

	}
	}*/


	//Need to change this to the new method of collision detection
	/*if (ball.location[2] <= -4.1 || ball.location[2] >= 50 || ball.location[1] <= -10.1)
	{
		resetBall();
	}
	*/
	lastTime = presentTime;
	glutPostRedisplay();
}
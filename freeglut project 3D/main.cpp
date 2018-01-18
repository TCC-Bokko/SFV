
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
#include "Plane.h" //Plano XZ

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
bool debug;
bool collisionDetected;
//pixel *img;

Objeto * ball;
//Pared* wall;
Objeto * ball2;
Objeto * plane;
PSystem * ps; 
PSystem * ps2;


void pause4delight() {
	system("Pause");
}

void initializeVariables()
{
	gravity = 1;
	gravityIsOn = 1;
	debug = false;

	friction = 0.10;

	// Actores de las escena
	ball = new Ball(Punto(0, 35, 15), Vector(0, 0, 0), 0.01f, 2.0f, Vector(0, 1.0f, 0));
	//ps = new PSystem(Punto(5, 0, 0), 10, Vector(3, 3, 3), 0.2f, false, false); //Lugar, nº particulas, velocidad por eje, masa, gravedad, debug
	ps2 = new PSystem(Punto(0, 5, 0), 1000, Vector(5, 5, 5), 0.5f, false, false);
	//ball2 = new Ball(Punto(0, 0, 5), Vector(2, 0, 0), 0.01f, 1.0f);
	//wall = new Pared(Punto(11, 7, 1), Vector(0, 1, 1), 10, 15, 0.0f);
	plane = new Plane(Punto(-30.f, -25.f, -30.f), 60.f, 0.7f); //origen, tamaño y coef. restitucion entre 0 y 1.

	//pause4delight();
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
	my_window = glutCreateWindow("R.E.K.T ENGINE");
	//glutCreateWindow(WINDOW_NAME);
	glutReshapeFunc(myReshape);

	glutDisplayFunc(display);


	glClearColor(0.36, 0.14, 0.57, 0);

	/*glutSpecialFunc(kbSpecialFunc);
	glutKeyboardFunc(kbDown);
	glutKeyboardUpFunc(kbUp);*/
	glutIdleFunc(idleFunc);
	//glutMouseFunc(mouseFunc);

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
	//wall->draw();
	plane->draw();
	//ball2->draw();
	//ps->draw();
	//ps2->draw();

	//drawShadows();
	//drawTable();
	//drawPlane();
	
	GLfloat amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.9f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH); // Shading by default

	// Luces de la escena
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat d[] = { 0.7f, 0.5f, 0.5f, 1.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
	GLfloat a[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat s[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, s);
	GLfloat p[] = { 25.0f, 25.0f, 25.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, p);




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


void debugMessage() {
	system("cls");
	dynamic_cast<Ball*> (ball)->debugMessage();
	//dynamic_cast<PSystem*> (ps)->debugMessage();
	//dynamic_cast<PSystem*> (ps2)->debugMessage();
	//dynamic_cast<Pared*> (wall)->debugMessage();
	dynamic_cast<Plane*> (plane)->debugMessage();
}

/*
Funcion Update del Main
*/
void idleFunc()
{
	static float lastTime = 0.0f, presentTime = 0.0f;
	int i = 0, j;
	double dt;

	presentTime = glutGet(GLUT_ELAPSED_TIME);

	dt = 0.001*(presentTime - lastTime); // Sec to MiliSec

	if (debug){ debugMessage(); }

	ball->update(dt);
	//ball2->update(dt);
	//ps->update(dt);
	//ps2->update(dt);
	//wall->plano.cambiarNormal(Vector(wall->plano.getNormal().getX() + 1, wall->plano.getNormal().getY(), wall->plano.getNormal().getZ()), wall->centro);


	//std::cout << "Previo a deteccion colision\n";
	collisionDetected = Collisions::sphereAndPlanoXZ(dynamic_cast<Ball*>(ball)->getSphere(), dynamic_cast<Plane*>(plane)->getPlanoXZ());
	if (collisionDetected) {
		//if(debug)std::cout << "Colision detectada\n";
		display();
		dynamic_cast<Ball*>(ball)->updatePhysics(dynamic_cast<Plane*>(plane)->location, dynamic_cast<Plane*>(plane)->getN(), dynamic_cast<Plane*>(plane)->getCR());
	}
	else {
		//if(debug)std::cout << "NO HAY COLISION\n";
	}

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

*/
	lastTime = presentTime;
	glutPostRedisplay();
	//if (collisionDetected) pause4delight();
}
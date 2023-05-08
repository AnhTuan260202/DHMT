#include <iostream>
#include <cmath>
#include <gl/glut.h>
#include "minecraft_human.h"
#include "mouse_keyboard.h"

GLfloat ambient_light[] = { 0, 0, 0, 1.0f };
GLfloat diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat specular_light[] = { 0.1f, 0.1f, 0.1f, 1.0f };
GLfloat light_position[] = { -10.0f, 0, -2.0f, 1.0f };

GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat mat_diffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat high_shininess[] = { 10.0f };

GLfloat pos[] = { 10, 50, -20, 0 },
am[] = { 0.1, 0.1, 0.1, 1 },
diff[] = { 0.3, 0.2, 0.2, 1 },
spe[] = { 0, 0, 0, 1 };


void mat_dat()
{
	glPushMatrix();
	color_rgb(mau_dat);
	glTranslatef(0, -.5, 0);
	glScalef(1, 0.001, 1);
	glutSolidCube(1000);
	glPopMatrix();
}

void toa_do()
{
	glDisable(GL_LIGHTING);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(500, 0, 0);
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 500, 0);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 500);
	glEnd();
	//glEnable(GL_LIGHTING);
}

void display(void)
{
	static float x = 100;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	if (proj == false)
		glOrtho(-x, x, -x, x, 0.0, x);
	else
		gluPerspective(60.0, 1.0, 1.0, x);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(xtm, ytm, -4.0);   // Place objects between near and far clipping planes.
	glRotatef(tipp, 1, 0, 0);       // Rotate around screen horizontal axis.
	glRotatef(turn, 0, 1, 0);       // Rotate around world vertical axis.

	glLightfv(GL_LIGHT0, GL_AMBIENT, am);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, spe);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	
	glScalef(scl, scl, scl);       // Scale world relative to its origin.

	glPushMatrix();
	glScalef(0.01, 0.01, 0.01);
	toa_do();
	mat_dat();
	human_minecraft();

	glEnable(GL_COLOR_MATERIAL);
	glPopMatrix();
	glFlush();

	glutPostRedisplay();
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glShadeModel(GL_FLAT);
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-50.0, 50.0, -50.0 * (GLfloat)h / (GLfloat)w, 50.0 * (GLfloat)h / (GLfloat)w, -4.0, 50.0);
	else
		glOrtho(-50.0 * (GLfloat)w / (GLfloat)h, 50.0 * (GLfloat)w / (GLfloat)h, -50.0, 50.0, -4.0, 50.0);

	//gluPerspective(60, (GLdouble)w / h, -4, 50);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0, 0, 50, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Minecraft Drawing Project");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(OnSpecialKeyDown);
	glutSpecialUpFunc(OnSpecialKeyUp);
	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);

	glutMainLoop();
	return 0;
}
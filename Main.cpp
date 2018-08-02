#include <windows.h>
#include <GL/gl.h>
#include <glut.h>

int w = 800;
int h = 600;

double *m = new double[16];

void init(GLvoid)
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

}


void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//gluPerspective(60, (float)w / (float)h, 1.0, 100.0f);
	glOrtho(-50, 70, -25, 55, -25, 25);

	//glGetDoublev(GL_PROJECTION_MATRIX, m);


}



void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glTranslatef(0.0f, 0.0f, -5.0f);
	glPointSize(5.0f);
	glBegin(GL_POINTS);
	glVertex3f(.0f, 3.0f, .0f);
	glEnd();

	glGetDoublev(GL_PROJECTION_MATRIX, m);

	

	glutSwapBuffers();

}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(w, h);
	glutCreateWindow("OpenGL Programming");
	
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);

	glutMainLoop();
}
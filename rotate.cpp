#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

float angle = 0.0;
float Cx, Cy, Cz = 0.0;
float Vx, Vy, Vz = 0.0;

void display(void) {
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(Cx, Cy, Cz);
   glRotatef(angle, Vx, Vy, Vz);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(0.2, 1.0, 0.2);
   glutWireCube(1.5);
   glFlush();
}

void init(void) {
   /* select clearing color 	*/
   glClearColor (0.0, 0.0, 0.0, 0.0);

   /* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
}

void rotateCube(void)
{
   angle += 15.0;
   if (angle > 360.0)
      angle = 0;
   glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
   if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
      rotateCube();
}

int main(int argc, char** argv) {
   Cx = atof(argv[7]);
   Cy = atof(argv[8]);
   Cz = atof(argv[9]);
   Vx = atof(argv[4]) - atof(argv[1]);
   Vy = atof(argv[5]) - atof(argv[2]);
   Vz = atof(argv[6]) - atof(argv[3]);

   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (600, 600);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Rotate");
   init ();
   glutDisplayFunc(display);
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;   /* We'll never be here.*/
}

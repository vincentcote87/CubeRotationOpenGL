#include <stdlib.h>
#include <stdio.h>

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

float EYEx, EYEy = 0.0;
float EYEz = 5.0;
float angle = 0.0;
float z = 0.0;

void display(void)
{
   /* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   /* Set the color to black */
   glColor3f (1.0, 1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);

   /* Clear the current matrix */
   glLoadIdentity();

   /* Viewing transformation */
   gluLookAt(EYEx, EYEy, (EYEz + z),   /* Eye */
             0.0, 0.0, 0.0,   /* Look at */
             0.0, 1.0, 0.0);  /* Up vector */

   glColor3f(1.0, 0.0, 1.0);
   glTranslatef(0.0, 0.0, z);
   glRotated(angle, 0.0, 1.0, 0.0);
   glutWireCube(1.0);

   angle += 0.01;
   if (angle > 360)
    angle = 0;

   /* don't wait!
    * start processing buffered OpenGL routines 
    */
   glFlush ();
}

void init (void)
{
   /* select clearing color 	*/
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
   /* Set the view port */
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);

   /* Projection transformation */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-1.0, 1.0, /* Left and right boundary */
             -1.0, 1.0, /* bottom and top boundary */
             1.5, 200.0); /* near and far boundary */
   glMatrixMode(GL_MODELVIEW);
}

void changeEye(void)
{
  if (EYEx == 5.0) {
    EYEx = 0.0;
    EYEy = 0.0;
  } else {
    EYEx = 5.0;
    EYEy = 5.0;
  }
  glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_RIGHT_BUTTON) {
    if (state == GLUT_DOWN) {
      EYEx = 5;
      EYEy = 5;
    }
    if (state == GLUT_UP) {
      EYEx = 0;
      EYEy = 0;
    }
  }
}

void keyboard(unsigned char key, int x, int y)
{
  if (key == 122) {
    z -= 0.01;
  };
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init();
   glutDisplayFunc(display);
   glutIdleFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;   /* We'll never be here.*/
}

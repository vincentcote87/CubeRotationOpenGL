#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

float angle = 0.0;
float cx = 0.0;
float cy = 0.0;
float cz = 0.0;
float vx = 0.0;
float vy = 0.0;
float vz = 0.0;


void display(void)
{
   /* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   /* Set the color to black */
   glColor3f (0.0, 1.0, 0.0);

   /* Clear the current matrix */
   glLoadIdentity();

   // Transform to origin
   glTranslatef(cx, cy, cz);

   // Do the rotation
   glRotatef(angle, vx, vy, vz);
   
   // Draw the Cube
   glutWireCube(1.0);

   /* don't wait!
    * start processing buffered OpenGL routines
    */
   glFlush ();
}

void init (void)
{
   /* select clearing color 	*/
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 600.0f, 600.0f, 1.0, -1.0, 1.0);
}

void rotateCube(void)
{
   angle = angle + 15.0;
   if (angle > 360.0)
      angle = 0;
   glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
   if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
      rotateCube();
}

int main(int argc, char** argv)
{
   cx = atof(argv[7]);
   cy = atof(argv[8]);
   cz = atof(argv[9]);
   vx = atof(argv[4]) - atof(argv[1]);
   vy = atof(argv[5]) - atof(argv[2]);
   vz = atof(argv[6]) - atof(argv[3]);

   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(600, 600);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init();
   glutDisplayFunc(display);
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;   /* We'll never be here.*/
}

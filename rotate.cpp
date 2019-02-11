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
   glColor3f (0.0, 1.0, 1.0);

   /* Clear the current matrix */
   glLoadIdentity();

   /* Viewing transformation */
//    gluLookAt(0.0, 0.0, 5.0,   /* Eye */
//              0.0, 0.0, 0.0,   /* Look at */
//              0.0, 1.0, 0.0);  /* Up vector */
   /* Modeling transformation */

   /* Create a unit cube whose center is at (0, 0, 0) */
//    glTranslatef(1.5,1,1);
//    glutWireCube(1.0);
// glTranslatef(1.0, 1.0, 1.0);
glTranslatef(cx, cy, cz);
glRotatef(angle, vx, vy, vz);
glutWireCube(1.0);
//    glBegin(GL_QUADS);
//     glVertex3f(-1.0f, -1.0, -1.0);
//     glVertex3f(-1.0f, 1.0, -1.0);
//     glVertex3f(1.0f, 1.0, -1.0);
//     glVertex3f(1.0f, -1.0, -1.0);
//    glEnd();

   /* don't wait!
    * start processing buffered OpenGL routines
    */
   glFlush ();
}

void init (void)
{
   /* select clearing color 	*/
   glClearColor (0.0, 0.0, 0.0, 0.0);

   /* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 600.0f, 600.0f, 1.0, -1.0, 1.0);
}

// void reshape(int w, int h)
// {
//    /* Set the view port */
//    glViewport(0, 0, (GLsizei) w, (GLsizei) h);

//    /* Projection transformation */
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glFrustum(-1.0, 1.0, /* Left and right boundary */
//              -1.0, 1.0, /* bottom and top boundary */
//              1.5, 20.0); /* near and far boundary */
//    glMatrixMode(GL_MODELVIEW);
// }
void rotateCube(void)
{
   angle = angle + 15.0;
   if (angle > 360.0)
      angle = 0;
   glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            rotateCube();
            // glutIdleFunc(rotateCube);
         if (state == GLUT_UP)
            glutIdleFunc(NULL);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
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
//    glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;   /* We'll never be here.*/
}
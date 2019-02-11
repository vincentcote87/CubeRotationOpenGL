
/*
 * hello.c
 * This is a simple, introductory OpenGL program.
 */
#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>


void display(void)
{
   /* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   /* Set the color to black */
   glColor3f (1.0, 1.0, 1.0);

   /* Clear the current matrix */
   glLoadIdentity();

   /* Viewing transformation */
   gluLookAt(0.0, 0.0, 5.0,   /* Eye */
             0.0, 0.0, 0.0,   /* Look at */
             0.0, 1.0, 0.0);  /* Up vector */
   /* Modeling transformation */
   glScalef(1.0, 2.0, 1.0);   
   
   /* Create a unit cube whose center is at (0, 0, 0) */
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
             1.5, 20.0); /* near and far boundary */
   glMatrixMode(GL_MODELVIEW);
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
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;   /* We'll never be here.*/
}

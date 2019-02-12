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
   glutCreateWindow ("hello");
   init ();
   glutDisplayFunc(display);
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;   /* We'll never be here.*/
}

















// float angle = 0.0;
// float cx = 0.0;
// float cy = 0.0;
// float cz = 0.0;
// float vx = 0.0;
// float vy = 0.0;
// float vz = 0.0;


// void display(void)
// {

//      /* clear all pixels  */
//    // glClear (GL_COLOR_BUFFER_BIT);

//    /* draw white polygon (rectangle) with corners at
//     * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
//     */
//    // glRotatef(45.0, 0.0, 0.0, 0.0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();

//    glClear (GL_COLOR_BUFFER_BIT);

//    glColor3f (0.5, 1.0, 1.0);
//    // glTranslatef(cx, cy, cz);
//    glTranslatef(1.0, 1.0, 1.0);
//    glRotatef(angle, vx, vy, vz);
//    // glTranslatef(-cx, -cy, -cz);

//    glTranslatef(-1.0, -1.0, -1.0);
//    glutWireCube(1.0);
//    // glBegin(GL_POLYGON);
//    //    glVertex3f (0.25, 0.25, 0.0);
//    //    glVertex3f (0.75, 0.25, 0.0);
//    //    glVertex3f (0.75, 0.75, 0.0);
//    //    glVertex3f (0.25, 0.75, 0.0);
//    // glEnd();

//    /* don't wait!
//     * start processing buffered OpenGL routines
//     */
//    glFlush ();

//    // /* clear all pixels  */
//    // glClear (GL_COLOR_BUFFER_BIT);

//    // /* Set the color to black */
//    // glColor3f (0.0, 1.0, 0.0);

//    // /* Clear the current matrix */
//    // glLoadIdentity();

//    // // Transform to origin
//    // glTranslatef(cx, cy, cz);

//    // // Do the rotation
//    // glRotatef(angle, vx, vy, vz);

//    // // Draw the Cube
//    // glutWireCube(1.0);

//    // /* don't wait!
//    //  * start processing buffered OpenGL routines
//    //  */
//    // glFlush ();
// }

// void init (void)
// {
//    /* select clearing color 	*/
//    glClearColor (0.0, 0.0, 0.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-5.0, 5.0, -5.0, 5.0, -1.0, 1.0);
// }

// void rotateCube(void)
// {
//    angle += 15.0;
//    if (angle > 360.0)
//       angle = 0;
//    glutPostRedisplay();
// }

// void mouse(int button, int state, int x, int y)
// {
//    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
//       rotateCube();
// }

// int main(int argc, char** argv)
// {
//    cx = atof(argv[7]);
//    cy = atof(argv[8]);
//    cz = atof(argv[9]);
//    vx = atof(argv[4]) - atof(argv[1]);
//    vy = atof(argv[5]) - atof(argv[2]);
//    vz = atof(argv[6]) - atof(argv[3]);

//    glutInit(&argc, argv);
//    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(600, 600);
//    glutInitWindowPosition (100, 100);
//    glutCreateWindow (argv[0]);
//    init ();

//    glutDisplayFunc(display);
//    glutMouseFunc(mouse);
//    printf("cx = %f, cy = %f, cz = %f, angle = %f \n", cx, cy, cz, angle);
//    glutMainLoop();
//    return 0;   /* We'll never be here.*/
// }

#include <GL/glut.h>
void display()
{
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);glVertex2f(0, 1);
        glColor3f(0,1,0);glVertex2f(1, -0.6);
        glColor3f(0,0,1);glVertex2f(-1, -0.6);
    glEnd();
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week02_colour_TRI*");
    glutDisplayFunc(display);

    glutMainLoop();
}

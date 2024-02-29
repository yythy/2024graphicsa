#include <GL/glut.h>
void display()
{
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);glVertex2f((0-200)/200.0, (0-200)/200.0);
        glColor3f(1,0,0);glVertex2f((400-200)/200.0, (1-200)/200.0);
        glColor3f(1,0,0);glVertex2f((400-200)/200.0, (400-200)/200.0);
        glColor3f(1,0,0);glVertex2f((1-200)/200.0, (400-200)/200.0);
    glEnd();
    /*glBegin(GL_POLYGON);
        glColor3f(1,0,0);glVertex2f(50/200.0, 150/200.0);
        glColor3f(1,0,0);glVertex2f(-50/200.0, -150/200.0);
        glColor3f(1,0,0);glVertex2f(50/200.0, -50/200.0);
        glColor3f(1,0,0);glVertex2f(-150/200.0, 150/200.0);
    glEnd();*/
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

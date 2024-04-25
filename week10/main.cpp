#include <GL/glut.h>
void myBody()
{
    glPushMatrix();
        glColor3f(1, 0, 0);
        glutWireCube(0.6);
     glPopMatrix();
}

void myArm()
{
        glPushMatrix();
        glColor3f(1, 1, 0);
        glScalef(1,0.4,0.4);
        glutWireCube(0.3);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    myBody();
    myArm();

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);

    glutMainLoop();
}

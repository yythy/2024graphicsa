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

float angle=0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    myBody();
    glPushMatrix();
        //glTranslatef();
        glRotatef(angle++,0,0,1);
        glTranslatef(0.15,0,0);///�ץ����त��
        myArm();
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();
}

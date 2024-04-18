#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///glutSolidCube( 0.3 );
    ///glutSolidSphere( 0.3,30,30 );
    glPushMatrix();
        glTranslatef(-0.5,+0.3,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(+0.0,+0.3,0);
        glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(+0.5,+0.3,0);
        glutSolidSphere(0.3,30,30);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.5,-0.3,0);
        glutWireTeapot(0.3);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(+0.0,-0.3,0);
        glutWireCube(0.3);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(+0.5,-0.3,0);
        glutWireSphere(0.3,30,30);
    glPopMatrix();

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

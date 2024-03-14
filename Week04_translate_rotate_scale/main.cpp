#include <GL/glut.h>
#include <stdio.h>
float angle =0,oldX=0;
void display()
{
    glClearColor(1.0,1.0,0.9,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(0.8,0,0);
        glRotatef(angle--, 0, 0, 1);
        glScalef(0.3,0.3,0.3);
        glColor3f(0, 1, 1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04_keyboard mouse motion");
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();
}

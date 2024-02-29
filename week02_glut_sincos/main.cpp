#include <GL/glut.h>
#include <math.h>
void display()
{
    glBegin(GL_POLYGON);
        for(float a=0;a<3.1415926*2;a+=0.001){
            glVertex2f(0.7*cos(a),0.7*sin(a)-0.3);
        }
    glEnd();

    glBegin(GL_POLYGON);
        for(float a=0;a<3.1415926*2;a+=0.001){
            glVertex2f(0.4*cos(a)-0.6,0.4*sin(a)+0.5);
        }
    glEnd();
    glBegin(GL_POLYGON);
        for(float a=0;a<3.1415926*2;a+=0.001){
            glVertex2f(0.4*cos(a)+0.6,0.4*sin(a)+0.5);
        }
    glEnd();
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week02_colour_circle");
    glutDisplayFunc(display);

    glutMainLoop();
}

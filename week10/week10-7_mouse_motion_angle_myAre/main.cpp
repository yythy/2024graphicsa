#include <GL/glut.h>
float angle = 0;
void myArm()
{
    glPushMatrix();
        glColor3f(1, 1, 0);
        glScalef(1,0.4,0.4);
        glutWireCube(0.3);
    glPopMatrix();
}
void myBody()
{
    glPushMatrix();
        glColor3f(1, 0, 0);
        glutWireCube(0.6);
     glPushMatrix();
        glTranslatef(0.3, 0.3, 0);///��b�ӤW
        glRotatef(angle,0,0,1);///�۶�
        glTranslatef(0.15, 0, 0);///�վ���त��
        myArm();///�ڪ������O��
    glPopMatrix();
}

void motion(int x, int y)
{
    angle = x;
    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    myBody();
    glPushMatrix();
        glTranslatef(0.3, 0.3, 0);///��b�ӤW
        glRotatef(angle,0,0,1);///�۶�
        glTranslatef(0.15, 0, 0);///�վ���त��
        myArm();///�ڪ������O��
        glPushMatrix();
            glTranslatef(0.15, 0, 0);///��b�ӤW
            glRotatef(angle,0,0,1);///�۶�
            glTranslatef(0.15, 0, 0);///�վ���त��
            myArm();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3, 0.3, 0);///��b�ӤW
        glRotatef(angle,0,0,1);///�۶�
        glTranslatef(-0.15, 0, 0);///�վ���त��
        myArm();///�ڪ������O��
        glPushMatrix();
            glTranslatef(-0.15, 0, 0);///��b�ӤW
            glRotatef(angle,0,0,1);///�۶�
            glTranslatef(-0.15, 0, 0);///�վ���त��
            myArm();
        glPopMatrix();
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
    glutMotionFunc(motion);

    glutMainLoop();
}
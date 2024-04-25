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
     glPopMatrix();
     glPushMatrix();
        glTranslatef(0.3, 0.3, 0);///放在肩上
        glRotatef(angle++,0,0,1);///旋傳
        glTranslatef(0.15, 0, 0);///調整旋轉中心
        myArm();///我的王之力啊
    glPopMatrix();

    glutSwapBuffers();
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    myBody();

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

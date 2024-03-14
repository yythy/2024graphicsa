#include <GL/glut.h>
#include <stdio.h>
float angle =0,oldX=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key, int x , int y){
    printf("key: %c x: %d y: %d\n",key , x, y);
}
void mouse(int button,int state, int x , int y){
     oldX=x;
}
void motion(int x,int y){
    angle +=(x-oldX);
    oldX = x;
    display();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04_keyboard mouse motion");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}

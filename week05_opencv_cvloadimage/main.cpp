#include <GL/glut.h>
#include <opencv/highgui.h>
void display()
{
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    IplImage * img = cvLoadImage("C:\\Users\\Administrator\\Downloads\\AA.jpg");
    cvShowImage("opencv",img);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);

    glutMainLoop();
}

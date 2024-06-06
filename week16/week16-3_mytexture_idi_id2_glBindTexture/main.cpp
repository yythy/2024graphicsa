#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * quad = NULL;
int id1,id2;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle =0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glBindTexture(GL_TEXTURE_2D,id2);
    glBegin(GL_POLYGON);
        glTexCoord2f(0,0); glVertex2f(-1, +1);
        glTexCoord2f(0,1); glVertex2f(-1, -1);
        glTexCoord2f(1,1); glVertex2f(+1, -1);
        glTexCoord2f(1,0); glVertex2f(+1, +1);
    glEnd();
    glBindTexture(GL_TEXTURE_2D,id1);
    glPushMatrix();
        glRotatef(90,1,0,0);
        glRotatef(angle++,0,0,1);
        gluSphere(quad,0.5,30,30);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("16-3");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    id2 = myTexture("C:/background.jpg");
    id1 = myTexture("C:/earth.jpg");
    quad = gluNewQuadric();
    gluQuadricTexture(quad,1);
    glutMainLoop();
}

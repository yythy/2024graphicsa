#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>

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
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * uppera = NULL;
GLMmodel * lowera = NULL;
GLMmodel * body = NULL;
void drawbody(void)
{
    if (!body) {
	body = glmReadOBJ("data/body.obj");
	if (!body) exit(0);
	glmUnitize(body);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH | GLM_TEXTURE);
}

void drawuppera(void)
{
    if (!uppera) {
	uppera = glmReadOBJ("data/upperA.obj");
	if (!uppera) exit(0);
	glmUnitize(uppera);
	glmFacetNormals(uppera);
	glmVertexNormals(uppera, 90.0);
    }

    glmDraw(uppera, GLM_SMOOTH | GLM_TEXTURE);
}

void drawlowera(void)
{
    if (!lowera) {
	lowera = glmReadOBJ("data/lowerA.obj");
	if (!lowera) exit(0);
	glmUnitize(lowera);
	glmFacetNormals(lowera);
	glmVertexNormals(lowera, 90.0);
    }

    glmDraw(lowera, GLM_SMOOTH | GLM_TEXTURE);
}
void myBody()
{
    glPushMatrix();
        glColor3f(1,0,0);
        glutSolidCube(0.6);
    glPopMatrix();
}
///float angle = 0, da = -1; ///�[�o��, �������
float angle[20] = {};
int angleID = 0;
int oldX = 0, oldY = 0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x,int y)
{
    angle[angleID] = +y - oldX;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
    if(fout==NULL) fout = fopen("angle.txt","w+");
    for(int i=0; i<20; i++){
        printf("%.1f ",angle[i]);
        fprintf(fout,"%.1f ",angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
}
void mouse(int button, int state,int x ,int y)
{
    oldX = x;
    oldY = y;
}
void keyboard(unsigned char key, int x,int y)
{
    if(key=='r') {
        if(fout==NULL) fin = fopen("angle.txt","r");
        for(int i=0; i<20; i++){
            fscanf(fin, "%f", & angle[i]);
        }
        glutPostRedisplay();
    }
    if(key=='0') angleID = 0;
    if(key=='1') angleID = 1;
    if(key=='2') angleID = 2;
    if(key=='3') angleID = 3;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);
    ///glPushMatrix();
        glRotatef(angle[0],0,1,0);
        drawbody();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1,1,1);

        glPushMatrix();
            glTranslatef(-0.1,0,0);
            glRotatef(angle[1],0,0,1);
            glRotatef(angle[2],1,0,0);
            glTranslatef(0,-0.07,0);
            drawuppera();
            glPushMatrix(); ///�[�o��, �������
                glTranslatef(-0.02,-0.09,0);
                glRotatef(angle[3], 1, 0, 0);
                glTranslatef(0,-0.21,0);
                drawlowera(); //glutSolidTeapot( 0.3 );
            glPopMatrix(); ///�[�o��, �������
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();

}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///�[�o��, �������

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11 Gundam");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///�[�o��, �������
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    myTexture("data/Diffuse.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}

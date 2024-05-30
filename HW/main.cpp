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
	uppera = glmReadOBJ("data/leg.obj");
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
	lowera = glmReadOBJ("data/leg.obj");
	if (!lowera) exit(0);
	glmUnitize(lowera);
	glmFacetNormals(lowera);
	glmVertexNormals(lowera, 90.0);
    }

    glmDraw(lowera, GLM_SMOOTH | GLM_TEXTURE);
}
void drawupperb(void)
{
    if (!upperb) {
	upperb = glmReadOBJ("data/leg.obj");
	if (!upperb) exit(0);
	glmUnitize(upperb);
	glmFacetNormals(upperb);
	glmVertexNormals(upperb, 90.0);
    }

    glmDraw(upperb, GLM_SMOOTH | GLM_TEXTURE);
}

void drawlowerb(void)
{
    if (!lowerb) {
	lowerb = glmReadOBJ("data/leg.obj");
	if (!lowerb) exit(0);
	glmUnitize(lowerb);
	glmFacetNormals(lowerb);
	glmVertexNormals(lowerb, 90.0);
    }

    glmDraw(lowerb, GLM_SMOOTH | GLM_TEXTURE);
}
void drawlega(void)
{
    if (!lega) {
	lega = glmReadOBJ("data/leg.obj");
	if (!lega) exit(0);
	glmUnitize(lega);
	glmFacetNormals(lega);
	glmVertexNormals(lega, 90.0);
    }

    glmDraw(lega, GLM_SMOOTH | GLM_TEXTURE);
}

void drawlegb(void)
{
    if (!legb) {
	lowerb = glmReadOBJ("data/leg.obj");
	if (!llegb) exit(0);
	glmUnitize(legb);
	glmFacetNormals(legb);
	glmVertexNormals(legb, 90.0);
    }

    glmDraw(legb, GLM_SMOOTH | GLM_TEXTURE);
}

void drawhead(void)
{
    if (!head) {
	lowerb = glmReadOBJ("data/head.obj");
	if (!lhead) exit(0);
	glmUnitize(head);
	glmFacetNormals(head);
	glmVertexNormals(head, 90.0);
    }

    glmDraw(head, GLM_SMOOTH | GLM_TEXTURE);
}

void myBody()
{
    glPushMatrix();
        glColor3f(1,0,0);
        glutSolidCube(0.6);
    glPopMatrix();
}
///float angle = 0, da = -1; ///�[�o��, �������
float angleX[10] = {},angleY[10] = {};
int angleID = 0;
int oldX = 0, oldY = 0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x,int y)
{
    angleX[angleID] += y - oldY;
    angleY[angleID] -= x - oldX;
    oldX = x;
    oldY = y;
    glutPostRedisplay();

}
void mouse(int button, int state,int x ,int y)
{
    oldX = x;
    oldY = y;
}
float oldAngleX[10] = {},newAngleX[10] ={};
float oldAngleY[10] = {},newAngleY[10] ={};
void timer(int t){
    glutTimerFunc(50,timer,t+1);
    if(t%20==0){
        if(fin==NULL) fin = fopen("angle.txt","r");
        for(int i=0;i<10;i++){
            oldAngleX[i] = newAngleX[i];
            oldAngleY[i] = newAngleY[i];
            fscanf(fin,"%f",& newAngleX[i]);
            fscanf(fin,"%f",& newAngleY[i]);
        }
    }
    float alpha = (t%20) / 20.0;
    for(int i=0;i<20;i++){
        angleX[i] = newAngleX[i]*alpha+oldAngleX[i]*(1-alpha);
        angleY[i] = newAngleY[i]*alpha+oldAngleY[i]*(1-alpha);
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x,int y)
{
    if(key=='p') {
        glutTimerFunc(0,timer,0);
    }
    if(key=='r') {
        if(fout==NULL) fin = fopen("angle.txt","r");
        for(int i=0; i<10; i++){
            fscanf(fin, "%f", & angleX[i]);
            fscanf(fin, "%f", & angleY[i]);
        }
        glutPostRedisplay();
    }else if(key == 's'){
        if(fout==NULL) fout = fopen("angle.txt","w+");
        for(int i=0; i<10; i++){
            printf("%.1f ",angleX[i]);
            printf("%.1f ",angleY[i]);
            fscanf(fin, "%f", & angleX[i]);
            fscanf(fin, "%f", & angleY[i]);
        }
        printf("\n");
        fprintf(fout,"\n");

    }
    if(key=='0') angleID = 0;
    if(key=='1') angleID = 1;
    if(key=='2') angleID = 2;
    if(key=='3') angleID = 3;
    if(key=='4') angleID = 4;
    if(key=='5') angleID = 5;
    if(key=='6') angleID = 6;
    if(key=='7') angleID = 7;
    if(key=='8') angleID = 8;
    if(key=='9') angleID = 9;
    if(key=='-') angleID = 10;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);
    glPushMatrix();
        glRotatef(angleX[0],0,1,0);
        glRotatef(angleY[0],0,1,0);
        drawbody();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1,1,1);

        glPushMatrix();
            glTranslatef(-0.1,0,0);
            glRotatef(angleX[1],0,0,1);
            glRotatef(angleY[1],0,0,1);
            glRotatef(angleX[2],1,0,0);
            glRotatef(angleY[2],0,0,1);
            glTranslatef(0,-0.07,0);
            drawuppera();
            glPushMatrix(); ///�[�o��, �������
                glTranslatef(-0.02,-0.09,0);
                glRotatef(angleX[3], 1, 0, 0);
                glRotatef(angleY[3], 1, 0, 0);
                glTranslatef(0,-0.21,0);
                drawlowera(); //glutSolidTeapot( 0.3 );
            glPopMatrix(); ///�[�o��, �������
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.1,0,0);
            glRotatef(angleX[4],0,0,-1);
            glRotatef(angleY[4],0,0,-1);
            glRotatef(angleX[5],-1,0,0);
            glRotatef(angleY[5],0,0,-1);
            glTranslatef(0,-0.07,0);
            drawupperb();
            glPushMatrix(); ///�[�o��, �������
                glTranslatef(-0.02,-0.09,0);
                glRotatef(angleX[6], -1, 0, 0);
                glRotatef(angleY[6], -1, 0, 0);
                glTranslatef(0,-0.21,0);
                drawlowerb(); //glutSolidTeapot( 0.3 );
            glPopMatrix(); ///�[�o��, �������
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.1,0,0);
            glRotatef(angleX[7],0,0,1);
            glRotatef(angleY[7],0,0,1);
            glRotatef(angleX[8],1,0,0);
            glRotatef(angleY[8],0,0,1);
            glTranslatef(0,-0.07,0);
            drawlega();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.1,0,0);
            glRotatef(angleX[9],0,0,1);
            glRotatef(angleY[9],0,0,1);
            glRotatef(angleX[10],1,0,0);
            glRotatef(angleY[10],0,0,1);
            glTranslatef(0,-0.07,0);
            drawlegb();
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

///void timer(int t){
   /// glutTimerFunc(1000,timer,t+1);
    ///printf("wakeUP!!:%d\n",t);
///}

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
    ///glutTimerFunc(0,timer,0);

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
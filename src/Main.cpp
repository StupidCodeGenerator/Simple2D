#include <GL/glut.h>
#include <stdio.h>
#include <Windows.h>
#include "2DInterface.h"

GLuint tex_2d;

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);    //����ϴ���ʾ�Ľ����ÿ�λ���ǰ���������      
	glClearColor(0.0, 0.0, 0.0, 0.0);  //�˾�ע�͵��Խ��û��Ӱ��,˵��Ĭ�ϵġ������ɫΪ��ɫ��
	glClear(GL_COLOR_BUFFER_BIT);    //����ϴ���ʾ�Ľ����ÿ�λ���ǰ���������    
	S2_SetColor(1.0, 0.0, 0.0);
	S2_DrawTriangle(30, 30, 400, 40, 50, 250);
	S2_SetColor(0.0, 1.0, 0.0);
	S2_DrawRect(100, 100, 300, 200);
	S2_SetColor(0.0, 1.0, 1.0);
	S2_DrawLine(100, 100, 200, 300);
	S2_DrawTexture(300, 300, 256, 256, tex_2d);
	glFlush();  //�͵�����GLUT_SINGLE ���ʹ��
	glutSwapBuffers(); //��˫����GLUT_DOUBLE���ʹ��
}
void main(int argc, char **argv) {
	const float texcolor[] = { 1.0, 1.0, 1.0, 1.0 };

	glutInit(&argc, argv);

	//glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);   //������
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);  //˫����
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Aying GLUT Tutorial");     //glutCreateWindow(argv[0]);    
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	glutDisplayFunc(renderScene);  //renderScene�ǻص�����     
	glDisable(GL_DEPTH_TEST); // ȥ����ȼ�⣬��2d
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, texcolor);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glEnable(GL_BLEND);
	tex_2d = SOIL_load_OGL_texture
		(
		"../res/fuck.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

	glutMainLoop();

}

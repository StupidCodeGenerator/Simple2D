#include <GL/glut.h>
#include <stdio.h>
#include <Windows.h>
#include "2DInterface.h"

GLuint tex_2d;

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);    //清除上次显示的结果，每次绘制前都必须调用      
	glClearColor(0.0, 0.0, 0.0, 0.0);  //此句注释掉对结果没有影响,说明默认的“清除颜色为黑色”
	glClear(GL_COLOR_BUFFER_BIT);    //清除上次显示的结果，每次绘制前都必须调用    
	S2_SetColor(1.0, 0.0, 0.0);
	S2_DrawTriangle(30, 30, 400, 40, 50, 250);
	S2_SetColor(0.0, 1.0, 0.0);
	S2_DrawRect(100, 100, 300, 200);
	S2_SetColor(0.0, 1.0, 1.0);
	S2_DrawLine(100, 100, 200, 300);
	glFlush();  //和单缓冲GLUT_SINGLE 配合使用
	glutSwapBuffers(); //和双缓冲GLUT_DOUBLE配合使用
}
void main(int argc, char **argv) {
	const float texcolor[] = { 1.0, 1.0, 1.0, 1.0 };

	glutInit(&argc, argv);

	//glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);   //单缓冲
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);  //双缓冲
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Aying GLUT Tutorial");     //glutCreateWindow(argv[0]);    
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	glutDisplayFunc(renderScene);  //renderScene是回调函数     
	glDisable(GL_DEPTH_TEST); // 去掉深度检测，纯2d
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, texcolor);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glEnable(GL_BLEND);


	glutMainLoop();

}

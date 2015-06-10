#include <GL/glut.h>
#include <stdio.h>
//#include <Windows.h>
#include "2DInterface.h"

S2_Texture * pTestTexture;
S2_Texture * pSpriteTexture;
S2_SpriteSheet * pTestSpriteSheet;

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);    //
    glClearColor(0.0, 0.0, 0.0, 0.0);  //
    glClear(GL_COLOR_BUFFER_BIT);    //
    S2_SetColor(1.0, 0.0, 0.0);
    S2_DrawTriangle(30, 30, 400, 40, 50, 250);
    S2_SetColor(0.0, 1.0, 0.0);
    S2_DrawRect(100, 100, 300, 200);
    S2_SetColor(0.0, 1.0, 1.0);
    S2_DrawLine(100, 100, 200, 300);
    S2_DrawTexture(300, 300, pTestTexture);
    S2_DrawSprite(&pTestSpriteSheet->pSprites[0], 300, 500);
    //S2_DrawLimitedTexture(500, 500, 0.0f, 0.5f, 0.5f, 0.0f, pTestTexture);
    glFlush();  //
    glutSwapBuffers(); //
}
int main(int argc, char **argv) {
    const float texcolor[] = { 1.0, 1.0, 1.0, 1.0 };

    glutInit(&argc, argv);

    //glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);   //µ¥»º³å
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);  //Ë«»º³å
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Aying GLUT Tutorial");     //glutCreateWindow(argv[0]);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glutDisplayFunc(renderScene);  //
    glDisable(GL_DEPTH_TEST); //
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, texcolor);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glEnable(GL_BLEND);

    pTestTexture = S2_LoadTextureFromFile("../res/fuck.png", 256, 256);
    pSpriteTexture = S2_LoadTextureFromFile("../res/textureTest.png", 1024, 1024);
    pTestSpriteSheet = S2_LoadSpriteSheetFromFile("../res/textureTest.xml", pSpriteTexture);

    glutMainLoop();
    return 0;
}

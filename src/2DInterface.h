#ifndef __2D_INTERFACE_H__
#define __2D_INTERFACE_H__
#define _CRT_SECURE_NO_WARNINGS

#define MAX_SPRITE_SHEET 0xff

#include<GL/glut.h>
#include<stdio.h>
#include"SOIL.h"

// The SetColor(float, float, float) function will change them
// And the paint procedure will paint the shapes based on that

// S2 means Simple 2D

extern float S2_Color_r;
extern float S2_Color_g;
extern float S2_Color_b;




void S2_SetColor(const float r, const float g, const float b);

void S2_DrawTriangle(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3);
void S2_DrawRect(const float x1, const float y1, const float x2, const float y2);
void S2_DrawLine(const float x1, const float y1, const float x2, const float y2);

class S2_Texture {
public:
	GLuint textureName;
	int width;
	int height;
};

// the width and height should be well known before load
S2_Texture* S2_LoadTextureFromFile(char * fileName, int texWidth, int texHeight);

void S2_DrawTexture(const float x, const float y, S2_Texture * texture);
void S2_DrawLimitedTexture(const float x, const float y,
	float left, float right, float top, float bottom,
	S2_Texture * texture);

class S2_Sprite {
public:
	S2_Texture* texture;
	float xLB, yLB, xRB, yRB, xRT, yRT, xLT, yLT; // Texture range
	bool isRotated;
};

class S2_SpriteSheet {
public:
	S2_Sprite sprites[MAX_SPRITE_SHEET];
	int length;
};


#endif
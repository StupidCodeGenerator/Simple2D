#ifndef __2D_INTERFACE_H__
#define __2D_INTERFACE_H__
#define _CRT_SECURE_NO_WARNINGS

#define MAX_SPRITE_SHEET 0xff

#include<GL/glut.h>
#include<stdio.h>
#include"SOIL.h"
#include"tinyxml2.h"
#include "Transactions.h"

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
	S2_Vector2 *plb, S2_Vector2 *prb, S2_Vector2 *prt, S2_Vector2 *plt,
	S2_Texture * texture);

class S2_Sprite {
public:
	const char *pSpriteName;
	S2_Texture *pTexture;
	S2_Vector2 vlb, vrb, vrt, vlt;
	S2_Vector2 vo;
	float originalWidth, originalHeight;
	bool isRotated;
};

class S2_SpriteSheet {
public:
	S2_Sprite * pSprites;
	int length;
};

S2_SpriteSheet * S2_LoadSpriteSheetFromFile(char * fileName, S2_Texture * pTexture);
void S2_DrawSprite(const S2_Sprite *pSprite, float x, float y);

#endif
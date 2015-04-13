#ifndef __2D_INTERFACE_H__
#define __2D_INTERFACE_H__
#define _CRT_SECURE_NO_WARNINGS
#include<GL/glut.h>
#include<stdio.h>
#include"SOIL.h"

// The SetColor(float, float, float) function will change them
// And the paint procedure will paint the shapes based on that

// S2 means Simple 2D

extern float S2_Color_r;
extern float S2_Color_g;
extern float S2_Color_b;

// This is the comment from that xml file
//n = > name of the sprite
//x = > sprite x pos in texture
//y = > sprite y pos in texture
//w = > sprite width(may be trimmed)
//h = > sprite height(may be trimmed)
//oX = > sprite's x-corner offset (only available if trimmed)
//oY = > sprite's y-corner offset (only available if trimmed)
//oW = > sprite's original width (only available if trimmed)
//oH = > sprite's original height (only available if trimmed)
//r = > 'y' only set if sprite is rotated
typedef struct {
	char* spriteName;
	float x, y, width, height; // [0,1]
	float ox, oy, owidth, oheight; // [0,1]
	bool isRotated;
} S2_Sprite;

typedef struct {
	S2_Sprite * spriteList;
	int length;
} S2_SpriteSheet;

S2_SpriteSheet * S2_LoadSprites(const char* fileName);

void S2_SetColor(const float r, const float g, const float b);

void S2_DrawTriangle(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3);
void S2_DrawRect(const float x1, const float y1, const float x2, const float y2);
void S2_DrawLine(const float x1, const float y1, const float x2, const float y2);

void S2_DrawTexture(const float x, const float y, const float width, const float height, GLuint textureName);

#endif
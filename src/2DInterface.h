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

namespace Simple2D {


void S2SetColor(float r, float g, float b);

void S2DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
void S2DrawRect(float x1, float y1, float x2, float y2);
void S2DrawLine(float x1, float y1, float x2, float y2);

class S2Texture {
public:
    explicit S2Texture() : textureName(NULL), width(0), height(0) {}
    static S2Texture* LoadTextureFromFile(char * fileName, int texWidth, int texHeight);
    void S2DrawTexture(float x, float y);
    void S2DrawLimitedTexture(float x, float y,
                               float xLB, float yLB,
                               float xRB, float yRB,
                               float xRT, float yRT,
                               float xLT, float yLT);

private:
	GLuint textureName;
	int width;
	int height;
};

// the width and height should be well known before load


class S2Sprite {
public:

private:
	S2Texture* texture;
	float xLB, yLB, xRB, yRB, xRT, yRT, xLT, yLT; // Texture range
	bool isRotated;
};

class S2SpriteSheet {
private:
	S2Sprite sprites[MAX_SPRITE_SHEET];
	int length;
};

}

#endif   //  #endif __2D_INTERFACE_H__


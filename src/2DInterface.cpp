// The version 0.1 will use center anchor point as default.

#include "2DInterface.h"

static int float g_S2Color_r = 0.0f;
static float g_S2Color_g = 0.0f;
static float g_S2Color_b = 0.0f;

void S2SetColor(float r, float g, float b) {
	g_S2Color_r = r;
	g_S2Color_g = g;
	g_S2Color_b = b;
}

void S2DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {

	glBegin(GL_TRIANGLES);
	glColor3f(g_S2Color_r, g_S2Color_g, g_S2Color_b);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}

void S2DrawRect(float x1, float y1, float x2, float y2) {
	glBegin(GL_POLYGON);
	glColor3f(g_S2Color_r, g_S2Color_g, g_S2Color_b);
	glVertex2f(x1, y1);
	glVertex2f(x1, y2);
	glVertex2f(x2, y2);
	glVertex2f(x2, y1);
	glEnd();
}

void S2DrawLine(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINES);
	glColor3f(g_S2Color_r, g_S2Color_g, g_S2Color_b);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

S2Texture* S2Texture::LoadTextureFromFile(char* fileName, int texWidth, int texHeight) {
	GLuint textureName = SOIL_load_OGL_texture
		(
		//"../res/fuck.png",
		fileName,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
	S2Texture * result = new S2Texture();
	result->textureName = textureName;
	result->width = texWidth;
	result->height = texHeight;
	return result;
}

void S2Texture::S2DrawTexture(float x, float y) {
	S2DrawLimitedTexture(
		x, y,
		0.0f, 0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f, 1.0f);
}

void S2Texture::S2DrawLimitedTexture(float x, float y,
	float xLB, float yLB,
	float xRB, float yRB,
	float xRT, float yRT,
	float xLT, float yLT) {
	// Calculate vertexes
	float width = this->width;
	float height = this->height;
	float vertexBLx = x - width / 2;
	float vertexBLy = y - height / 2;
	float vertexBRx = x + width / 2;
	float vertexBRy = y - height / 2;
	float vertexTRx = x + width / 2;
	float vertexTRy = y + height / 2;
	float vertexTLx = x - width / 2;
	float vertexTLy = y + height / 2;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->textureName);
	glBegin(GL_QUADS);

	glTexCoord2f(xLB, yLB); glVertex2f(vertexBLx, vertexBLy);
	glTexCoord2f(xRB, yRB); glVertex2f(vertexBRx, vertexBRy);
	glTexCoord2f(xRT, yRT); glVertex2f(vertexTRx, vertexTRy);
	glTexCoord2f(xLT, yLT); glVertex2f(vertexTLx, vertexTLy);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}


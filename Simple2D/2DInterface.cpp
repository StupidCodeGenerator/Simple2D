// The version 0.1 will use center anchor point as default.

#include "2DInterface.h"

float S2_Color_r = 0.0f;
float S2_Color_g = 0.0f;
float S2_Color_b = 0.0f;

void S2_SetColor(float r, float g, float b) {
	S2_Color_r = r;
	S2_Color_g = g;
	S2_Color_b = b;
}

void S2_DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {

	glBegin(GL_TRIANGLES);
	glColor3f(S2_Color_r, S2_Color_g, S2_Color_b);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}

void S2_DrawRect(float x1, float y1, float x2, float y2) {
	glBegin(GL_POLYGON);
	glColor3f(S2_Color_r, S2_Color_g, S2_Color_b);
	glVertex2f(x1, y1);
	glVertex2f(x1, y2);
	glVertex2f(x2, y2);
	glVertex2f(x2, y1);
	glEnd();
}

void S2_DrawLine(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINES);
	glColor3f(S2_Color_r, S2_Color_g, S2_Color_b);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void S2_DrawTexture(float x, float y, float width, float height, GLuint textureName) {
	// Calculate vertexes
	float vertexBLx = x - width / 2;
	float vertexBLy = y - height / 2;
	float vertexBRx = x + width / 2;
	float vertexBRy = y - height / 2;
	float vertexTRx = x + width / 2;
	float vertexTRy = y + height / 2;
	float vertexTLx = x - width / 2;
	float vertexTLy = y + height / 2;
	glBindTexture(GL_TEXTURE_2D, textureName);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(vertexBLx, vertexBLy);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(vertexBRx, vertexBRy);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(vertexTRx, vertexTRy);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(vertexTLx, vertexTLy);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}
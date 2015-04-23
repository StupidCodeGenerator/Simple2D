// The version 0.1 will use center anchor point as default.

#include "2DInterface.h"

float S2_Color_r = 0.0f;
float S2_Color_g = 0.0f;
float S2_Color_b = 0.0f;

void S2_SetColor(const float r, const float g, const float b) {
	S2_Color_r = r;
	S2_Color_g = g;
	S2_Color_b = b;
}

void S2_DrawTriangle(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3) {

	glBegin(GL_TRIANGLES);
	glColor3f(S2_Color_r, S2_Color_g, S2_Color_b);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}

void S2_DrawRect(const float x1, const float y1, const float x2, const float y2) {
	glBegin(GL_POLYGON);
	glColor3f(S2_Color_r, S2_Color_g, S2_Color_b);
	glVertex2f(x1, y1);
	glVertex2f(x1, y2);
	glVertex2f(x2, y2);
	glVertex2f(x2, y1);
	glEnd();
}

void S2_DrawLine(const float x1, const float y1, const float x2, const float y2) {
	glBegin(GL_LINES);
	glColor3f(S2_Color_r, S2_Color_g, S2_Color_b);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

S2_Texture* S2_LoadTextureFromFile(char* fileName, int texWidth, int texHeight) {
	GLuint textureName = SOIL_load_OGL_texture
		(
		//"../res/fuck.png",
		fileName,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
	S2_Texture * result = new S2_Texture;
	result->textureName = textureName;
	result->width = texWidth;
	result->height = texHeight;
	return result;
}

void S2_DrawTexture(const float x, const float y, S2_Texture* texture) {
	S2_DrawLimitedTexture(
		x, y,
		0.0f, 1.0f, 1.0f, 0.0f,
		texture);
}

void S2_DrawLimitedTexture(const float x, const float y,
	float left, float right, float top, float bottom,
	S2_Texture * texture) {
	// Calculate vertexes
	float width = (texture->width) * (right - left);
	float height = (texture->height) * (top - bottom);
	float vertexBLx = x - width / 2;
	float vertexBLy = y - height / 2;
	float vertexBRx = x + width / 2;
	float vertexBRy = y - height / 2;
	float vertexTRx = x + width / 2;
	float vertexTRy = y + height / 2;
	float vertexTLx = x - width / 2;
	float vertexTLy = y + height / 2;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture->textureName);
	glBegin(GL_QUADS);

	glTexCoord2f(left, bottom); glVertex2f(vertexBLx, vertexBLy);
	glTexCoord2f(right, bottom); glVertex2f(vertexBRx, vertexBRy);
	glTexCoord2f(right, top); glVertex2f(vertexTRx, vertexTRy);
	glTexCoord2f(left, top); glVertex2f(vertexTLx, vertexTLy);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}

S2_SpriteSheet * S2_LoadSpriteSheetFromFile(char* fileName, S2_Texture * pTexture) {
	tinyxml2::XMLDocument * xDoc = new tinyxml2::XMLDocument();
	xDoc->LoadFile(fileName);
	tinyxml2::XMLElement * pSpriteRoot = xDoc->LastChild()->ToElement();
	tinyxml2::XMLElement * pChildEle = pSpriteRoot->FirstChildElement();
	S2_SpriteSheet * pResult = new S2_SpriteSheet();
	int spriteCount = 0;
	pResult->pSprites = new S2_Sprite[MAX_SPRITE_SHEET];
	while (pChildEle != NULL) {
		S2_Sprite * pSprite = new S2_Sprite();
		pSprite->pSpriteName = pChildEle->Attribute("n");
		float x = atof(pChildEle->Attribute("x"));
		float y = atof(pChildEle->Attribute("y"));
		float w = atof(pChildEle->Attribute("w"));
		float h = atof(pChildEle->Attribute("h"));
		float oX, oY, oW, oH;
		if (pChildEle->Attribute("oX") != NULL) {
			oX = atof(pChildEle->Attribute("oX"));
			oY = atof(pChildEle->Attribute("oY"));
			oW = atof(pChildEle->Attribute("oW"));
			oH = atof(pChildEle->Attribute("oH"));
		}
		else {
			oX = x, oY = y, oW = w, oH = h;
		}
		pSprite->isRotated = FALSE;
		if (pChildEle->Attribute("r") != NULL) {
			pSprite->isRotated = (pChildEle->Attribute("r")[0] == 'y');
		}
		pChildEle = pChildEle->NextSiblingElement();
	}
	return NULL;
}
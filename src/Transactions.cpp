#include "Transactions.h"

S2_Vector2 S2_CreateEmptyVector2() {
	S2_Vector2 result;
	result.x = 0;
	result.y = 0;
	return result;
}

S2_Vector2 S2_CreateVector2(const float x, const float y) {
	S2_Vector2 result;
	result.x = x;
	result.y = y;
	return result;
}
S2_Vector2 S2_NegativeVector2(const S2_Vector2* v) {
	S2_Vector2 result;
	result.x = -v->x;
	result.y = -v->y;
	return result;
}
S2_Vector2 S2_AddVector2(const S2_Vector2* v1, const S2_Vector2* v2) {
	S2_Vector2 result;
	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	return result;
}
S2_Vector2 S2_SubVector2(const S2_Vector2* vl, const S2_Vector2* vr) {
	S2_Vector2 result;
	result.x = vl->x - vr->x;
	result.y = vl->y - vr->y;
	return result;
}


S2_Bound S2_CreateEmptyBound() {
	S2_Bound result;
	result.left = 0;
	result.right = 0;
	result.top = 0;
	result.bottom = 0;
	return result;
}

S2_Bound S2_CreateBound(const float left, const float right, const float top, const float bottom) {
	S2_Bound result;
	result.left = left;
	result.right = right;
	result.top = top;
	result.bottom = bottom;
	return result;
}

// Translate the left top coordiante into the left bottom coordinate.
// The screen use left top as the (0,0), but opengl use the left bottom one.
S2_Vector2 S2_LeftTopToLeftBottomTransaction(const S2_Vector2* vlt, const float worldHeight) {
	S2_Vector2 result;
	result.x = vlt->x;
	result.y = worldHeight - vlt->y;
	return result;
}

// Translate the pixel coordinate into the openGL texture coordinate[0,0]~[1,1]
S2_Vector2 S2_PixelVectorToTextureVector(const S2_Vector2 *v, const float textureWidth, const float textureHeight) {
	S2_Vector2 result;
	result.x = v->x / textureWidth;
	result.y = v->y / textureHeight;
	return result;
}

S2_Bound S2_PixelBoundToTextureBound(S2_Bound pixelBound, float textureWidth, float textureHeight) {
	S2_Bound result;
	result.left = pixelBound.left / textureWidth;
	result.right = pixelBound.right / textureWidth;
	result.top = pixelBound.top / textureHeight;
	result.bottom = pixelBound.bottom / textureHeight;
	return result;
}


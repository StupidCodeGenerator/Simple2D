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

S2_Vector2 S2_LeftTopToLeftBottomTransaction(const S2_Vector2* vlt, const float worldHeight) {
	S2_Vector2 result;
	result.x = vlt->x;
	result.y = worldHeight - vlt->y;
	return result;
}

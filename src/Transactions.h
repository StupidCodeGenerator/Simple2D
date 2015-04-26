#ifndef __TRANSACTIONS_H__
#define __TRANSACTIONS_H__

typedef struct {
	float x;
	float y;
} S2_Vector2;

S2_Vector2* S2_CreateEmptyVector2();
S2_Vector2* S2_CreateVector2(const float x, const float y);
S2_Vector2* S2_NegativeVector2(const S2_Vector2* pV);
S2_Vector2* S2_AddVector2(const S2_Vector2 *pV1, const S2_Vector2 *pV2);
S2_Vector2* S2_SubVector2(const S2_Vector2 *pVl, const S2_Vector2 *pVr);

S2_Vector2* S2_LeftTopToLeftBottomTransaction(const S2_Vector2* vlt, const float worldHeight);

#endif
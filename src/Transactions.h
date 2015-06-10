#ifndef __TRANSACTIONS_H__
#define __TRANSACTIONS_H__

#define PIXEL_TO_TEXTURE_COOR(a, b) (a)/(b)

typedef struct {
    float x;
    float y;
} S2_Vector2;

S2_Vector2 S2_CreateEmptyVector2();
S2_Vector2 S2_CreateVector2(float x, float y);
S2_Vector2 S2_NegativeVector2(const S2_Vector2 *pV);
S2_Vector2 S2_AddVector2(const S2_Vector2 *pV1, const S2_Vector2 *pV2);
S2_Vector2 S2_SubVector2(const S2_Vector2 *pVl, const S2_Vector2 *pVr);

typedef struct {
    float left;
    float right;
    float top;
    float bottom;
} S2_Bound;

S2_Bound S2_CreateEmptyBound();
S2_Bound S2_CreateBound(float left, float right, float top, float bottom);
S2_Bound S2_ScaleBoundByTextureSize(S2_Bound *pBound, float textureWidth, float textureHeight);

// Translate the left top coordiante into the left bottom coordinate.
// The screen use left top as the (0,0), but opengl use the left bottom one.
S2_Vector2 S2_LeftTopToLeftBottomTransaction(const S2_Vector2 *vlt, float worldHeight);

// Translate the pixel coordinate into the openGL texture coordinate[0,0]~[1,1]
S2_Vector2 S2_PixelVectorToTextureVector(const S2_Vector2 *v, float textureWidth, float textureHeight);

S2_Bound S2_PixelBoundToTextureBound(S2_Bound pixelBound, float textureWidth, float textureHeight);

#endif  // #endif __TRANSACTIONS_H__

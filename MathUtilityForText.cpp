#include "MathUtilityForText.h"

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate)
{

    Vector3 dm;
    dm = scale;
   
    Matrix4x4 RotateMatY = {
     cosf(rot.y), 0, -sinf(rot.f), 0,
     0,1,0,0,
     sinf(rot.y), 0, cosf(rot.f), 0,
     0,0,0,1
    };

    return result;
}

Vector3& operator+=(Vector3& lhv, const Vector3& rhv)
{
    lhv.x += rhv.x;
    lhv.y += rhv.y;
    lhv.z += rhv.z;
    return lhv;
}

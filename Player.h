#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"


class Player {

public:
    void Initialize(Model* model, uint32_t textureHandle_, ViewProjection* viewProjection_, const Vector3& position);
    void Update();
    void Draw();
private:
    //ワールド変換データ
    WorldTransform worldTransform_;
    //モデル
    Model* model_ = nullptr;
    //テクスチャハンドル
    uint32_t textureHandle_ = 0u;

    ViewProjection* viewProjection_ = nullptr;

    Vector3 velocity_ = {};
    static inline const float kAcceleration = 0.01f;
    static inline const float kAttenuation = 0.03f;
    static inline const float kLimitRunSpeed = 0.5f;
};


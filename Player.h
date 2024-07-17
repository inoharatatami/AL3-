#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"


class Player {

public:
    void Initialize(Model* model, uint32_t textureHandle_, ViewProjection* viewProjection_, const Vector3& position);
    void Update();
    void Draw(WorldTransform worldTransform_, ViewProjection* viewProjection_, uint32_t textureHandle_);
private:
    //ワールド変換データ
    WorldTransform worldTransform_;
    //モデル
    Model* model_ = nullptr;
    //テクスチャハンドル
    uint32_t textureHandle_ = 0u;

    ViewProjection* viewProjection_ = nullptr;

    Vector3 velocity_ = {};
    static inline const float kAcceleration = 1;
};


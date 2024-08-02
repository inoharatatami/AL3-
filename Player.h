#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"


class Player {

public:
    void Initialize(Model* model, uint32_t textureHandle_, ViewProjection* viewProjection_, const Vector3& position);
    void Update();
    void Draw();

    enum class LRDirection{
     kRight,
     kLeft,
    };

private:
    LRDirection lrDirection_ = LRDirection::kRight;
    //ワールド変換データ
    WorldTransform worldTransform_;
    //モデル
    Model* model_ = nullptr;
    //テクスチャハンドル
    uint32_t textureHandle_ = 0u;

    ViewProjection* viewProjection_ = nullptr;

    float turnFirstRotationY_  =0.0f;
    float turnTimer_ = 0.0f;

    static inline const float kTimeTurn = 0.3f;

    Vector3 velocity_ = {};
    static inline const float kAcceleration = 0.01f;
    static inline const float kAttenuation = 0.03f;
    static inline const float kLimitRunSpeed = 0.3f;

    bool onGround_ = true;
    static inline const float kGravityAcceleration = 0.02f;
    static inline const float kLimitFallSpeed = 5.0f;
    static inline const float kJumpAcceleration = 0.4f;
};


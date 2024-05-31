#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"

///<summaru>
///自キャラ
///<summaru>


class Player {

public:
    ///<summaru>
    ///自キャラ
    ///<summaru>
    void Initialize(Model* model, uint32_t textureHandle_, ViewProjection* viewProjection_);

    ///<summaru>
    ///自キャラ
    ///<summaru>
    void Update();

    ///<summaru>
    ///自キャラ
    ///<summaru>
    void Draw(WorldTransform worldTransform_, ViewProjection* viewProjection_, uint32_t textureHandle_);



private:
    //ワールド変換データ
    WorldTransform worldTransform_;
    //モデル
    Model* model_ = nullptr;
    //テクスチャハンドル
    uint32_t textureHandle_ = 0u;

    ViewProjection* viewProjection_ = nullptr;
};


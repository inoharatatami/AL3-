#include "Player.h"
#include "cassert"
#include<numbers>
#include"MathUtilityForText.h"
#include"Input.h"



void Player::Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection, const Vector3& position)
{
	assert(model);

	model_ = model;
	textureHandle_ = textureHandle;
	viewProjection_ = viewProjection;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;
	

}

void Player::Update()
{
	//移動入力
	if(Input::GetInstance()->PushKey(DIK_D) ||
		Input::GetInstance()->PushKey(DIK_A)){
	 //左右加速
		Vector3 acceleration = {};
		if(Input::GetInstance() -> PushKey(DIK_D)){
			acceleration.x += kAcceleration;
		}else if(Input::GetInstance()->PushKey(DIK_A)){
			acceleration.x -= kAcceleration;
		}
		velocity_ += acceleration;
	}
	//移動
	worldTransform_.translation_ += velocity_;
	//行列計算
	worldTransform_.UpdateMatrix();
}
void Player::Draw(WorldTransform worldTransform, ViewProjection* viewProjection, uint32_t textureHandle)
{
	model_->Draw(worldTransform, *viewProjection, textureHandle);
}



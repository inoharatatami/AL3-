#define NOMINMAX
#include "Player.h"
#include "cassert"
#include<numbers>
#include"MathUtilityForText.h"
#include"Input.h"
#include"algorithm"

#include<Windows.h>



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
	if (onGround_) {
		//移動入力
		if (Input::GetInstance()->PushKey(DIK_D) ||
			Input::GetInstance()->PushKey(DIK_A)) {
			//左右加速
			Vector3 acceleration = {};
			if (Input::GetInstance()->PushKey(DIK_D)) {
				if (velocity_.x < 0.0f) {
					velocity_.x *= (1.0f - kAttenuation);
				}
				acceleration.x += kAcceleration;

				if (lrDirection_ != LRDirection::kRight) {
					lrDirection_ = LRDirection::kRight;
					turnFirstRotationY_ = worldTransform_.rotation_.y;
					turnTimer_ = kTimeTurn;

				}

			}
			else if (Input::GetInstance()->PushKey(DIK_A)) {
				if (velocity_.x > 0.0f) {
					velocity_.x *= (1.0f - kAttenuation);
				}
				acceleration.x -= kAcceleration;

				if (lrDirection_ != LRDirection::kLeft) {
					lrDirection_ = LRDirection::kLeft;
					turnFirstRotationY_ = worldTransform_.rotation_.y;
					turnTimer_ = kTimeTurn;
				}

			}
			velocity_ += acceleration;
			velocity_.x = std::clamp(velocity_.x, -kLimitRunSpeed, kLimitRunSpeed);
		}
		else {
			velocity_.x *= (1.0f - kAttenuation);
		}

		if (turnTimer_ > 0.0f)
		{
			turnTimer_ -= 1.0f / 60.0f;
			float destinationRotationYTable[] = {
			   std::numbers::pi_v<float> / 2.0f,
			   std::numbers::pi_v<float> *3.0f / 2.0f
			};
			float destinationRotationY = destinationRotationYTable[static_cast<uint32_t>(lrDirection_)];
			worldTransform_.rotation_.y = EaseInOut(destinationRotationY, turnFirstRotationY_, turnTimer_ / kTimeTurn);
		}

		if(Input::GetInstance() -> PushKey(DIK_SPACE)){
			velocity_ += Vector3(0, kJumpAcceleration, 0);
		}
		//空中
	}else{
		velocity_ += Vector3(0, -kGravityAcceleration, 0);
		velocity_.y = std::max(velocity_.y, -kLimitFallSpeed);
	}
	
	//着地フラグ
	bool landing = false;
	if(velocity_.y < 0){
	 if(worldTransform_.translation_.y <= 1.0f){
		 landing = true;
	 }
	}
	//設置判定
	if(onGround_){
	 if(velocity_.y>0.0f){
		 onGround_ = false;
	 }
	}else{
	 if(landing){
		 worldTransform_.translation_.y = 1.0f;
		 velocity_.x *= (1.0f - kAttenuation);
		 velocity_.y = 0.0f;
		 onGround_ = true;
	 }
	}



	//移動
	worldTransform_.translation_ += velocity_;
	//行列計算
	worldTransform_.UpdateMatrix();

	


}
void Player::Draw()
{
	model_->Draw(worldTransform_, *viewProjection_);
}



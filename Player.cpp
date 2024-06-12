#include "Player.h"
#include "cassert"


void Player::Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection)
{
	assert(model);

	model_ = model;
	textureHandle_ = textureHandle;
	viewProjection_ = viewProjection;
	worldTransform_.Initialize();
}
void Player::Update()
{
	worldTransform_.TransferMatrix();
}
void Player::Draw(WorldTransform worldTransform, ViewProjection* viewProjection, uint32_t textureHandle)
{
	model_->Draw(worldTransform, *viewProjection, textureHandle);
}



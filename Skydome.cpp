#include "Skydome.h"

void Skydome::Initialize(Model* modelSkydome, uint32_t Skydome_3d, ViewProjection* viewProjection)
{
	modelSkydome_ = modelSkydome;
	Skydome_3d_ = Skydome_3d;
	viewProjection_ = viewProjection;
	worldTransform_.Initialize();
}

void Skydome::Update()
{
	worldTransform_.TransferMatrix();
}

void Skydome::Draw(WorldTransform worldTransform)
{
	modelSkydome_->Draw(worldTransform_, *viewProjection_ );
}

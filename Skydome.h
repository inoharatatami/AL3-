#pragma once
#include"WorldTransform.h"
#include <Model.h>
#include "ViewProjection.h"

class Skydome{
public:
	void Initialize(Model* modelSkydome_, uint32_t Skydome_3d_, ViewProjection* viewProjection_);
	void Update();
	void Draw(WorldTransform worldTransform_);

private:
	WorldTransform worldTransform_;
	Model* modelSkydome_ = nullptr;
	uint32_t Skydome_3d_ = 0;

	ViewProjection* viewProjection_ = nullptr;
};
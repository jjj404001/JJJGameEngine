#pragma once
#include "Vector2.hpp"
#include "Affine2d.hpp"

class Transform
{
	friend class Object;
	friend class Renderer;

	Vector2 translation_ = Vector2(0.0f, 0.0f);
	float rotation_   = 0.0f;
	Vector2 scale_ = { 1.0f , 1.0f };

public:
	void SetTranslation(const Vector2 input) { translation_ = input; };
	void SetRotation(const float input) { rotation_ = input; };
	
	void SetScale(const Vector2 input) { scale_ = input; };

	Vector2 GetScale() { return scale_; };
	float GetRotation() { return rotation_; };
	Vector2 GetTranslation() { return translation_; };

	Affine2d GetModelToWorld() const;
};

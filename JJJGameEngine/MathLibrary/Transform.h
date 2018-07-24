#pragma once
#include "Vector2.hpp"
#include "Affine2d.hpp"

class Transform
{
	friend class Object;
	friend class Graphics;

	Vector3 translation_ = Vector3(0.0f, 0.0f, 0.0f);
	float rotation_   = 0.0f;
	Vector3 scale_ = { 1.0f , 1.0f , 1.0f};

public:
	void SetTranslation(const Vector3 input);
	void SetRotation(const float input);
	
	void SetScale(const Vector3 input);

	Vector3 GetScale() { return scale_; };
	float GetRotation() { return rotation_; };
	Vector3 GetTranslation() { return translation_; };

	Affine2d GetModelToWorld() const;
};

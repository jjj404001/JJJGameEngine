#include "Transform.h"


Affine2d Transform::GetModelToWorld() const
{
	// Calculate translate, rotation, scale;
	const Affine2d model_translate = Affine2d::build_affine_translation(translation_.x, translation_.y);
	const Affine2d model_rotation = Affine2d::build_rotation(rotation_);
	const Affine2d model_scale = Affine2d::build_scale(scale_.x, scale_.y);



	// Model to world matrix.
	const Affine2d model_matrix = model_translate * model_rotation * model_scale;









	return model_matrix;
}

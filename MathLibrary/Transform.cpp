#include "Transform.h"


affine2d Transform::GetModelToWorld() const
{
	// Calculate translate, rotation, scale;
	affine2d model_translate = affine2d::build_affine_translation(translation_.x, translation_.y);
	affine2d model_rotation = affine2d::build_affine_rotation(rotation_);
	affine2d model_scale = affine2d::build_affine_scale(scale_.x, scale_.y);



	// Model to world matrix.
	affine2d model_matrix = model_translate * model_rotation * model_scale;









	return model_matrix;
}

#version 400 core
layout(location = 0) in vec3 input_position;
layout(location = 1) in vec4 input_color;

out vec4 color_for_fragment;

void main() 
{
     gl_Position = vec4(input_position, 1.0);
     color_for_fragment = input_color;
}
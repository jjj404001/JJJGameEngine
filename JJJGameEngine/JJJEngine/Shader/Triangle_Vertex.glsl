#version 400 core
layout(location = 0) in vec3 input_position;
layout(location = 1) in vec4 input_color;

out vec4 color_for_TC;

void main() 
{
     gl_Position = vec4(input_position, 1.0);
     color_for_TC = input_color;
}
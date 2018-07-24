#version 400 core
layout(location = 0) in vec3 input_position;
layout(location = 1) in vec4 input_color;

out vec4 color_for_TC;

uniform mat4 combined;

void main() 
{
    vec4 position = combined * vec4(input_position, 1.0);
    gl_Position = vec4(position.xyz, 1.0);
    color_for_TC = input_color;
}
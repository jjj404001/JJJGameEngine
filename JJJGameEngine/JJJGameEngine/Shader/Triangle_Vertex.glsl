#version 400 core
layout(location = 0) in vec3 position

void main() 
{
    // gl_Position = vertices[gl_VertexID];
    gl_Position = vec4(position, 1.0);
}
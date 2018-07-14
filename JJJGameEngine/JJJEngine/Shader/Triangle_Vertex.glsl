#version 400 core
layout(location = 0) in vec3 position;

void main() 
{
     gl_Position = vec4(position, 1.0);
}

// #version 400 core

// void main() 
// {
//     const vec4 vertices[3] = vec4[3](vec4(0.25, -0.25, 0.5, 1.0),
//                                      vec4(-0.25, -0.25, 0.5, 1.0),
//                                      vec4(0.25, 0.25, 0.5, 1.0));

//     gl_Position = vertices[gl_VertexID];
// }
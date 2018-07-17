#version 400 core

layout (triangles) in;
layout (points, max_vertices = 3) out;

in vec4 color_for_GE[];
out vec4 color_for_Frag[];

void main() 
{
    int i;

    for(i = 0; i < gl_in.length(); i++)
    {
        gl_Position = gl_in[i].gl_Position;
        EmitVertex();
    }

    color_for_Frag = color_for_GE;
}
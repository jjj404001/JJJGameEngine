#version 400 core
// Setup tesselation mode.
layout (triangles, equal_spacing, cw) in;

in vec4 color_for_TE[];
out vec4 color_for_GE;

void main() 
{
    gl_Position = (gl_TessCoord.x * gl_in[0].gl_Position +
                   gl_TessCoord.y * gl_in[1].gl_Position +
                   gl_TessCoord.z * gl_in[2].gl_Position);


    color_for_GE = vec4(0);
    color_for_GE += gl_TessCoord.x * color_for_TE[0];
    color_for_GE += gl_TessCoord.y * color_for_TE[1];
    color_for_GE += gl_TessCoord.z * color_for_TE[2];
}
#version 400 core
// ouput control point. 3 is default
layout (vertices = 3) out;

in vec4 color_for_TC[];
out vec4 color_for_TE[];

void main() 
{
    // gl_InvocationID is 0 based index for control points inside patch.
    if(gl_InvocationID == 0)
    {
        gl_TessLevelInner[0] = 5.0;

        gl_TessLevelOuter[0] = 5.0;
        gl_TessLevelOuter[1] = 5.0;
        gl_TessLevelOuter[2] = 5.0;
    }

    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;

    color_for_TE[gl_InvocationID] = color_for_TC[gl_InvocationID];
}
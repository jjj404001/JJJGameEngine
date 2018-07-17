#version 400 core

in vec4 color_for_GE;

void main() 
{
    gl_FragColor  = color_for_GE / 255;
}
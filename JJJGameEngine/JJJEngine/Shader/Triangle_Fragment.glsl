#version 400 core

in vec4 color_for_fragment;

void main() 
{
    gl_FragColor = color_for_fragment / 255;
}
#version 130

in vec2 fragposition;
in vec4 fragColor;
in vec2 fragUV;

out vec4 color;

uniform sampler2D Text;
void main(){
vec4 textcolour= texture(Text,fragUV);
//fragColor = vec4();
color = textcolour+fragColor;
}
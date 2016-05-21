#version 130

out vec4 color;
in vec4 fragColor;
uniform float time;
void main(){
color = fragColor+vec4(0.5*(cos(time)+1.0),0.0,0.0,-1.0*(cos(time)+1.0)*0.5);
//color = vec4(1.0,0.0,1.0,1.0);
}
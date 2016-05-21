#version 130

in vec2 vertexPos;
in vec4 vertexColor;
out vec4 fragColor;
uniform float time;
void main(){
	gl_Position.xy = vertexPos;
	gl_Position.z = 0.0;
	gl_Position.w = 1.0;
	fragColor=vertexColor;
}




#version 330
layout (location =0) in vec3 pos;
layout (location =1) in vec3 color;
out vec4 vColor;

void main()
{
	gl_Position=vec4(pos.x,pos.y,pos.z,1.0f);
	vColor=vec4(color,1.0f);
}
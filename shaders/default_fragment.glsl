#version 330 core
in vec4 fragment_color;

out vec4 out_color;

void main()
{
	out_color = fragment_color;
	//out_color = vec4(1.0, 1.0, 1.0, 1.0);
}

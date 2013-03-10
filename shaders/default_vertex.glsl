#version 330 core
layout(location = 0) in vec2 in_vertex_position_modelspace;
layout(location = 1) in vec4 in_vertex_color;

uniform mat4 u_p_matrix;
uniform mat4 u_v_matrix;
uniform mat4 u_m_matrix;
uniform mat4 u_T;	// translation matrix
uniform mat4 u_R;

out vec4 fragment_color;

void main()
{
	mat4 transformed_m_matrix = u_m_matrix * u_T * u_R;

	mat4 mvp_matrix = u_p_matrix * u_v_matrix * transformed_m_matrix;
	//mat4 mvp_matrix = u_p_matrix * u_v_matrix * u_m_matrix;

	gl_Position = mvp_matrix * vec4(in_vertex_position_modelspace, 0.0, 1.0);
	fragment_color = in_vertex_color;
}
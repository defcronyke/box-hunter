/* Ⓒ Copyright 2013 Jeremy Carter
 *
 * This file is part of Box Hunter.
 *
 * Box Hunter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Box Hunter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Box Hunter.  If not, see <http://www.gnu.org/licenses/>.
 *
 * default_vertex.glsl
 *
 *  Created on: 2013-03-04
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */
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

	gl_Position = mvp_matrix * vec4(in_vertex_position_modelspace, 0.0, 1.0);
	fragment_color = in_vertex_color;
}
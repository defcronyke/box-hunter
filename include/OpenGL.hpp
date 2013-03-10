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
 * OpenGL.hpp
 *
 *  Created on: 2013-03-05
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#ifndef OPENGL_HPP_
#define OPENGL_HPP_

#include <vector>
#include <string>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Window.hpp"

namespace Defcronyke
{

class GameObject;

class OpenGLConfig
{
public:
	glm::mat4 p_matrix;
	glm::mat4 v_matrix;
	glm::mat4 m_matrix;

	OpenGLConfig();  // assumes 640x480 window, use a different constructor to override
	OpenGLConfig(WindowConfig*& window_config);
	OpenGLConfig(WindowConfig& window_config);
	~OpenGLConfig();
};

class OpenGL
{
	bool owns_opengl_config_memory;

public:
	OpenGLConfig* opengl_config;

	glm::mat4 p_matrix;
	glm::mat4 v_matrix;
	glm::mat4 m_matrix;

	GLint p_matrix_u_loc;
	GLint v_matrix_u_loc;
	GLint m_matrix_u_loc;
	GLint T_u_loc; // translation matrix uniform location
	GLint R_u_loc;

	GLuint vao_id;
	std::vector<GLuint> vbo_positions_ids;
	std::vector<GLuint> vbo_colors_ids;

	OpenGL();  // assumes 640x480 window, use a different constructor to override
	OpenGL(OpenGLConfig*& opengl_config);
	OpenGL(OpenGLConfig& opengl_config);
	OpenGL(WindowConfig*& window_config);	// a shortcut
	OpenGL(WindowConfig& window_config);
	virtual ~OpenGL();

	bool init();
	GLuint load_shaders(std::string vertex_shader, std::string fragment_shader); // returns shader program id
	bool init_buffers(GLuint& shader_program_id, std::vector<GameObject*>& objects_on_screen);
	void update(GLuint& shader_program_id, std::vector<GameObject*>& objects_on_screen); // takes the objects that will be drawn by the draw() function
	void clear();
	void draw(GLuint& shader_program_id, std::vector<GameObject*>& objects_on_screen);
};

}
#endif

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
 * OpenGL.cpp
 *
 *  Created on: 2013-03-05
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#include <GL/glew.h>
#include "../include/OpenGL.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../include/GameObject.hpp"

namespace Defcronyke
{

OpenGLConfig::OpenGLConfig()
	: p_matrix(glm::ortho(0.0f, (float)640 * 0.02f, 0.0f, (float)480 * 0.02f, 0.1f, 100.0f)),
      v_matrix(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -1.0f))),
	  m_matrix(glm::mat4(1.0f))
{

}

OpenGLConfig::OpenGLConfig(WindowConfig*& window_config)
	: p_matrix(glm::ortho(0.0f, (float)window_config->width * 0.02f, 0.0f,
						  (float)window_config->height * 0.02f, 0.1f, 100.0f)),
	  v_matrix(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -1.0f))),
	  m_matrix(glm::mat4(1.0f))
{

}

OpenGLConfig::OpenGLConfig(WindowConfig& window_config)
	: p_matrix(glm::ortho(0.0f, (float)window_config.width * 0.02f,
			   0.0f, (float)window_config.height * 0.02f, 0.1f, 100.0f)),
	  v_matrix(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -1.0f))),
      m_matrix(glm::mat4(1.0f))
{

}

OpenGLConfig::~OpenGLConfig()
{

}


OpenGL::OpenGL()
	: owns_opengl_config_memory(true),
	  opengl_config(new OpenGLConfig),
	  p_matrix(this->opengl_config->p_matrix),
	  v_matrix(this->opengl_config->v_matrix),
	  m_matrix(this->opengl_config->m_matrix),
	  p_matrix_u_loc(0),
	  v_matrix_u_loc(0),
	  m_matrix_u_loc(0),
	  T_u_loc(0),
	  R_u_loc(0),
	  vao_id(0)
{

}

OpenGL::OpenGL(OpenGLConfig*& opengl_config)
	: owns_opengl_config_memory(false),
	  opengl_config(opengl_config),
	  p_matrix(this->opengl_config->p_matrix),
	  v_matrix(this->opengl_config->v_matrix),
	  m_matrix(this->opengl_config->m_matrix),
	  p_matrix_u_loc(0),
	  v_matrix_u_loc(0),
	  m_matrix_u_loc(0),
	  T_u_loc(0),
	  R_u_loc(0),
	  vao_id(0)
{

}

OpenGL::OpenGL(OpenGLConfig& opengl_config)
	: owns_opengl_config_memory(false),
	  opengl_config(&opengl_config),
	  p_matrix(this->opengl_config->p_matrix),
	  v_matrix(this->opengl_config->v_matrix),
	  m_matrix(this->opengl_config->m_matrix),
	  p_matrix_u_loc(0),
	  v_matrix_u_loc(0),
	  m_matrix_u_loc(0),
	  T_u_loc(0),
	  R_u_loc(0),
	  vao_id(0)
{

}

OpenGL::OpenGL(WindowConfig*& window_config)
	: owns_opengl_config_memory(true),
	  opengl_config(new OpenGLConfig(window_config)),
	  p_matrix(this->opengl_config->p_matrix),
	  v_matrix(this->opengl_config->v_matrix),
	  m_matrix(this->opengl_config->m_matrix),
	  p_matrix_u_loc(0),
	  v_matrix_u_loc(0),
	  m_matrix_u_loc(0),
	  T_u_loc(0),
	  R_u_loc(0),
	  vao_id(0)
{

}

OpenGL::OpenGL(WindowConfig& window_config)
	: owns_opengl_config_memory(true),
	  opengl_config(new OpenGLConfig(window_config)),
	  p_matrix(this->opengl_config->p_matrix),
	  v_matrix(this->opengl_config->v_matrix),
	  m_matrix(this->opengl_config->m_matrix),
	  p_matrix_u_loc(0),
	  v_matrix_u_loc(0),
	  m_matrix_u_loc(0),
	  T_u_loc(0),
	  R_u_loc(0),
	  vao_id(0)
{

}

OpenGL::~OpenGL()
{
	if (this->owns_opengl_config_memory)
		if (this->opengl_config)
			delete this->opengl_config;
}

bool OpenGL::init()
{
	glewExperimental = GL_TRUE;
	GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK)
	{
		std::cerr << "\nError: glewInit() failed\n";
		return false;
	}

	glClearColor(0.3, 0.2, 0.7, 1.0);

	return true;
}

GLuint OpenGL::load_shaders(std::string vertex_shader, std::string fragment_shader)
{
	GLuint vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertex_shader_code;
	std::ifstream vertex_shader_stream(vertex_shader.c_str(), std::ios::in);
	if (!vertex_shader_stream.is_open())
	{
		std::cerr << "\nError: Couldn't open vertex shader file: " << vertex_shader << "\n";
		return 0;
	}
	else
	{
		std::string line;
		while (std::getline(vertex_shader_stream, line))
			vertex_shader_code += line + '\n';
		vertex_shader_stream.close();
	}

	std::string fragment_shader_code;
	std::ifstream fragment_shader_stream(fragment_shader.c_str(), std::ios::in);
	if (!fragment_shader_stream.is_open())
	{
		std::cerr << "\nError: Couldn't open fragment shader file: " << fragment_shader << "\n";
		return 0;
	}
	else
	{
		std::string line;
		while (std::getline(fragment_shader_stream, line))
			fragment_shader_code += line + '\n';
		fragment_shader_stream.close();
	}

	GLint result = GL_FALSE; // result of compiling or linking the shaders
	int info_log_length = 0;

	const char* vertex_shader_c_str = vertex_shader_code.c_str();
	glShaderSource(vertex_shader_id, 1, &vertex_shader_c_str, 0);
	glCompileShader(vertex_shader_id);

	glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertex_shader_id, GL_INFO_LOG_LENGTH, &info_log_length);
	std::vector<GLchar> vertex_shader_error_message(info_log_length);
	glGetShaderInfoLog(vertex_shader_id, info_log_length, 0, &vertex_shader_error_message[0]);
	if (result == GL_FALSE)
	{
		std::cerr << "Error: Couldn't compile vertex shader\n" << &vertex_shader_error_message[0] << "\n";
		return 0;
	}

	const char* fragment_shader_c_str = fragment_shader_code.c_str();
	glShaderSource(fragment_shader_id, 1, &fragment_shader_c_str, 0);
	glCompileShader(fragment_shader_id);

	glGetShaderiv(fragment_shader_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragment_shader_id, GL_INFO_LOG_LENGTH, &info_log_length);
	std::vector<GLchar> fragment_shader_error_message(info_log_length);
	glGetShaderInfoLog(fragment_shader_id, info_log_length, 0, &fragment_shader_error_message[0]);
	if (result == GL_FALSE)
	{
		std::cerr << "Error: Couldn't compile fragment shader\n" << &fragment_shader_error_message[0] << "\n";
		return 0;
	}

	GLuint program_id = glCreateProgram();
	glAttachShader(program_id, vertex_shader_id);
	glAttachShader(program_id, fragment_shader_id);
	glLinkProgram(program_id);

	glGetProgramiv(program_id, GL_LINK_STATUS, &result);
	glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &info_log_length);
	std::vector<GLchar> program_error_message(info_log_length);
	glGetProgramInfoLog(program_id, info_log_length, 0, &program_error_message[0]);
	if (result == GL_FALSE)
	{
		std::cerr << "Error: Couldn't link shader program\n" << &program_error_message << "\n";
		return 0;
	}

	glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);

	return program_id;
}

bool OpenGL::init_buffers(GLuint& shader_program_id, std::vector<GameObject*>& objects_on_screen)
{
	glGenVertexArrays(1, &this->vao_id);
	glBindVertexArray(this->vao_id);

	for (unsigned int i = 0; i < objects_on_screen.size(); i++)
	{
		GLuint vbo_positions_id;
		glGenBuffers(1, &vbo_positions_id);
		this->vbo_positions_ids.push_back(vbo_positions_id);
		glBindBuffer(GL_ARRAY_BUFFER, vbo_positions_id);
		glBufferData(GL_ARRAY_BUFFER,
			objects_on_screen[i]->coords_opengl.size() * sizeof(glm::vec2),
			&objects_on_screen[i]->coords_opengl[0], GL_STATIC_DRAW);

		GLuint vbo_colors_id;
		glGenBuffers(1, &vbo_colors_id);
		this->vbo_colors_ids.push_back(vbo_colors_id);
		glBindBuffer(GL_ARRAY_BUFFER, vbo_colors_id);
		glBufferData(GL_ARRAY_BUFFER,
			objects_on_screen[i]->colors.size() * sizeof(glm::vec4),
			&objects_on_screen[i]->colors[0], GL_STATIC_DRAW);
	}

	this->p_matrix_u_loc = glGetUniformLocation(shader_program_id, "u_p_matrix");
	this->v_matrix_u_loc = glGetUniformLocation(shader_program_id, "u_v_matrix");
	this->m_matrix_u_loc = glGetUniformLocation(shader_program_id, "u_m_matrix");
	this->T_u_loc = glGetUniformLocation(shader_program_id, "u_T");
	this->R_u_loc = glGetUniformLocation(shader_program_id, "u_R");
	if (this->p_matrix_u_loc == -1 || this->v_matrix_u_loc == -1 || this->m_matrix_u_loc == -1 || this->T_u_loc == -1 || this->R_u_loc == -1)
	{
		std::cerr << "\nError: glGetUniformLocation() failed\n";
		return false;
	}

	return true;
}

void OpenGL::update(GLuint& shader_program_id, std::vector<GameObject*>& objects_on_screen)
{
//	for (unsigned int i = 0; i < objects_on_screen.size(); i++)
//	{
//
//	}

	return;
}

void OpenGL::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	return;
}

void OpenGL::draw(GLuint& shader_program_id, std::vector<GameObject*>& objects_on_screen)
{
	for (unsigned int i = 0; i < objects_on_screen.size(); i++)
	{
		glUseProgram(shader_program_id);

		glUniformMatrix4fv(this->p_matrix_u_loc, 1, GL_FALSE, &this->p_matrix[0][0]);
		glUniformMatrix4fv(this->v_matrix_u_loc, 1, GL_FALSE, &this->v_matrix[0][0]);
		glUniformMatrix4fv(this->m_matrix_u_loc, 1, GL_FALSE, &this->m_matrix[0][0]);
		glUniformMatrix4fv(this->T_u_loc, 1, GL_FALSE, &objects_on_screen[i]->T[0][0]);
		glUniformMatrix4fv(this->R_u_loc, 1, GL_FALSE, &objects_on_screen[i]->R[0][0]);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo_positions_ids[i]);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo_colors_ids[i]);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glDrawArrays(GL_TRIANGLES, 0, objects_on_screen[i]->coords_opengl.size());

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
	}

	return;
}

}

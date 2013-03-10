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
 * Window.cpp
 *
 *  Created on: 2013-03-04
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#include "../include/Window.hpp"
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

namespace Defcronyke
{

WindowConfig::WindowConfig()
	: title("Some Program"),
	  pos(SDL_WINDOWPOS_UNDEFINED),
	  width(640),
	  height(480),
	  settings(SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN)
{

}

WindowConfig::~WindowConfig()
{

}


Window::Window()
	: owns_window_config_memory(true),
	  window_config(new WindowConfig),
	  sdl_window(0),
	  sdl_glcontext(0)
{

}

Window::Window(WindowConfig*& window_config)
	: owns_window_config_memory(false),
	  window_config(window_config),
	  sdl_window(0),
	  sdl_glcontext(0)
{

}

Window::Window(WindowConfig& window_config)
	: owns_window_config_memory(false),
	  window_config(&window_config),
	  sdl_window(0),
	  sdl_glcontext(0)
{

}

Window::~Window()
{
	if (this->owns_window_config_memory)
		if (this->window_config)
			delete this->window_config;

	if (this->sdl_window)
		SDL_DestroyWindow(this->sdl_window);

	if (this->sdl_glcontext)
		SDL_GL_DeleteContext(this->sdl_glcontext);

	SDL_Quit();
}

void Window::open()
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	this->sdl_window = SDL_CreateWindow(this->window_config->title.c_str(),
						this->window_config->pos, this->window_config->pos,
						this->window_config->width, this->window_config->height,
						this->window_config->settings);

	SDL_GLContext tmp_context = SDL_GL_CreateContext(this->sdl_window);
	this->sdl_glcontext = &tmp_context;

	SDL_GL_SetSwapInterval(1);	// sync buffer swap with monitor's vertical refresh rate

	return;
}

void Window::swap_buffers()
{
	SDL_GL_SwapWindow(this->sdl_window);
	return;
}

}

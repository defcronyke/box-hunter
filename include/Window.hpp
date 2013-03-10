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
 * Window.hpp
 *
 *  Created on: 2013-03-04
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <string>

class SDL_Window;
typedef void* SDL_GLContext;

namespace Defcronyke
{

class WindowConfig
{
public:
	std::string title;
	int pos;
	int width;
	int height;
	int settings;

	WindowConfig();
	~WindowConfig();
};

class Window
{
	const bool owns_window_config_memory;

public:
	WindowConfig* window_config;
	SDL_Window* sdl_window;
	SDL_GLContext* sdl_glcontext;

	Window();	// use a new default config
	Window(WindowConfig*& window_config);	// use an existing config
	Window(WindowConfig& window_config);	// use an existing config from the stack
	virtual ~Window();

	void open();
	void swap_buffers();
};

}
#endif

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
 * main.cpp
 *
 *  Created on: 2013-03-04
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#include <iostream>
#include "../include/Window.hpp"
#include "../include/OpenGL.hpp"
#include "../include/Physics2D.hpp"
#include "../include/GameObject.hpp"
#include "../include/levels/Level001.hpp"
#include "../include/levels/Level002.hpp"
#include "../include/levels/Level003.hpp"
#include "../include/levels/Level004.hpp"
#include "../include/levels/Level005.hpp"
#include "../include/levels/Level006.hpp"
#include "../include/levels/Level007.hpp"
#include "../include/levels/Level008.hpp"
#include "../include/levels/Level009.hpp"
#include "../include/levels/Level010.hpp"
#include "../include/levels/Level011.hpp"

int main(int argc, char** argv)
{
	int level = 1;
//	int level = 11;

	int num_levels = 10;

	bool running_outer = true;

	Defcronyke::WindowConfig window_config;
	window_config.title = "Box Hunter v0.0.0";
	window_config.width = 800;
	window_config.height = 600;

	Defcronyke::Window window(window_config);
	window.open();

	while (running_outer)
	{
		Defcronyke::OpenGL opengl(window_config);	// use default matrices
		if (!opengl.init())
			return 1;

		GLuint shader_program_id = opengl.load_shaders(
			"shaders/default_vertex.glsl", "shaders/default_fragment.glsl");
		if (!shader_program_id)
			return 1;

		std::vector<Defcronyke::GameObject*> objects;

		if (level == 1)
			Defcronyke::Level001 level001(objects, window_config);
		else if (level == 2)
			Defcronyke::Level002 level002(objects, window_config);
		else if (level == 3)
			Defcronyke::Level003 level003(objects, window_config);
		else if (level == 4)
			Defcronyke::Level004 level004(objects, window_config);
		else if (level == 5)
			Defcronyke::Level005 level005(objects, window_config);
		else if (level == 6)
			Defcronyke::Level006 level006(objects, window_config);
		else if (level == 7)
			Defcronyke::Level007 level007(objects, window_config);
		else if (level == 8)
			Defcronyke::Level008 level008(objects, window_config);
		else if (level == 9)
			Defcronyke::Level009 level009(objects, window_config);
		else if (level == 10)
			Defcronyke::Level010 level010(objects, window_config);
//		else if (level == 11)
//			Defcronyke::Level011 level011(objects, window_config);
		else
		{
			std::cout << "Congratulations, you beat the game!" << std::endl;
			level = 1;
			continue;
		}

		std::cout << "Level " << level << std::endl;

		if (!opengl.init_buffers(shader_program_id, objects))
			return 1;

		Defcronyke::Physics2DConfig physics_config;
		physics_config.gravity.y = -2.0f;

		Defcronyke::Physics2D physics(physics_config);

		if (!physics.init(objects))
			return 1;

		int running_inner = 1;	// main loop
		while(running_inner == 1)
		{
			running_inner = physics.step(objects);	// events are handled in here
			opengl.update(shader_program_id, objects);
			opengl.clear();
			opengl.draw(shader_program_id, objects);
			window.swap_buffers();
		}

		std::vector<Defcronyke::GameObject*>::reverse_iterator it;	// cleanup
		for (it = objects.rbegin(); it != objects.rend(); ++it)
		{
			if (*it)
				delete (*it);
			objects.pop_back();
		}

		objects.resize(0);

		if (running_inner == 0)
		{
			running_outer = false;
		}
		else if (running_inner == 2)
		{
			level++;
		}
		else if (running_inner == 3) // if died
		{
			continue;
		}
		else if (running_inner == 4) // if reloaded level (the F1 key)
		{
			continue;
		}
		else if (running_inner == 5)
		{
			level--;
		}

		if (level <= 0)
			level = num_levels;
	}

	return 0;
}

# Ⓒ Copyright 2013 Jeremy Carter
#
# This file is part of Box Hunter.
#
# Box Hunter is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Box Hunter is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Box Hunter.  If not, see <http://www.gnu.org/licenses/>.
#
# CMakeLists.txt
#
#  Created on: 2013-03-10
#      Author: Jeremy Carter
#     Contact: Jeremy@JeremyCarter.ca
#

cmake_minimum_required ( VERSION 2.8 )
project ( box-hunter )
set ( box-hunter_VERSION_MAJOR 0 )
set ( box-hunter_VERSION_MINOR 0 )
set ( box-hunter_VERSION_MICRO 0 )

set ( CMAKE_CXX_FLAGS "-std=c++0x" )
set ( CMAKE_BUILD_TYPE "Release" )

include_directories( /usr/local/include )

add_executable( 
	box-hunter 
	src/main.cpp 
	src/Window.cpp
	src/OpenGL.cpp
	src/Physics2D.cpp
	src/GameObject.cpp
	src/Triangle.cpp
	src/Square.cpp
	src/Polygon.cpp
	src/ConcavePolygon.cpp
	src/SquarePlayer.cpp
	src/Goal.cpp
	src/levels/Level1.cpp
	src/levels/Level2.cpp
	src/levels/Level3.cpp
	src/levels/Level4.cpp
	src/levels/Level5.cpp
	src/levels/Level6.cpp
	src/levels/Level7.cpp
	src/levels/Level8.cpp )

link_directories( /usr/local/lib )

target_link_libraries( 
	box-hunter
	GLEW
	SDL2
	Box2D )

file( COPY "${PROJECT_SOURCE_DIR}/shaders" 
	  DESTINATION "${PROJECT_BINARY_DIR}" )

# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté hello
project(ray_trcaing.out)

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

# Crée des variables avec les fichiers à compiler
set(SRCS
    	main.cpp
	Sphere.cpp
	Hitable_list.cpp
    )
    
set(HEADERS
	Vec3.hpp
	Ray.hpp
	Sphere.hpp
	Hitable.hpp
	Hitable_list.hpp
    )

# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(ray_trcaing.out ${SRCS} ${HEADERS})


all: 
	@gcc main.c -I ./Frameworks/SDL2.framework/Versions/A/Header -F ./Frameworks -framework SDL2 -rpath ./frameworks -I ./Frameworks/SDL2_image.framework/Versions/A/Header -F ./Frameworks -framework SDL2_image -rpath ./frameworks

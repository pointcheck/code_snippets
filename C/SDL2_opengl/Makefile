SDL2_opengl: sdl2_opengl.c
	#gcc sdl2_opengl.c -lSDL2 -lGL -o sdl2_opengl 
	gcc -Wall -pthread -I ../../include -D_REENTRANT -D_THREAD_SAFE -lGL -lSDL2 -lSDL2_ttf -lSDL2_net -ldl -lm -freg-struct-return -ffast-math -fno-finite-math-only -o sdl2_opengl sdl2_opengl.c 

SDL2_opengl_static: sdl2_opengl.c
	gcc -Wall -pthread -I ../../include -D_REENTRANT -D_THREAD_SAFE -lGL -lSDL2 -lSDL2_ttf -lSDL2_net -ldl -lm -freg-struct-return -ffast-math -fno-finite-math-only -static -o sdl2_opengl sdl2_opengl.c 

clean:
	rm -rf sdl2_opengl

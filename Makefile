all:
	gcc -Iinclude/ source/callbacks.c source/camera.c source/init.c source/main.c source/scene.c source/texture.c source/utils.c -lSOIL -lobj -lopengl32 -lglu32 -lglut32 -lm -o game.exe -Wall -Wextra -Wpedantic

linux:
	# gcc -Iinclude/ source/callbacks.c source/camera.c source/init.c source/main.c source/scene.c source/texture.c source/utils.c -lSOIL -lobj -lGL -lGLU -lglut -lm -o game -Wall -Wextra -Wpedantic

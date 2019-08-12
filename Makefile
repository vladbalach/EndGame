NAME = EndGame

INC = inc/header.h 

HEADTMP = header.h 

SRCS = ./src/main.c \
	./src/mx_move.c \
	./src/checkMove.c \
	./src/redrawMap.c \
	./src/drawMap.c \
	./src/mx_push_front.c \
	./src/moveBullet.c \
	./src/createBullet.c \
	./src/mx_pop_index.c \
	./src/mx_pop_front.c \
	./src/mx_pop_back.c \
	./src/check_x.c \
	./src/check_y.c

CTMP = 	main.c \
	mx_move.c \
	checkMove.c \
	redrawMap.c \
	drawMap.c \
	mx_push_front.c \
	moveBullet.c \
	createBullet.c \
	mx_pop_index.c \
	mx_pop_front.c \
	mx_pop_back.c \
	check_x.c \
	check_y.c

CFLSGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install uninstall

install:
	@cp $(SRCS) .
	@cp $(INC) .
	@gcc $(CTMP) -I ./Frameworks/SDL2.framework/Versions/A/Header -F ./Frameworks -framework SDL2 -rpath ./Frameworks -I ./Frameworks/SDL2_image.framework/Versions/A/Header -F ./Frameworks -framework SDL2_image -rpath ./frameworks
uninstall:
	@rm -rf $(CTMP)
	@rm -rf $(OUT)
	@rm -rf $(HEADTMP)
clean:
	@rm -rf $(NAME)
	@rm -rf $(CTMP)
	@rm -rf $(OUT)
	@rm -rf $(HEADTMP)
reinstall: clean all

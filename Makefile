NAME = EndGame

INC = inc/header.h 

HEADTMP = header.h 
SRCS2 = test.c
CTMP2 = test.c
SRCS = ./src/main.c \
	./src/newMain.c \
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
	./src/check_y.c \
	./src/clearBulletList.c \
	./src/drawPlayer.c \
	./src/initMap.c \
	./src/showStartmenu.c \
	./src/startHard.c \
	./src/endScreen.c

CTMP = 	main.c \
	newMain.c \
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
	check_y.c \
	clearBulletList.c \
	drawPlayer.c \
	initMap.c \
	showStartmenu.c \
	startHard.c \
	endScreen.c

CFLSGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install uninstall
all2:
	@gcc $(CTMP2)  -F ./Frameworks -framework SDL2 -rpath ./Frameworks \
	 -F ./Frameworks -framework SDL2_image -rpath ./Frameworks\
	 -F ./Frameworks -framework SDL2_ttf -rpath ./Frameworks\ 
install:
	@cp $(SRCS) .
	@cp $(INC) .
	@gcc $(CTMP)  -F ./Frameworks -framework SDL2 -rpath ./Frameworks \
	 -F ./Frameworks -framework SDL2_image -rpath ./Frameworks\
	 -F ./Frameworks -framework SDL2_ttf -rpath ./Frameworks\

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
start: all
	./a.out

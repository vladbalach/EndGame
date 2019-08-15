NAME = endgame

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
	./src/endScreen.c \
	./src/drawText.c \
	./src/checkPlayers.c \
	./src/initPlayers.c \
	./src/startEasy.c \
	./src/ScoreboardScreen.c \
	./src/mx_strnew.c \
	./src/fillPlayerFromFile.c \
	./src/mx_strcmp.c \
	./src/mx_strcpy.c \
	./src/rewritePlayer.c

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
	endScreen.c \
	drawText.c \
	checkPlayers.c \
	initPlayers.c \
	startEasy.c \
	ScoreboardScreen.c \
	mx_strnew.c \
	fillPlayerFromFile.c \
	mx_strcmp.c \
	mx_strcpy.c \
	rewritePlayer.c

DFLAGS = -fsanitize=address -g
FFLAGS = -F ./Frameworks -framework SDL2 -rpath ./Frameworks \
	 -F ./Frameworks -framework SDL2_image -rpath ./Frameworks \
	 -F ./Frameworks -framework SDL2_ttf -rpath ./Frameworks \
	 -F ./Frameworks -framework SDL2_mixer -rpath ./Frameworks
CFLSGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install uninstall

debug:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLSGS) $(FFLAGS) $(DFLAGS) -o $(NAME) $(CTMP)
install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLSGS) -o $(NAME) $(CTMP) $(FFLAGS)

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

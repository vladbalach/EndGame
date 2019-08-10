NAME = EndGame

INC = inc/header.h 

HEADTMP = header.h 

SRCS = ./src/main.c \
	./src/mx_move.c \
	./src/checkMove.c

CTMP = 	main.c \
	mx_move.c \
	checkMove.c

CFLSGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install uninstall

install:
	@cp $(SRCS) .
	@cp $(INC) .
	@gcc $(CTMP) -I ./Frameworks/SDL2.framework/Versions/A/Header -F ./Frameworks -framework SDL2 -rpath ./frameworks -I ./Frameworks/SDL2_image.framework/Versions/A/Header -F ./Frameworks -framework SDL2_image -rpath ./frameworks
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

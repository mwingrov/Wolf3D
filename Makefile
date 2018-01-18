# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 19:50:59 by mwingrov          #+#    #+#              #
#    Updated: 2018/01/18 17:33:23 by mwingrov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d.exe

SRC = *.c

BIN = $(SRC:.c=.o)

HEAD = include/wolf3d.h

FLAGS = -g -Wall -Werror -Wextra

LIB = -L libft -lft

TFLAGS = -lSDL2 -I include/SDL2/ -L ~/lib -I include/

all: $(NAME)

$(NAME):
	gunzip -c SDL2-2.0.5.tar.gz | tar xf -
	cd SDL2-2.0.5; \
	mkdir build; \
	cd build; \
	../configure; \
	make
	mkdir -p ~/lib/
	cp SDL2-2.0.5/build/build/.libs/libSDL2-2.0.0.dylib ~/lib/
	ln -F -s ~/lib/libSDL2-2.0.0.dylib ~/lib/libSDL2.dylib
	mkdir -p include/SDL2
	cp SDL2-2.0.5/include/*.h include/SDL2/
	make -C libft/ fclean && make -C libft/
	clang $(FLAGS) $(TFLAGS) $(SRC) $(LIB) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(BIN)

fclean:
	rm -rf $(NAME)
	rm -rf include/SDL2
	rm -rf SDL2-2.0.5

re: fclean all

run:
	make -C libft/ fclean && make -C libft/
	clang $(FLAGS) $(TFLAGS) $(SRC) $(LIB) -o $(NAME)

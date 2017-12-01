# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 19:50:59 by mwingrov          #+#    #+#              #
#    Updated: 2017/12/01 16:54:19 by mwingrov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

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

clean:
	@rm -f $(BIN)

fclean: clean
	@rm -f $(NAME)
	rm -rf include/SDL2
	rm -rf SDL2-2.0.5

co: 
	make -C libft/ fclean && make -C libft/
	clang $(FLAGS) $(TFLAGS) $(SRC) $(LIB) -o $(NAME)

re:
	fclean all

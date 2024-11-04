# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vluo <vluo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/13 17:21:30 by bblancha          #+#    #+#              #
#    Updated: 2024/07/14 17:42:34 by vluo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = \
	srcs/*.c \

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) -o rush-02 $(SOURCES)
clean:
	rm -f srcs/*.o
fclean: clean
	rm -f rush-02

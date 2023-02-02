# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <rteles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 23:05:44 by rteles            #+#    #+#              #
#    Updated: 2023/02/02 22:21:55 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= BSP

SRCS			= ./main.cpp ./Fixed.cpp ./Point.cpp ./bsp.cpp

SRCS_OBJS		= $(SRCS:.cpp=.o)

CXX				= c++
XXFLAGS			= -Wall -Wextra -Werror -std=c++98
RM				= rm -f

%.o: %.cpp
	$(CXX) $(XXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	$(CXX) $(XXFLAGS) $(SRCS_OBJS) -o $(NAME)

clean:
	$(RM) $(SRCS_OBJS)
	
fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <rteles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 22:17:01 by rteles            #+#    #+#              #
#    Updated: 2023/01/30 23:35:41 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ScavTrap

SRCS			= ./main.cpp ./ClapTrap.cpp ./ScavTrap.cpp

SRCS_OBJS		= $(SRCS:.cpp=.o)

CPP				= g++
FLAGS			= -Wall -Wextra -Werror -std=c++98
RM				= rm -f

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	$(CPP) $(FLAGS) $(SRCS_OBJS) -o $(NAME)

clean:
	$(RM) $(SRCS_OBJS)
	
fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
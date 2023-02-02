# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <rteles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 22:17:01 by rteles            #+#    #+#              #
#    Updated: 2023/02/02 22:24:27 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= DiamondTrap

SRCS			= ./main.cpp ./ClapTrap.cpp ./ScavTrap.cpp ./FragTrap.cpp ./DiamondTrap.cpp

SRCS_OBJS		= $(SRCS:.cpp=.o)

CXX				= c++
XXFLAGS			= -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
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
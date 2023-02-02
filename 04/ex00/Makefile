# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <rteles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 23:25:53 by rteles            #+#    #+#              #
#    Updated: 2023/02/02 23:47:05 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Animal

SRCS			= ./main.cpp ./Animal.cpp ./Dog.cpp ./Cat.cpp

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
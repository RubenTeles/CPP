# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <rteles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 23:05:44 by rteles            #+#    #+#              #
#    Updated: 2023/02/02 22:22:17 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fixedInt

SRCS			= ./main.cpp ./Fixed.cpp

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
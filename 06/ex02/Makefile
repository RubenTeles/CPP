# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <rteles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 23:25:53 by rteles            #+#    #+#              #
#    Updated: 2023/03/02 13:20:20 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Base

SRCS			= ./main.cpp \
				  ./Base.cpp \

SRCS_OBJS		= $(SRCS:.cpp=.o)

CXX				= c++
CXXFLAGS			= -Wall -Wextra -Werror -std=c++98 -Wshadow
RM				= rm -f

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS_OBJS) -o $(NAME)

clean:
	$(RM) $(SRCS_OBJS)
	
fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
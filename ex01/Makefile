# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmelo <bmelo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/03 14:37:54 by bmelo             #+#    #+#              #
#    Updated: 2026/11/08 19:30:59 by bmelo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucratNform
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp Bureaucrat.cpp Form.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@printf "\033[32mBureaucrat's are Ready to Sign Forms \033[0m\n" "$(NAME)"

BureaucratDEBUG : CXXFLAGS += -DBUREAUCRATDEBUG=1
BureaucratDEBUG : re

FormDEBUG : CXXFLAGS += -DFORMDEBUG=1
FormDEBUG : re

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re BureaucratDEBUG FormDEBUG
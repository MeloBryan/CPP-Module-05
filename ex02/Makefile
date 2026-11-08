# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmelo <bmelo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/08 19:29:45 by bmelo             #+#    #+#              #
#    Updated: 2026/11/08 19:29:45 by bmelo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@printf "\033[32mBureaucrat's are Ready to Sign Forms \033[0m\n" "$(NAME)"

BureaucratDEBUG : CXXFLAGS += -DBUREAUCRATDEBUG=1
BureaucratDEBUG : re

PresidentialPardonFormDEBUG : CXXFLAGS += -DPRESIDENTIALPARDONFORMDEBUG=1
PresidentialPardonFormDEBUG : re

RobotomyRequestFormDEBUG : CXXFLAGS += -DROBOTOMYREQUESTFORMDEBUG=1
RobotomyRequestFormDEBUG : re

ShrubberyCreationFormDEBUG : CXXFLAGS += -DSHRUBBERYCREATIONFORMDEBUG=1
ShrubberyCreationFormDEBUG : re

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re

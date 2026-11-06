# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmelo <bmelo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/06 21:39:09 by bmelo             #+#    #+#              #
#    Updated: 2026/11/06 21:39:09 by bmelo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
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

InternDEBUG : CXXFLAGS += -DINTERNDEBUG=1
InternDEBUG : re

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re

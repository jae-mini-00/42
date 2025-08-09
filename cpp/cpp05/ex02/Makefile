CXX	=	c++
C_Flag	=	-std=c++98 -Wall -Wextra -Werror -g #-fsanitize=address

NAME =  AForm

SRCS = ./main.cpp ./Bureaucrat.cpp ./AForm.cpp ./ShrubberyCreationForm.cpp ./PresidentialPardonForm.cpp ./RobotomyRequestForm.cpp \

OBJS = $(SRCS:.cpp=.o)

all :	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(C_Flag) -o $(NAME) $(OBJS)

%.o	:	%.cpp
		$(CXX) $(C_Flag) -c $< -o $@
	
clean :
		rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME) *_shrubbery

re	:	fclean all

.PHONY	:	all clean fclean re
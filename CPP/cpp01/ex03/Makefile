CXX	=	c++ -std=c++98
C_Flag	=	-Wall -Wextra -Werror

NAME = Unnecessary_violence

SRCS = ./main.cpp ./Weapon.cpp ./HumanB.cpp ./HumanA.cpp\

OBJS = $(SRCS:.cpp=.o)

all :	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(C_Flag) -o $(NAME) $(OBJS)

%.o	:	%.cpp
		$(CXX) $(C_Flag) -c $< -o $@
	
clean :
		rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
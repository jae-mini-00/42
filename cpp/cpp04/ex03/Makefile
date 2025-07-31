CXX	=	c++
C_Flag	=	-std=c++98 
#-Wall -Wextra -Werror

NAME =  a.out

SRCS = ./main.cpp ./AMateria.cpp ./Character.cpp ./Ice.cpp ./Cure.cpp ./MateriaSource.cpp \

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
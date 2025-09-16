CXX	=	c++ -std=c++98
C_Flag	= -Wall -Wextra -Werror
# -O3 -march=native -flto -funroll-loops
NAME = PmergeMe

SRCS = ./main.cpp ./PmergeMe.cpp \

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
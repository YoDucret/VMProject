##
## Makefile
##
## vm project
##

NAME	=	vm

CXX	=	g++

RM	=	rm -f

SRCS	=	srcs/main.cpp	\
		srcs/Boot.cpp

OBJS	=	$(SRCS:.cpp=.o)

CXXFLAGS=	-W -Wall -Wextra -Werror -g3 -Iinclude -std=c++11

LDFLAGS	=	-ldl

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

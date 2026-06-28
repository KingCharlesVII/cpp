NAME=animal
CPP=c++
CPP_FLAGS=-std=c++98 -Wall -Wextra -Werror 
SRCS=main.cpp A.cpp B.cpp C.cpp Base.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(OBJS) -o $(NAME)
%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
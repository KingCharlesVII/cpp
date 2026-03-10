NAME=cpp_02_00
CPP=c++
CPP_FLAGS=-Wall -Wextra -Werror -std=c++98
SRCS=main.cpp 
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
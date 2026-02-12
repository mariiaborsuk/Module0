SFILES			= phonebook.cpp

OFILES			= $(SFILES:.cpp=.o)

CXX				= c++
RM				= rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


NAME			= phonebook
all:			$(NAME)

$(NAME):		$(OFILES)
				$(CXX) $(CXXFLAGS)  $(OFILES) -o $(NAME)

clean:
				$(RM) $(OFILES)

fclean:			clean
				$(RM) $(NAME) $(OLIBS)

re:				fclean $(NAME)
.PHONY:			all clean fclean re

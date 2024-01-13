# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

# NAME = linear_regression
# SRC = estimate_price.cpp gradient_descent.cpp calculate_precision.cpp main.cpp
# OBJS = $(SRC:.cpp=.o)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
# 	@echo "\033[0;32mCompilation successful! 🚀\033[0m"

# %.o: %.cpp linear_regression.h
# 	@$(CXX) $(CXXFLAGS) -c $<
# 	@echo "\033[0;32mCompiling $<... ✔\033[0m"

# clean:
# 	@rm -f $(OBJS) data.txt model.txt
# 	@echo "\033[0;33mCleaning object files... ✔\033[0m"

# fclean: clean
# 	@rm -f $(NAME)
# 	@echo "\033[0;31mCleaning executable... ✔\033[0m"

# re: fclean all

# .PHONY: all clean fclean re

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

NAME = linear_regression
SRC = estimate_price.cpp gradient_descent.cpp calculate_precision.cpp main.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[0;32mCompilation successful! 🚀\033[0m"

%.o: %.cpp linear_regression.h
	@$(CXX) $(CXXFLAGS) -c $<
	@echo "\033[0;32mCompiling $<... ✔\033[0m"

clean:
	@rm -f $(OBJS) data.txt model.txt
	@echo "\033[0;33mCleaning object files... ✔\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31mCleaning executable... ✔\033[0m"

re: fclean all

visualize:
	@python3 visualize.py  # Assurez-vous que le script Python s'appelle visualize.py
	@echo "\033[0;32mVisualizing 3D graph... ✔\033[0m"

.PHONY: all clean fclean re 
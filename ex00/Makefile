# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 12:29:20 by ddyankov          #+#    #+#              #
#    Updated: 2023/11/13 09:46:53 by ddyankov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED_BACK = \033[0;101m
GREEN_BACK = \033[0;102m
COLOUR_END = \033[0m

NAME = btc
# specifies the name of the output executable

SRC = main.cpp BitcoinExchange.cpp
# source files required for the program

OBJ = $(patsubst %.cpp, obj/%.o, $(SRC))
# patsubst function transforms the source files into objects with a 
# corresponding directory structure

DEPS = $(patsubst %.cpp, obj/%.d, $(SRC))
# specifies the dependencies

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP -g
# c++ flags for warning messages, for using the 98 standard required by subject
# -MMD 1. Automates the process of tracking dependencies between source and 
#        header files. When a header files is changed the associated source
# 		 files are recompiled automatically
#	   2. Saves time during the build process by recompiling only the
#		 necessary source files, rather than the entire project
#	   3. Ensured that the build remains up to date wit the latest changes
# -MP helps to maintain the correctness and reliability of Makefiles by ensuring
# 	  that header files are properly tracked as dependencies, even if they lack 
#	  explicit build rules. This is particularly useful for preventing errors and 
#	  ensuring that the build system remains robust in the presence of header file
#	  changes or removals.

.PHONY: all clean fclean re
# makes the makefile more explicit and less prone to errors and make understands
# that these targets are for tasks or actios and not for file-building targets

obj/%.o: %.cpp
	@mkdir -p obj
	@c++ $(CPPFLAGS) -c $< -o $@
# creates obj files in another directory and compiles src files into objects
# $< automatic variable for the first prerequisite, the 1. src file
# -o $@ specifies the output file

all: $(NAME)

$(NAME): $(OBJ)
		@c++ $(CPPFLAGS) $(OBJ) -o $@
		@echo "$(GREEN_BACK)✅✅✅Executable $(NAME) is ready✅✅✅$(COLOUR_END)"

clean:
		@rm -rf obj
		@echo "$(RED_BACK)🧹🧹🧹obj folder was cleaned🧹🧹🧹$(COLOUR_END)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(RED_BACK)🧹🧹🧹Executable was cleaned🧹🧹🧹$(COLOUR_END)"

re: fclean all
-include $(DEPS)
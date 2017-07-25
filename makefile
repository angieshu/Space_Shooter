# @Author: Anhelina Shulha <angieshu>
# @Date:   Jul-25-2017
# @Email:  anhelina.shulha@gmail.com
# @Filename: makefile
# @Last modified by:   angieshu
# @Last modified time: Jul-25-2017


NAME = SpaceShooter

SRC = src/*.cpp

FLAGS = -I/Library/Frameworks/SDL2.framework/Headers \
 		-I/Library/Frameworks/SDL2_image.framework/Headers \
		-I/Library/Frameworks/SDL2_mixer.framework/Headers \
		-F/Library/Frameworks \
		-framework SDL2 \
		-framework SDL2_image \
		-framework SDL2_mixer

all: $(NAME)

$(NAME):
	@clang++ $(FLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	@rm -rf $(NAME)

re: fclean all

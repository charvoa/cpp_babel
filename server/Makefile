##
## Makefile for babel in /home/nicolas/rendu/cpp_babel/server
##
## Made by Nicolas Girardot
## Login   <girard_s@epitech.net>
##
## Started on  Mon Oct 19 11:47:59 2015 Nicolas Girardot
## Last update Tue Oct 27 10:48:14 2015 Nicolas Girardot
##

MAIN		=	server

EXEC		=	$(MAIN)

DCOMMON		=	Common

SRC		=	VerifyRequest.cpp	\
			DataFromClient.cpp	\
			Client.cpp		\

SRC_MAIN	=	$(SRC) Common/main.cpp

OBJ_MAIN	=	$(SRC_MAIN:.cpp=.o)

LDFLAGS		=	-lboost_system		\

CPPFLAGS	=	-Wall -Wextra -Werror

CPP		=	g++

DEL_FILE	=	rm -f


all:		$(EXEC)
		@printf "\r[\033[2;35mMAKE\033[0m] SPYKE_SERVER\n"

$(MAIN):	$(OBJ_MAIN)
		@$(CPP) -o $@ $^ $(LDFLAGS)

%.o:            %.cpp
		@$(CPP) -o $@ -c $< $(CPPFLAGS)

clean:
		@$(DEL_FILE) $(OBJ)
		@printf "\r[\033[1;31mDELETE\033[0m] *.o\n"
		@$(DEL_FILE)
		@printf "\r[\033[1;31mDELETE\033[0m] *~\n"

fclean:		clean
		@$(DEL_FILE) $(MAIN)
		@printf "\r[\033[1;31mDELETE\033[0m] $(EXEC)\n"

re:		fclean all

.PHONY:		all clean fclean re
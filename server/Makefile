##
## Makefile for babel in /home/nicolas/rendu/cpp_babel/server
##
## Made by Nicolas Girardot
## Login   <girard_s@epitech.net>
##
## Started on  Mon Oct 19 11:47:59 2015 Nicolas Girardot
## Last update Sun Nov  8 14:25:33 2015 Nicolas Girardot
## Last update Mon Nov  2 18:26:32 2015 Nicolas Charvoz
##

MAIN		=	server

EXEC		=	$(MAIN)

SRC		=	VerifyRequest.cpp	\
			DataFromClient.cpp	\
			Common/TCPConnection.cpp\
			Server.cpp		\
			Account.cpp		\
			ProtocolClient.cpp	\
			Response.cpp		\
			Sender.cpp		\

SRC_MAIN	=	$(SRC) Common/main.cpp

OBJ_MAIN	=	$(SRC_MAIN:.cpp=.o)

LDFLAGS		=	-lboost_system		\

CPPFLAGS	=	-Wall -Wextra -Werror

ifeq ($(OS),Windows_NT)
	CPP	=	cl
else
	OS := $(shell uname)
	CPP	=	g++ -std=c++11
endif

DEL_FILE	=	rm -f


print-%  : ; @echo $* = $($*)

all:		$(EXEC)
		@printf "\r[\033[2;35mMAKE\033[0m] SPYKE_SERVER\n"

$(MAIN):	$(OBJ_MAIN)
		@$(CPP) -o $@ $^ $(LDFLAGS)

%.o:            %.cpp
		@$(CPP) -o $@ -c $< $(CPPFLAGS)

clean:
		@$(DEL_FILE) $(OBJ_MAIN)
		@printf "\r[\033[1;31mDELETE\033[0m] *.o\n"
		@$(DEL_FILE)
		@printf "\r[\033[1;31mDELETE\033[0m] *~\n"

fclean:		clean
		@$(DEL_FILE) $(MAIN)
		@printf "\r[\033[1;31mDELETE\033[0m] $(EXEC)\n"

re:		fclean all

.PHONY:		all clean fclean re

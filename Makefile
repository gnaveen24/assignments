
SRC =  ./src/test.c\
       ./src/mystrlen.c\
       ./src/mystrcpy.c\
       ./src/mystrcat.c\
       ./src/mystrcmp.c\
       ./src/factorial.c\
       ./src/isprime.c\
       ./src/ispalindrome.c\
       ./src/set.c\
       ./src/reset.c

INC = ./inc/mystrings.h\
      ./inc/myutils.h\
      ./inc/bitmask.h

Target :$(SRC) $(INC)
	gcc $(SRC) -o all.out


run : Target
	./all.out

clean:
	rm ./all.out

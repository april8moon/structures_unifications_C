FLAGS = -Wall -Wextra -Werror

all: door_struct list_test

door_struct: 
	gcc $(FLAGS) dmanager_module.c -o ../build/Quest_1

list_test: 
	gcc $(FLAGS) list_test.c list.c -o ../build/Quest_2

clean: 
	rm -rf  ./*.o 
	rm -rf ../build/Quest_1
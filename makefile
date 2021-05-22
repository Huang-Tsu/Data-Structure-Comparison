whole_dot_o:= main.o linked_list.o side_func.o array.o bs_array.o
CFLAG:=-Wall -g -fsanitize=undefined -fsanitize=address -fsanitize=leak
whole_dot_h:= basic.h linked_list.h array.h
all: $(whole_dot_o)
	@echo "gcc $(whole_dot_o) -o main\n"
	@gcc $(CFLAG) $(whole_dot_o) -o main

#%.o: %.c basic.h
#	@echo "gcc -c $<\n"
#	@gcc -c $(CFLAG) $<
#
main.o: main.c $(whole_dot_h)
	@echo "gcc -c main.c\n"
	@gcc -c $(CFLAG) $<

linked_list.o: linked_list.c linked_list.h basic.h
	@echo "gcc -c $<\n"
	@gcc -c $(CFLAG) $<

array.o: array.c array.h basic.h
	@echo "gcc -c $<\n"
	@gcc -c $(CFLAG) $<

bs_array.o: bs_array.c bs_array.h basic.h
	@echo "gcc -c $<\n"
	@gcc -c $(CFLAG) $<

side_func.o: side_func.c basic.h
	@echo "gcc -c $<\n"
	@gcc -c $(CFLAG) $<


.PHONY = clean
clean:
	-rm -f $(whole_dot_o) main
#	'-' 在開頭表示，就算後面出錯，這樣執行這行指令
#	'@' 在開頭表示不顯示這行指令

#	$?：代表已被更新的 dependencies 的值。
#		也就是 dependencies 中，比 targets 還新的值。
#	$@：代表 targets 的值。
#	$<：代表第一個 dependencies 的值。
#	$* :代表 targets 所指定的檔案，但不包含副檔名。

whole:= main.o 
CFLAG:=-Wall -g -fsanitize=undefined -fsanitize=address -fsanitize=leak
all: $(whole) 				
	@echo "gcc $(whole) -o main\n"
	@gcc $(CFLAG) $(whole) -o main 

%.o: %.c 
	@echo "gcc -c $<\n"
	@gcc -c $(CFLAG) $< 

.PHONY = clean
clean:
	-rm -f $(whole) main 
#	'-' 在開頭表示，就算後面出錯，這樣執行這行指令
#	'@' 在開頭表示不顯示這行指令

#	$?：代表已被更新的 dependencies 的值。
#		也就是 dependencies 中，比 targets 還新的值。
#	$@：代表 targets 的值。
#	$<：代表第一個 dependencies 的值。
#	$* :代表 targets 所指定的檔案，但不包含副檔名。

src = $(wildcard ./src/*.c)
obj = $(patsubst ./src/%.c, ./obj/%.o, $(src))

#编译器 
CC =  gcc
args = -Wall -g
#头文件路径
inc_path = -I ./include
#编译库的选择
lib = -lpthread
#库文件路径
LDFLAG = -L ./lib
#可执行程序 输出目标
target = ./output/demo

#目标($@)：需要依赖的条件($^)
$(target):$(obj)
	$(CC) $(inc_path) $(LDFLAG) $^ -o $@  $(args) $(lib)
#@echo make complete!

## %.o:%.c 同一目录下(src) 
# 不同目录下  ./obj/%.o : ./src/%.c 
./obj/%.o : ./src/%.c  
	$(CC) $(inc_path) $(LDFLAG)  -c $^ -o  $@ 

# 删除.o和输出文件
.PHONY: clean
clean:
	-rm  $(obj) $(target) -rf
#@echo Cleanup complete!




	
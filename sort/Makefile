#算法练习\
Author : yewei_andy\
Email : 896882701yw@gmail.com
CC=/usr/bin/g++
LD=$(CC)
DIR_INC = inc
DIR_SRC = src
DIR_OBJ = obj
DIR_BIN = bin

Lib_flag=-g -Wall -I${DIR_INC}
SRC = $(wildcard ${DIR_SRC}/*.cpp)
OBJ = $(patsubst %.cpp,${DIR_OBJ}/%.o,$(notdir ${SRC}))
TARGET = Mainout
BIN_TARGET = ${DIR_BIN}/${TARGET}

all:${BIN_TARGET}
${BIN_TARGET} : ${OBJ}
	@echo 链接生成目标文件
	${LD} ${DEF} ${Lib_flag} $(OBJ) -o $@

${DIR_OBJ}/%.o : ${DIR_SRC}/%.cpp
	@echo 正在编译:$< 输出目标: $@
	$(CC) ${DEF} ${Lib_flag} -c $< -o $@


.PHONY:clean
clean:
	@echo 删除目标文件
	rm -f ${DIR_OBJ}/*.o ${BIN_TARGET}

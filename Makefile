# 定义变量
CXX = g++
CFLAGS = -Wall -g

# 定义目标文件和依赖关系
TARGET = my_exe
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

# 默认目标
all: $(TARGET)

# 编译规则
$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^

# 生成 .o 文件的规则
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

# 清理规则
clean:
	-rm  -f $(OBJS) $(TARGET)

# 运行程序
run: $(TARGET)
	./$(TARGET)

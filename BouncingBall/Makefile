CXX = g++
CXXFLAGS = -g -O2 -Wall -Wextra -std=c++17 -Iinclude -MMD -MP
LDFLAGS = -Llib -lraylib -lgdi32 -lwinmm

SHELL := powershell.exe
MAKEFLAGS += -j$(NUMBER_OF_PROCESSORS)

# 1. Cấu hình thư mục build
BUILD_DIR = build
TARGET = main.exe

# 2. Quản lý danh sách file
SRCS = $(wildcard *.cpp) $(wildcard src/*.cpp)
# File .o và .d sẽ nằm trong thư mục build
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

# 3. Quy tắc liên kết (Linking)
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# 4. Quy tắc biên dịch (Compiling)
$(BUILD_DIR)/%.o: %.cpp
	@# Lệnh này sẽ tạo thư mục đích (bao gồm cả thư mục con) nếu chưa tồn tại
	@if (!(Test-Path $(@D))) { New-Item -ItemType Directory -Path $(@D) -Force | Out-Null }
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Bao gồm các file phụ thuộc .d
-include $(DEPS)

run: $(TARGET)
	./$(TARGET)

# 5. Dọn dẹp sạch sẽ
clean:
	if (Test-Path $(BUILD_DIR)) { rm -Recurse -Force $(BUILD_DIR) }
	if (Test-Path $(TARGET)) { rm $(TARGET) }


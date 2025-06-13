CXX = clang++
CXXFLAGS = -std=c++20 -g -I/opt/homebrew/Cellar/sfml/3.0.1/include
LDFLAGS = -L/opt/homebrew/Cellar/sfml/3.0.1/lib -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp
TARGET = fractal

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean

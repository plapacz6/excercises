
TARGET=reverse_words_order
CPP_OPTIONS=-std=c++1z -g 
#;c++1y c++11

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	g++ $(CPP_OPTIONS) -o $(TARGET) $(TARGET).cpp

.PHONY: clean

clean:
	-rm $(TARGET)


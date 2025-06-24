CXX = g++
CXXFLAGS = -Wall -g

TARGET = vCalc

TARGET_DEL = vCalc.exe

SRCS = main.cpp vector2D.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(TARGET) clean run

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o :  %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	del /Q $(OBJS)

run : vCalc.exe
	vCalc.exe
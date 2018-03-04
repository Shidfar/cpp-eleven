CPPFLAGS = -O2 -std=c++11 -stdlib=libc++ -Wall # -DPOSX

.cpp.o: ${CXX} $(CPPFLAGS) -c $< -o $@

SOURCES = main.cpp ring.cpp Sugar.cpp NestedTemplate.cpp
EXECUTABLE = run
OBJECTS = $(SOURCES:.cpp=.o)

$(EXECUTABLE): $(OBJECTS)
	${CXX} $(CPPFLAGS) -o $@ $^

clean:
	rm -rf *.o
	rm -rf `find . -name *.o`
	rm -rf *.so
	rm -rf $(EXECUTABLE)

all:  $(EXECUTABLE)


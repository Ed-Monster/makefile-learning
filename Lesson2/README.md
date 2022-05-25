# Lesson2 
- source files in src/
- headers in headers/
- targets and the makefile in build/
- use wildcard characters
```
objects = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
```

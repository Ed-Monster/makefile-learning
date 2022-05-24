target = StudenMgr
objects = main.o student.o cmdui.o
compiler = g++

$(target) : $(objects)
	$(compiler) $(objects) -o $(target)

main.o : main.cpp cmdui.h
	$(compiler) -c main.cpp
cmdui.o : cmdui.cpp cmdui.h
	$(compiler) -c cmdui.cpp
student : student.cpp student.h
	$(compiler) -c student.cpp

.PHONY : clean
clean :
	-rm $(target) $(objects)
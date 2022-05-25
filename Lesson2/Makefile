target = StudentMgr
sources = $(wildcard *.cpp)
objects = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
CC = g++

# generate the executable
$(target) : $(objects)
	$(CC) $(objects) -o $(target)

# generate objects
-include $(sources:.cpp=.d)

# automatically generate dependencies
%.d:%.cpp
	@echo "Creating $@ ..."
	@set -e; rm -f $@; \
	$(CC) -MM $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

.PHONY : cleanall cleanobj cleandp
cleanall : cleanobj cleandp
	-rm $(target)
cleanobj :
	-rm *.o
cleandp :
	-rm *.d
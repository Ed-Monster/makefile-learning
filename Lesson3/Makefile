target := StudentMgr
alibrary := libstu.a
sources := $(wildcard *.cpp)
objects := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
mains := main.o
others := $(filter-out $(mains),$(objects))
CC := g++

# generate the executable
$(target) : $(mains) $(alibrary)
	$(CC) $(mains) $(alibrary) -o $(target)

# build a static library
$(alibrary) : $(others)
	$(AR) -r $(alibrary) $(others)

# generate objects
-include $(sources:.cpp=.d)

# automatically generate dependencies
%.d:%.cpp
	@echo "Creating $@ ..."
	@set -e; rm -f $@; \
	$(CC) -MM $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

.PHONY : cleanall cleanobj cleandp cleanlib
cleanall : cleanobj cleandp cleanlib
	-rm $(target)
cleanobj :
	-rm *.o
cleandp :
	-rm *.d
cleanlib :
	-rm *.a
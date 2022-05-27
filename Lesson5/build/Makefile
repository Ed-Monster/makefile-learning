# The executable file
target := StudentMgr
# Shared library
LIB_DIR := ../lib
solibrary := libstu.so
library_name := $(patsubst lib%.so,%,$(solibrary))
vpath %.so $(LIB_DIR)
# Source files
SRC_DIR := ../src
sources := main.cpp cmdui.cpp student.cpp
src_path := $(patsubst %.cpp,$(SRC_PATH)/%.cpp,$(sources))
vpath %.cpp $(SRC_DIR)
# Dependencies
dependencies := $(patsubst %.cpp,%.d,$(sources))
# Header files
HD_DIR := ../include
vpath %.h $(HD_DIR)
# Objects
objects := $(patsubst %.cpp,%.o,$(sources))
mains := main.o
others := $(filter-out $(mains),$(objects))

CPPFLAGS := -fpic

# generate the executable
$(target) : $(mains) $(patsubst %.o,%.d,$(mains)) $(solibrary)
	$(CXX) $(mains) -L $(LIB_DIR) -l $(library_name) -o $(target)

# build a shared library
$(solibrary) : $(others) $(patsubst %.o,%.d,$(others))
	$(CXX) -shared $(others) -o $(LIB_DIR)/$(solibrary)

# CPPFLAGS :=
# generate the main object
# -include $(mains.o=.d)
# CPPFLAGS :=

# generate other objects with -fpic
# CPPFLAGS := -fpic
# -include $(filter-out $(mains:.o=.d),$(sources:.cpp=.d))
# 	$(CXX) -c -fpic $<

-include $(sources:.cpp=.d)

# generate the main object
# -include $(mains.o=.d)
# -include $(mains:.o=.d)
# 	# $(CXX) -c $(mains:.o=.cpp) -o $(mains)

# automatically generate dependencies


%.d : %.cpp
	echo "Creating $@ ..."
	set -e; rm -f $@; \
	$(CC) -MM $< > $@.tmp1; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.tmp1 > $@.tmp2; \
	sed '1a \\t$(CXX) -c $(CPPFLAGS) $< -I $(HD_DIR)' $@.tmp2 > $@; \
	rm -f $@.tmp1 $@.tmp2

.PHONY : cleanall cleanobj cleandp cleanlib
cleanall : cleanobj cleandp cleanlib
	-rm $(target)
cleanobj :
	-rm *.o
cleandp :
	-rm *.d
cleanlib :
	-rm *.so
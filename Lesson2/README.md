# Lesson2 
- use wildcard characters
    ```makefile
    objects = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
    ```
- use phony objects
    ```makefile
    .PHONY : cleanall cleanobj
    cleanall : cleanobj
        -rm $(target)
    cleanobj :
        -rm *.o
    ```
- static pattern
    ```makefile
    $(objects) : %.o: %.cpp
        $(CC) -c $< -o $@
    ```
- automatically generate dependencies
    ```makefile
    %.d:%.cpp
        @echo "Creating $@ ..."
        @set -e; rm -f $@; \
        $(CC) -MM $< > $@.$$$$; \
        sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
        rm -f $@.$$$$
    ```

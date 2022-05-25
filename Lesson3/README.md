# Lesson3
- to build a static library
    ```makefile
    $(alibrary) : $(others)
        $(AR) -r $(alibrary) $(others)
    ```
- to filter out
    ```makefile
    others := $(filter-out $(mains),$(objects))
    ```

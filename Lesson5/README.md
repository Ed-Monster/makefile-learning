# Lesson4
- to build a shared library
    ```makefile
    # generate the executable, linking to shared libraries
    $(EXE) : $(mains) $(solibrary)
	$(CXX) $(mains) $(solibrary) -o $(EXE)
    ...
    # build a shared library
    $(solibrary) : $(others)
	$(CXX) -shared -o $(solibrary) $(others)
    ...
    # the objects used to build a shared library
    $(others):%.o:%.cpp
	$(CXX) -c -fpic -o $@ $< $(CPPFLAGS)
    ```
- **Q&A**: If you encounter this error when running StudentMgr:
    ```
    ./StudentMgr: error while loading shared libraries: libstu.so: cannot open shared object file: No such file or directory
    ```
    That's because the runtime system wouldn't search the directory where your shared libraries are.To solve this problem, you can try these approaches:
    1. Set the environment variable for the runtime.(disabled when you quit the program.)
        ```
        LD_LIBRARY_PATH=/path/to/your/lib:$LD_LIBRARY_PATH ./StudentMgr
        ```
    2. Set the environment variable for the current terminal.(disabled when you quit the terminal)
        ```
        export LD_LIBRARY_PATH=/path/to/your/lib:$LD_LIBRARY_PATH
        ./StudentMgr
        ```
    3. Set the environment variable for the current user.(disabled when you login as other users.)\
       Append this line to ~/.bashrc
       ```
       export LD_LIBRARY_PATH=/path/to/your/lib:$LD_LIBRARY_PATH
       ```
       then
       ```
       source ~/.bashrc
       ./StudentMgr
       ```
    4. Add the directory to your library to the config file that specifies the directories for the dynamic loader to search.(for any user of this machine)\
       Append this line to /etc/ld.so.conf
       ```
       /path/to/your/lib
       ```

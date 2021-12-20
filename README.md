## GFG-to-CPP
Using this appllication you can search for available code templates on www.geeksforgees.org with only entering a keyword
and also easily download them and split retrived codes from geeksforgees in different languages to seprate text files and open them automatically.


### Installing Python requirements
To easily install Python reqired packages, we provided a file which you can easily install all requirements in one line of code.
To do so, using terminal direct to ``GFG-to-CPP/sites_scraping_python`` directory and enter the command below:
```
$ pip install -r requirements.txt
```

### Lunching the application using CMake file
For Lunching the application using CMake file you should firstly go to the following path using terminal: ``GFG-to-CPP``
and then enter the commands below:
```
$ cmake .
$ make
and now for running the exec, you shold perform the following command:
$ ./GFG_to_CPP
```


### Testing
The test is based on ``binary search`` keyword for the input.
test test, checks if the files for this particular search exitsts or not.
For performing the test, make sure that you have searched for ``binary search`` using the GFG application. Then go to 
tests directory and enter the command bellow:
```
cmake -S . -B build && cmake --build build && build/GFGtest
```
if everyting is ok, you can see that 3 tests are passed!
You can also see the screenshots for the tests.

----

**ATTENTION:** ``Application can lunch only using Linux operating system!``


**Date: 10/6/2018**  
**Last Edit: 11/6/2018**

TestCase    
===  

Assignment 9 in a C++ course  

Authors:
--
Dvir Barzilay  
Kineret Ruth Nahary   
Shmuel Shimoni  

**Introduction**
==

About the assignment:
-- 
This assignment is for practicing creating otomatic testers for a project.  
We need to create a class that represents the testers - TestCase class.  
In this class there need to be 4 functions that checks equal, difference, output and function.  
Those checking functions need to be of type template.  
The class need to have a print function that will print the number of passed, failed and total cases.  
    
**File list:**  
--  

```  
.: 
.gitignore 
TestCase.cpp  
TestCase.hpp    
README.md  
main.cpp  
```  
Further look into the classes:     
--  
1. **main.cpp** - This class has some examples to run and check the code with it.  
2. **TestCase.hpp** - This class represents a testing class. Its fields are :   
*total, passed, failed* - The number of failed, passed and total cases checked by the class.   
*_name* - The name of the test type.   
*c* - An ostream object to be used.  
3. **TestCase.cpp** - The implementation of TestCase.hpp.  

Compile Command:  
--  
g++ -std=c++11 *.cpp  

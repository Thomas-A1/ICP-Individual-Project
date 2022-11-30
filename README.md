# ICP-Individual-Project in C++

**HOW TO RUN THE CODE**

The code can be tested by running / compiling and executing the main method (main.cpp) in the files above. Two routes were tested to find their number of stops and optimal distance in the main method (main.cpp). These routes are: 
- From Harare, Zimbabwe to Accra, Ghana (**The output of this file is titled : HarareToAccraOutputfile.txt read from HarareToAccraInputfile.csv in the files above**)
- From Zanzibar, Tanzania to Accra, Ghana (**The output of this file is titiled: ZanzibarToAccraOutputfile.txt read from ZanzibarToAccraInputfile.csv in the files above**)

**HOW TO KNOW IF THE CODE IS RUNNING / EXECUTING**
When the main method (main.cpp) is compiled and executed, the user is approached with an info that says **"Reading Routes file (67664) rows. This process might take a while, please be patient...................."**. This is to inform the user that the program is still being executed and giving the reason why it might take a while to process. However, the search algorith (Uniform Cost Search) which returns the optimal distance takes approximately 43 seconds(max) to be executed(finding the goal). Therefore, when you see the above prompt after running main.cpp, don't be scared because it's not a bug :blush: 😊

**SIGNIFICANT CODES AM MOST PROUD OF AND WHERE TO LOCATE THEM**
- The method that writes to a text file can be found in the node.cpp file which was declared in the *node.h* file (The name of the method is "write_to_file")
- The Uniform Cost Search which is performing most of the tasks in this program is a static method located in the *Search.h* header file.
- The method that reads the csv files (i.e. Routes.csv, Airline.csv, and Airport.csv) has a user-defined split method that can be located in the *Readfile.cpp* file.
- The method that reads each input csv file to compute their distance by passing the source city and destination city to the Uniform Cost Search can be found in *Inputfile.h* header file

**FURTHER DESCRIPTIONS**
- The Airport.cpp, Airline.cpp, and Routes.cpp are classes created with the member variables and functions (mutator methods) curated from the corresponding columns of the Airport.csv file, Airline.csv, and Routes.csv (which are the files am reading from , and needed to complete this project).

- *NB*: Ernest Torto's personal reflection for this project is titled "Ernest Torto Reflection", and mine (Thomas Quarshie) is titled "Final Project C++.pdf" in the files above. I bet that if you take your time to read these instructions and details, you will be able to access and even manipulate manipulates to test its efficiency or suit your future works/projects.

**Thanks**,

Thomas & Ernest 😊

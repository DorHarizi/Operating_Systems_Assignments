Chat supports an unlimited members using Reactor Design pattern 
Task 4 : Linux practice - Operating systems course.

Project Description:
The reactor of the design pattern according like that: 
a) you implement a data structure that will map between the function and the FD 
b) you implement the mechanism and perform FD to listen to all the (select or poll) that is responsible for the selector 
   reactor the operation listed in the table of the 

API of the reactor:

1. **void createReactor()** 

2. **void stopReactor(void this)** 

3. **void startReactor(void this)** 

4. **void addFd(void this,int fd, handler_t handler)** 

5. **void WaitFor(void this)** 

Building</div>
1. Cloning the repo to local machine: ` git clone` [https://github.com/DorHarizi/Chat-using-ds-Reactor.git] 
2. Building all the necessary files & the main programs:  `make` 
3. Export shared libraries : `export LD_LIBRARY_PATH=.` 

How to run? 
- Run the reactor server: `./react_server 

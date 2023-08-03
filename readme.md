# MINITALK - @42Wolfsburg

## Purpose

Minitalk is in the second ring of the Core Curriculum @42Wolfsburg.
42 minitalk project is a collaboration between emomkus and qduong
Our goal:
	1. to practice git branching
	2. collaborate together on project

## Installation & Usage

### Requirements
The only requirements are:
- GNU make (v3.81)
- GCC (12.0.0) (clang-1200.0.32.28)

Those versions are the ones used during development.

### Building the program

1. Download/Clone this repo

        git clone https://github.com/qduong42/42_minitalk
2. `cd` into the 42_minitalk/srcs directory and run `make`

        cd 42_minitalk/srcs
        make

### Running the program

After running make, execute `./server` from the same folder. You should see `Server pid: X`
Open another terminal in the same folder 42_minitalk/srcs and run `./client X [message-to-send]`

## Details about the project:

### Communication method

Examination shows that we may use **kill(USERSIG1, PID) kill(USERSIG2, PID)** functions to signal the individual bits of characters of string. *kill(USERSIG1, PID)* may mean *0* and *kill(USERSIG2, PID)* may mean *1*.
Out of these bits server shall accumulate 8bit characters.

we use **<<** shift operator, **&** bitwise AND and other bitwise operators to access individual bits

#### Using sigaction()

Technical Documentation of signal.h 
It explains that we shall define a struct sigaction   to use function sigaction(). The technical documentation (https://pubs.opengroup.org/onlinepubs/009695399/basedefs/signal.h.html) defines function's sigaction() operation. Notice the argument data types:

```c
	int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);
```
```c
	const struct sigaction
```   
or
```c
     struct sigaction
```
#### Using struct sigaction

It accepts struct sigaction in the same behabiour as any other datatype (int, char, char *). Contents of struct sigaction are predefined in signal.h library and are listed in technical documentation (https://man7.org/linux/man-pages/man2/sigaction.2.html).
```c
			struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
        	};
```
1. void     (*sa_handler)(int) - pointer to a signal handling function. This function receives the signal number as its only argument.
2. void     (*sa_sigaction)(int, siginfo_t *, void *) -- dependant on architecture or flags, is used instead of sa_handler.
3. sigset_t   sa_mask -- specifies a mask of signals which should be blocked.
4. sa_flags -- specifies a set of flags which modify the behavior of the signal like SA_SIGINFO.

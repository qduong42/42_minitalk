# MINITALK Prototype directory

## Purpose

this folder purposed for code testing debuging and prototyping
expected to be removed in final repo

## Communication method

examination shown that we may use **kill(USERSIG1, PID) kill(USERSIG2, PID)** functions to signal the individual bits of characters of string. *kill(USERSIG1, PID)* may mean *0* and *kill(USERSIG2, PID)* may mean *1*.
Out of these bits server shall accumulate 8bit characters.

That is not sane!!! How we were supposed to figure that out Huy?

we use **<<** shift operator, **&** bitwise AND and other bitwise operators to access individual bits

### Using sigaction()

technical documentation of signal.h 
it explains that we shall define a    struct sigaction   to use function sigaction(). It is a new concept we encounter of struct, so it is confusing, because we do not use typedef but:
technical documentation (https://pubs.opengroup.org/onlinepubs/009695399/basedefs/signal.h.html) defines function's sigaction() operation. notice argument data types:

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
### Using struct sigaction

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
1. **void     (*sa_handler)(int)** - pointer to a signal handling function. This function receives the signal number as its only argument.
2. **void     (*sa_sigaction)(int, siginfo_t *, void *)** -- dependant on architecture or flags, is used instead of sa_handler.
3. **sigset_t   sa_mask** -- specifies a mask of signals which should be blocked.
4. **sa_flags** -- specifies a set of flags which modify the behavior of the signal like SA_SIGINFO.
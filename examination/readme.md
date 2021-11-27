this folder purposed for code testing debuging and prototyping
expected to be removed in final repo

examination shown that we may use /kill(USERSIG1, PID) kill(USERSIG2, PID)/ functions to signal the individual bits of characters of string. kill(USERSIG1, PID) may mean 0 and kill(USERSIG2, PID) may mean 1.
Out of these bits server shall accumulate 8bit characters.

That is not sane!!! How we were supposed to figure that out Huy?

we use << shift operator and & bitwise AND to access individual bits

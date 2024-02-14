## Level02
## Source Code
![level02.png](level02.png)
## Walkthrough
- We reverse the binary to find the logic of this program.
- The binary is owned by user `level03` and the set-uid bit is set.
- The printf after the `strncmp` is vulnerable because we control the format string.
- We need to read from the stack because the password is stored into the stack.
- The payload contains 21 `%p` and then 5 `%p` to print the password
## Answer
    python print_password.py | ./level02
    python print_result.py
## Flag
Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
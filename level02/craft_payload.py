import struct

addr1 = 0x756e505234376848
addr2 = 0x45414a3561733951
addr3 = 0x377a7143574e6758
addr4 = 0x354a35686e475873
addr5 = 0x48336750664b394d

str = struct.pack('<Q', addr1)
str += struct.pack('<Q', addr2)
str += struct.pack('<Q', addr3)
str += struct.pack('<Q', addr4)
str += struct.pack('<Q', addr5)

print(str)
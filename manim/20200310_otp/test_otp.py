import hashlib
import hmac
def int_to_bytestring(i, padding=8):
    result = bytearray()
    while i != 0:
        result.append(i & 0xFF)
        i >>= 8
    return bytes(bytearray(reversed(result)).rjust(padding, b'\0'))
hasher = hmac.new(b'plusplus7', b'plusplus7', hashlib.sha1)
hmac_hash = bytearray(hasher.digest())
offset = hmac_hash[-1] & 0xf
code = ((hmac_hash[offset] & 0x7f) << 24 |
        (hmac_hash[offset + 1] & 0xff) << 16 |
        (hmac_hash[offset + 2] & 0xff) << 8 |
        (hmac_hash[offset + 3] & 0xff))
str_code = str(code % 10 ** 6)
while len(str_code) < 6:
    str_code = '0' + str_code

print(str_code)
import ctypes
import os

dir_path = os.path.dirname(os.path.realpath(__file__))
handle = ctypes.CDLL(dir_path + "/libTest.so")

handle.Multiplier.argtypes = [ctypes.c_int]
handle.address_return.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_size_t, ctypes.c_int]
handle.address_return.restype = ctypes.c_char_p


def Multiplier(num, multi):
    return handle.Multiplier(num, multi)


phrase = b"wow cool"
result = ctypes.create_string_buffer(100)
res = handle.address_return(phrase, result, ctypes.sizeof(result), 5, 10)
print(res)
print(result.value)
# def address_return(word):
# return handle.address_return(num, multi)

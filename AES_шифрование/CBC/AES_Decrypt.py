from Crypto.PublicKey import RSA
from Crypto.Cipher import AES, PKCS1_OAEP
import binascii

try:
    # Input
    key = '140b41b22a29beb4061bda66b6747e14'
    ciphertext_iv = '5b68629feb8606f9a6667670b75b38a5b4832d0f26e1ab7da33249de7d4afc48e713ac646ace36e872ad5fb8a512428a6e21364b0c374df45503473c5242a253'
    # Get IV
    iv = ciphertext_iv[:32]
    # Get Ciphertext
    ciphertext = ciphertext_iv[32:]
    # Hex to raw bytes
    iv = bytes.fromhex(iv)
    ciphertext = bytes.fromhex(ciphertext)
    key = bytes.fromhex(key)
    # Decode
    cipher = AES.new(key, AES.MODE_CBC, iv)
    pt = (cipher.decrypt(ciphertext), AES.block_size)
    pt = pt[0].hex()
    # unpad
    unpad = int(pt[-2:], 16) * 2
    pt = pt[:(len(pt)-unpad)]
    pt = binascii.unhexlify(pt)
    pt = str(pt, 'ascii')
    # Write text to file
    with open("plaintext.txt", "w") as file_handler:
        file_handler.write(pt)

    print("The message was:", '\n' + pt)
    print('Message is writen to "plaintext.txt".')
except (ValueError, KeyError):
    print("Incorrect decryption")
except IOError:
    print("An IOError has occurred!")

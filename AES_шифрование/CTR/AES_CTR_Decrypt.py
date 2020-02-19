from Crypto.Cipher import AES
import binascii

try:
    # Input
    key = '36f18357be4dbd77f050515c73fcf9f2'
    ciphertext_iv = '770b80259ec33beb2561358a9f2dc617e46218c0a53cbeca695ae45faa8952aa0e311bde9d4e01726d3184c34451'
    # Get IV
    nonce = ciphertext_iv[:16]
    iv = ciphertext_iv[:32]
    counter = ciphertext_iv[16:32]
    # Get Ciphertext
    ciphertext = ciphertext_iv[32:]
    # Hex to raw bytes
    iv = binascii.unhexlify(iv)
    nonce = binascii.unhexlify(nonce)
    ciphertext = binascii.unhexlify(ciphertext)
    key = binascii.unhexlify(key)
    counter = binascii.unhexlify(counter)
    # Decode
    size = len(nonce)
    cipher = AES.new(key, AES.MODE_CTR, nonce=nonce, initial_value=counter)
    pt = cipher.decrypt(ciphertext)
    pt = binascii.hexlify(pt)
    pt = pt.decode("hex")
    # Write text to file
    with open("plaintext.txt", "w") as file_handler:
        file_handler.write(pt)

    print("The message was:", '\n' + pt)
    print('Message is writen to "plaintext.txt".')
except (ValueError, KeyError):
    print("Incorrect decryption")
except IOError:
    print("An IOError has occurred!")

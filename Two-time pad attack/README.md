# Программа для подбора ключа к сообщению, зашифрованному с помощью "two - time pad".

Attack on Two-Time Pad
The general rule of cryptography says that one should never use the same keystream characters more than once. Otherwise, the cipher starts to be vulnerable to ciphertext-only attacks.

The following example shows, how the security of the OTP cipher is affected by using the same keystream bytes twice:

c1 <- m1 XOR PRG(k)
c2 <- m2 XOR PRG(k)

Having the two ciphertexts, an eavesdropper is able to break the cipher just by adding them together:

c1 XOR c2 = m1 XOR PRG(k) XOR m2 XOR PRG(k) = m1 XOR m2

The received byte sequence does not depend on the secret key. Due to the fact that there is enough redundancy in languages and in ASCII encoding, the attacker is able to extract the original messages:

m1 XOR m2 -> m1, m2

Nowadays, well-designed algorithms of symmetric ciphers add some unique (for every piece of data) characters to secret key bits. In the simplest case, a regular counter could be used. It may be stored on a few bytes and it should increase every iteration of the encryption algorithm. This guarantees effective encryption, without the risk of repetition of secret key bits.

Источник: [Attack on Two-Time Pad](http://www.crypto-it.net/eng/attacks/two-time-pad.html).

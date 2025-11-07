char = 'abcdefghijklmnopqrstuvwxyz'
num_letters = len(char)

def dencrypt(ciphertext, key):
    plaintext = ''
    for letter in ciphertext:
        letter = letter.lower()
        if letter != ' ':
            index = char.find(letter)
            if index == -1:
                plaintext += letter
            else:
                new_index = (index - key) % num_letters
                plaintext += char[new_index]
        else:
            plaintext += ' '
    return plaintext

ciphertext = "odrboewscdrolocdcwkbdmyxdvkmdzvkdpbyweddrobo"

for key in range(1, 26):
    decrypted_text = dencrypt(ciphertext, key)
    print(f"Shift {key}: {decrypted_text}")
    print()

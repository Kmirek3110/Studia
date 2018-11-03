#Programowanie Obiektowe Karol Mirek 01.03.2018 Zadanie 4 Kod Morsa

MORS = { 'A':'.-', 'B':'-...',
                    'C':'-.-.', 'D':'-..', 'E':'.',
                    'F':'..-.', 'G':'--.', 'H':'....',
                    'I':'..', 'J':'.---', 'K':'-.-',
                    'L':'.-..', 'M':'--', 'N':'-.',
                    'O':'---', 'P':'.--.', 'Q':'--.-',
                    'R':'.-.', 'S':'...', 'T':'-',
                    'U':'..-', 'V':'...-', 'W':'.--',
                    'X':'-..-', 'Y':'-.--', 'Z':'--..',
                    '1':'.----', '2':'..---', '3':'...--',
                    '4':'....-', '5':'.....', '6':'-....',
                    '7':'--...', '8':'---..', '9':'----.',
                    '0':'-----', ', ':'--..--', '.':'.-.-.-',
                    '?':'..--..', '/':'-..-.', '-':'-....-',
                    '(':'-.--.', ')':'-.--.-'}
def encrypt(message):
    szyfr = ''
    for x in message:
        if x != ' ':
            szyfr += MORS[x] + ' '
        else:
            szyfr += ' '
    return szyfr
def decrypt(message):
    message += ' '
    inv_map = {v: k for k, v in MORS.items()}
    kod = ''
    tekst = ''
    for x in message:
        if (x != ' '):
            i = 0
            tekst += x
        else:
            i += 1
            if i == 2 :
                kod += ' '
            else:
                kod +=inv_map[tekst]
                tekst = ''
    return kod


def szyfruj(txt,k):
    alfabet = {
  'a' : 1,
  'ą' : 2,
  'b' : 3,
  'c' : 4,
  'ć': 5,
  'd': 6,
  'e': 7,
  'ę': 8,
  'f': 9,
  'g': 10,
  'h': 11,
  'i': 12,
  'j': 13,
  'k': 14,
  'l': 15,
  'ł': 16,
  'm': 17,
  'n': 18,
  'ń': 19,
  'o': 20,
  'ó': 21,
  'p': 22,
  'r': 23,
  's':24,
  'ś':25,
  't':26,
  'u':27,
  'y':28,
  'z':29,
  'ź':30,
  'ż':31,
}
    inv_map = {alfabet[k] : k for k in alfabet}
    zaszyfrowny =""
    for i in range(len(txt)):
        i=alfabet[txt[i]]
        if(i+k>31):
            i=(i+k)-31
        else:
            i=i+k
        zaszyfrowny+=inv_map[i]
    return zaszyfrowny









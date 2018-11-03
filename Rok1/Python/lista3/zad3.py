def usun_nawiasy(s):
  s = list(s) 
  for i in range(len(s)):
    if s[i] == '(' or s[i]== ')':
      s[i] = ''
  return ''.join(s)
print (usun_nawiasy('(ala ma (psa) lub (kota) i (mysz(a)'))
print (usun_nawiasy('Ala ma kota (perskiego)!'))
print (usun_nawiasy('(((())))()()(Xadasvsad()(SAd0a()DA(SD)'))

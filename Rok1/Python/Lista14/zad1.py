

def kratkeczka(n,napis):
	z = 0  
	w = 0  
	for i in range(n):
		if i % 2 == 0:
			print(n*'#',end='')
		else:
			for j in range(round(n/2 - 1)):
				if z == w*((n-1)/2) and j < len(napis) and j+z < len(napis):
					pom = napis[int(j+z)]
				else:
					pom = " "

				print("#", end='')
				if len(napis) > j:
					print(pom, end='')
				else:
					print(" ", end='')
					pom = " "

			w += 1
			z += (n-1)/2 
				
			print("#", end='')
		print('\n',end='')

	return ''
			
print(kratkeczka(9, 'abcdefghijkasdza'))

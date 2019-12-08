import matplotlib.image as mpimg
import matplotlib.pyplot as plt
import numpy as np
import random as rnd



class photo:
    def __init__(self, img):
        self.img = mpimg.imread(img)
    def __call__(self):
        return self.img



class photoeditor:
    def encode(self,image, sentance):
        zdjecie = image.img
        helper = zdjecie.copy()
        h,w,rgb = helper.shape
        encode_jumps = h//len(sentance)
        k = 0
        for i in range(len(sentance)):
            pixel_toencode = rnd.randint(k*encode_jumps,encode_jumps*(k+1))
            rand_width = rnd.randint(0,w)
            r = helper[pixel_toencode][rand_width][0]   
            helper[pixel_toencode][rand_width][0] = (ord(sentance[k]) )* 0.1  + r
            k +=1
        return helper


    def decode(self, decoded, real): 
        code = []
        for i in range(decoded.shape[0]):
            for j in range(decoded.shape[1]):
                if decoded[i][j][0] != real[i][j][0]:
                    code.append(chr(int(round((decoded[i][j][0] - real[i][j][0]) *10))))
        return "".join(code)
        



zdjecie = photo("shadow.png")
editor = photoeditor()
Encoded = editor.encode(zdjecie, "Bardzo dlugi tekst nw co sie dzieje prosze dzialaj")
print(editor.decode(Encoded, zdjecie()))


fig, (ax1, ax2) = plt.subplots(1,2, figsize=(10,10))
ax1.imshow(zdjecie())
ax1.set_title('Original Image')
ax2.imshow(Encoded)
ax2.set_title("Zakodowane")
plt.show()
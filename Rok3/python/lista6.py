import requests
import html.parser
import re
import bs4


class MyHTMLParser(html.parser.HTMLParser):
    lshref = list()

    def handle_starttag(self, tag, attrs):
        if tag == 'a':
            for (atr, val) in attrs:
                if atr == 'href':
                    self.lshref.append(val)



adres = "([a-zA-Z]+\.)*[a-zA-Z]+" 
automat = re.compile("https*://" + adres)
cos = []
myparser = MyHTMLParser()


def crawl(start_page, distance, action):
    if distance == 0:
        return None
    r = requests.get(start_page)
    myparser.feed(r.text)
    lista = myparser.lshref
    for i in lista:
        if automat.match(i) and i not in [x for x in cos]:
            yield ((i, action(i)))
            cos.append(i)
            yield from crawl(i, distance-1, action)


def yesa(x):
    r = requests.get(x)
    bs = bs4.BeautifulSoup(r.text, "html.parser")
    sent = bs.get_text()
    split = (x.strip() for x in sent.splitlines())
    text = '\n'.join(y for y in split)
    sent = re.split(r'[.?\n]', text)
    lista = list()
    for y in sent:
        if "Python" in y:
            lista.append(y)
    return lista


for x, y in (crawl("http://www.ii.uni.wroc.pl/~marcinm/dyd/python/", 1, yesa)):
    print("Url", x, "After action", y)

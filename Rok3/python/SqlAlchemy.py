from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, Integer, ForeignKey, String
from sqlalchemy.orm import relationship
from sqlalchemy.orm import sessionmaker
from sqlalchemy import create_engine
import sys

Base = declarative_base()


class Book(Base):
    __tablename__ = 'book'
    autor = Column(String(20), nullable=False)
    tytul = Column(String, ForeignKey('friends_list.tytul'),
                                    unique=True, primary_key=True)
    child = relationship("Friend_list", back_populates="parents")
    rok = Column(Integer, default=2019)


class Friend_list(Base):
    __tablename__ = 'friends_list'
    tytul = Column(String, primary_key=True)
    parents = relationship("Book", back_populates="child")
    email = Column(String)
    imie = Column(String)


engine = create_engine('sqlite:///:memory', echo=True)
Base.metadata.create_all(bind=engine)
Session = sessionmaker(bind=engine)
sesja = Session()


tabela = sys.argv[1]
arguments = sys.argv[2:]
print(tabela)

if len(arguments) == 1 and arguments[0] == "Wypisz":
    if tabela == "Book":
        for krotki in sesja.query(Book).all():
            print(vars(krotki))
    else:
        for krotki in sesja.query(Friend_list).all():
            print(vars(krotki))
else:
    if arguments[0] == "Dodaj":
        if tabela == "Book":
            a = input("Podaj autora : ")
            b = input("Podaj tytul : ")
            c = input("Podaj rok wydania : ")
            o = Book(autor=a, tytul=b, rok=c)
            sesja.add(o)
            sesja.commit()
    elif arguments[0] == "Wypozycz":
        a = input("Podaj tytul ksiazki do wypozyczenia: ")
        if sesja.query(Book).filter(Book.tytul == a).first() is not None:
            b = input("Podaj mail : ")
            c = input("Podaj imie : ")
            o = Friend_list(tytul=a, email=b, imie=c)
            sesja.add(o)
            sesja.commit()
            print("Wypozyczyles ksiazke {}".format(a))
        else:
            print("Brak ksiazki w bibliotece")
    if arguments[0] == "Oddaj":
        a = input("Podaj tytul ksiazki do oddania: ")
        if sesja.query(Friend_list).filter(Friend_list.tytul == a)\
                                            .first() is not None:
            sesja.query(Friend_list).filter(Friend_list.tytul == a).delete()
            print("Oddales ksiazke {}".format(a))
            sesja.commit()
        else:
            print("Nie bylo takiej ksiazki do oddania")




sesja.close()

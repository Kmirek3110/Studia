#lang racket
(define (dist a b)
  (abs(- a b)))
;;Liczy Ai
(define (Apriori  num den i)
  (cond[(= i -1) 1]
       [(= i 0) 0]
       [else (+
              (*(den i)(Apriori  num den (- i 1)))
               (*(num i)(Apriori  num den (- i 2))
                 ))
             ]))
(Apriori (lambda(i) (+ i 1)) (lambda(i)(* i 2)) 3)
;;Liczy Bi    
(define (Bpriori  num den i)
  (cond[(= i -1) 0]
       [(= i 0) 1]
       [else (+
              (*
               (den i)(Bpriori  num den (- i 1)))
               (*(num i)(Bpriori  num den (- i 2))
                 ))
             ]))
;;Ai/Bi       
(define (Fk f g)
  (/ f g))
(define (square x)(* x x))
;;Glówna funkcja
(define (glebokosc a b num den  )
  (define (iter i)
     (if(<(dist
         (Fk
          (a num den i)
          (b num den i ))
         (Fk
          (a num den (- i 1))
          (b num den (- i 1))))
        0.0001)
     (Fk(a num den i)(b num den i ))
     (iter (+ i 1))))
  (iter 1))
;;Do wyniku dodałem +3  ponieważ  , funkcja glebokosc liczyla tylko ze wzoru licznik/mianownik
;; a we Wzorze zadanie 7 jest  +3 na początku 
(+(glebokosc Apriori Bpriori (lambda(i)(square(-(* 2 i)1))) (lambda(i) 6.0))3)
(glebokosc Apriori Bpriori (lambda(i)(+ i 2.0)) (lambda(i)(* i 100)))
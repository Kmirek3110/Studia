#lang racket

(define (const? t)
  (number? t))


(define (binop? t)
  (and (list? t)
       (= (length t) 3)
       (member (car t) '(+ - * /))))


(define (binop-op e)
  (car e))

(define (binop-left e)
  (cadr e))

(define (binop-right e)
  (caddr e))

(define (binop-cons op l r)
  (list op l r))


(define (op->proc op)
  (cond [(eq? op '+) +]
        [(eq? op '*) *]
        [(eq? op '-) -]
        [(eq? op '/) /]))


(define (let-def? t)
  (and (list? t)
       (= (length t) 2)
       (symbol? (car t))))


(define (let-def-var e)
  (car e))

(define (let-def-expr e)
  (cadr e))

(define (let-def-cons x e)
  (list x e))

(define (let? t)
  (and (list? t)
       (= (length t) 3)
       (eq? (car t) 'let)
       (let-def? (cadr t))))

(define (let-def e)
  (cadr e))

(define (let-expr e)
  (caddr e))

(define (let-cons def e)
  (list 'let def e))

(define (var? t)
  (symbol? t))

(define (var-var e)
  e)

(define (var-cons x)
  x)

(define (hole? t)
  (eq? t 'hole))

(define (arith/let/holes? t)
  (or (hole? t)
      (const? t)
      (and (binop? t)
           (arith/let/holes? (binop-left  t))
           (arith/let/holes? (binop-right t)))
      (and (let? t)
           (arith/let/holes? (let-expr t))
           (arith/let/holes? (let-def-expr (let-def t))))
      (var? t)))

(define (num-of-holes t)
  (cond [(hole? t) 1]
        [(const? t) 0]
        [(binop? t)
         (+ (num-of-holes (binop-left  t))
            (num-of-holes (binop-right t)))]
        [(let? t)
         (+ (num-of-holes (let-expr t))
            (num-of-holes (let-def-expr (let-def t))))]
        [(var? t) 0]))

(define (arith/let/hole-expr? t)
  (and (arith/let/holes? t)
       (= (num-of-holes t) 1)))


(define (hole-context e)
  (define (sub-hole-context e context) 
    (cond
      [(let?  e)                                                    
       (if (arith/let/hole-expr? (let-def-expr (let-def e)))           
           (sub-hole-context (let-def-expr (let-def e)) context)          
           (sub-hole-context (let-expr e)                                
                             (let((el
                                   (let-def-var (let-def e))
                                   ))
                               (if (member el context)                      
                                   context                                 
                                   (cons el context))
                               )))]
      [(hole?  e) context]
      [(and (binop? e)
            (arith/let/hole-expr? (binop-left e)))
       (sub-hole-context (binop-left e) context)]
      [else (sub-hole-context (binop-right e) context)] 
      ))
  (sub-hole-context e null))





(define (test)
  (define tests    
    (list (list '(+ 3 hole) '())
          (list '(let(x hole) (let(y 7) (+ x 3))) '())
          (list '(let(x 3) (let(y 7) (+ x hole))) '(y x) )
          (list '(let(x 3) (let(y hole) (+ x 3))) '(x) )
          ))
  (define (test2 t)
    (cond
      [(null? t) #t]
      [(equal? (hole-context (first (first t)))
               (second (first t)))
       (test2 (cdr t))]
      [else (third (first t))]))
  (if (equal? (test2 tests) #t)
      (test2 tests)
      (and (print (test2 tests)) (newline) #f)))




(test)
  ( hole-context '(+ 3 hole ) )

 ( hole-context '( let ( x 3) ( let ( y 7) (+ x hole ) ) ) )

 ( hole-context '( let ( x 3) ( let ( y hole ) (+ x 3) ) ) )

 ( hole-context '( let ( x hole ) ( let ( y 7) (+ x 3) ) ) )

 ( hole-context '( let ( piesek 1)
                    ( let ( kotek 7)
                       ( let ( piesek 9)
                          ( let ( chomik 5)
                             hole ) ) ) ) )

 ( hole-context '(+ ( let ( x 4) 5) hole ) )






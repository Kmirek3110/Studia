#lang racket

(define(dist x y)
  (abs(- x y)))

(define(average x y)
  (/ (+ x y) 2))

(define (third_power x)
  (* x x x))


(define (third_root x)
  ;;lokalne
  (define (improve  approx)
    (average ( / (+( / x (* approx approx)) (* 2 approx ) ) 3) approx))
  (define (good-enough? approx)
    (< (dist x (third_power approx)) 0.00000001))
  (define(iter approx)
     (cond
       [(good-enough? approx) approx]
       [else          (iter (improve approx))]))
     (iter 1.0))

(third_root 125)
(third_root 8)
(third_root -8)
(third_root 4)
(third_root 1.125)
(third_root -1)
(third_root 8.125)
(third_root 216)
(third_root 1312)
(third_root 1231231)
#lang racket

(define (get-max n)
  (define max-val (read))
  (for ([i (- n 1)])
    (define curr-val (read))
    (when (> curr-val max-val)
      (set! max-val curr-val)))
  max-val)

(display "Enter the number of values to be compared:\n")
(define n (read))

(display "Enter the numbers:\n")
(define max (get-max n))

(display "The maximum number is:\n")
(display max)

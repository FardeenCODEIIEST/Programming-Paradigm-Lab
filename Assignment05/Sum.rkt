#lang racket

(define (get-sum n)
  (define ans 0)
  (for ([i n])
    (define curr-val (read))
    (set! ans (+ ans curr-val)))
  ans)

(display "Enter the number of numbers\n")
(define n (read))

(display "Enter the numbers\n")
(define sum (get-sum n))

(display "The sum of numbers is:\n")
(display sum)
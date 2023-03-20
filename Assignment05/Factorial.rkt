#lang racket
(define (factorial n)(if (<= n 1)1(* n (factorial (- n 1)))))
(display "Enter the natural number:")
(fprintf (current-output-port)"The factorial is ~a"(factorial (string->number(read-line(current-input-port) 'any))))



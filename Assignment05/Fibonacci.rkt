#lang racket
(define (fib n)(cond((= n 1)0)((= n 2)1)(else (+ (fib(- n 1))(fib(- n 2))))))
(display "Enter the position of the fibonacci number:")
(fprintf (current-output-port)"The required fibonacci number is ~a"(fib (string->number(read-line(current-input-port) 'any))))
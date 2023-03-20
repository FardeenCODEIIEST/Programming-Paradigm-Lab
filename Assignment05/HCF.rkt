#lang racket
(define (hcf a b)(if (> b a)(hcf b a)(if (= b 0)a(hcf b (modulo a b)))))
(display "Enter the numbers:\n")
(fprintf (current-output-port)"The HCF is ~a"(hcf (string->number(read-line(current-input-port) 'any)) (string->number(read-line(current-input-port) 'any))))

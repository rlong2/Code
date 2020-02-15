; Tutorial courtesy of Derek Banas
; https://www.youtube.com/watch?v=ymSq4wHrqyU


; start with cr and insert b or a between 'cr', moving from right to left
; car prints the first item
; cdr prints everything but the first item
; you can only use 4 characters in a list

(format t "1st item = ~a ~%" (car '(superman batman aquaman flash joker)))
(format t "2nd item = ~a ~%" (cadr '(superman batman aquaman flash joker)))
(format t "4th item = ~a ~%" (cadddr '(superman batman aquaman flash joker)))

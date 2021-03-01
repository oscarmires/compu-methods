; Actividad 2.2: parte 1

;; 3. Función roots
(define (roots a b c)
    (/ 
        (- (sqrt (- (expt b 2) (* 4 a c))) b)
        (* 2 a)
    )
)

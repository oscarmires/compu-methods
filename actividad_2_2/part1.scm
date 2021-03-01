; Actividad 2.2: parte 1

;; 3. Función roots
(define (roots a b c)
    (/ 
        (- (sqrt (- (expt b 2) (* 4 a c))) b)
        (* 2 a)
    )
)

;; 4. Función bmi
(define (bmiVal w h)
    (/ w (expt h 2))
)

(define (bmi w h)
    (define bmiResult (bmiVal w h))
    (cond
        ((< bmiResult 20) 'underweight)
        ((< bmiResult 25) 'normal)
        ((< bmiResult 30) 'obese1)
        ((< bmiResult 40) 'obese2)
        (else 'obese3)
    )
)

; Actividad 2.2: parte 1

;; 1. fahrenheit-to-celsius


;; 2. sign


;; 3. roots
(define (roots a b c)
    (/ 
        (- (sqrt (- (expt b 2) (* 4 a c))) b)
        (* 2 a)
    )
)

;; 4. bmi
(define (bmiVal w h)
    (/ w (expt h 2))
)2

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

;; 6. factorial

(define (reverse lista l-reverse)
    (cond
        ((null? lista) l-reverse)
        ((list? (car lista)) (reverse (cdr lista) (cons (reverse(car lista )'()) l-reverse)))
        (else (reverse (cdr lista) (cons (car lista) l-reverse)))
    )
)

(define (deep-reverse lista)
    (cond
        ((not(list? lista)) 'noEsLista)
        ((null? lista) '())
        (else(reverse lista '()))
    )
)
(define (duplicate-l lista l-duplicada)
    (cond
        ((null? lista) (deep-reverse l-duplicada))
        (else (duplicate-l (cdr lista) (cons (car lista) (cons (car lista) l-duplicada) )))
    )
)
(define (duplicate lista)
    (cond
        ((not(list? lista)) 'noEsLista)
        ((null? lista) '())
        (else(duplicate-l lista '()))
    )
)


;; 10. positives


(define (reverse lista l-reverse)
    (cond 
 ((null? lista) l-reverse)
 ((list? (car lista)) (reverse (cdr lista) (cons (reverse(car lista )'()) l-reverse)))
 (else (reverse (cdr lista) (cons (car lista) l-reverse)))
    )
)

(define (deep-reverse lista)
    (cond
        ((not(list? lista)) 'noEsLista)
        ((null? lista) '())
        (else(reverse lista '()))
    )
)
(define (positives-l lista l-positiva)
    (cond
        ((null? lista) (deep-reverse l-positiva))
        ((> (car lista) 0) (positives-l (cdr lista) (cons (car lista) l-positiva)))
        ((> 0 (car lista)) (positives-l (cdr lista) l-positiva))
    )
)
(define (positives lista)
    (cond
        ((not(list? lista)) 'noEsLista)
        ((null? lista) '())
        (else(positives-l lista '()))
    )
)


; Actividad 2.2: parte 2

;; 1. insert
(define (insert n lst)
    (cond
        ((null? lst) (list n))
        ((< n (car lst)) (cons n lst))
        (else (cons (car lst) (insert n (cdr lst))))
    )
)

;; 3. rotate-left
(define (isEmpty? list)
    (null? list)
)

(define (merge startList endList)
    (cond 
        ((isEmpty? startList) endList)
        ((isEmpty? endList) startList)
        (else (cons (car startList) (merge (cdr startList) endList)))
    )    
)

(define (leftSubArr n lst)
    (cond
        ((isEmpty? lst) '())
        ((> n 0) (cons (car lst) (leftSubArr (- n 1) (cdr lst))))
        (else '())
    )
)

(define (rightSubArr n lst)
    (cond
        ((isEmpty? lst) '())
        ((> n 0) (rightSubArr (- n 1) (cdr lst)))
        (else lst)
    )
)

(define (length lst)
    (cond
        ((isEmpty? lst) 0)
        (else (+ 1 (length (cdr lst))))
    )    
)

(define (rotate-left n lst)
    (define shift 
        (if (not (isEmpty? lst))
            (modulo n (length lst))
        )
    )
    (cond 
        ((= n 0) lst)
        ((isEmpty? lst) '())
        (else (merge (rightSubArr shift lst) (leftSubArr shift lst)))
    )
)

;; 6. deep-reverse
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


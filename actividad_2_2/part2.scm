; Actividad 2.2: parte 2

;; 1. insert


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

(define (shift-left n tempLst lst)
    (cond
        ((> n 0) (shift-left (- n 1) (merge tempLst (car lst)) (cdr lst)))
        ((< n 0) 'error)
        (else (merge lst tempLst))
    )
)

(define (rotate-left n lst)
    (cond
        ((> n 0) (shift-left n '() lst)
        (else lst)
    )
)

;; 6. deep-reverse


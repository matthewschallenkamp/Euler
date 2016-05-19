;this is project euler problem 3:
;What is the largest prime factor of the number 600851475143?
;solution: 6857

(defun list-factors (n)
    "returns a list of the factors of a number, low to hi"
    (let ((divisor 2) (factors ()) (top (sqrt n)))
        (loop 
            (if (> divisor top) (return (reverse factors)))
            (if (= 0 (mod n divisor))
                (setf factors (cons divisor factors)))
            (setf divisor (+ divisor 1)))))

(defun is-prime (n)
    "true if prime, false if not"
    (let ((divisor 2) (top (sqrt n)))
        (loop
            (if (> divisor top) (return t))
            (if (= 0 (mod n divisor)) (return nil))
            (setf divisor (+ divisor 1)))))

(defun is-empty (mylist) 
    "true if empty, false if not"
    (if (= 0 (length mylist)) t nil))

(defun only-primes (mylist)
    "returns a list of the primes in the sent list"
    (let ((return-list ()))
        (loop
            (if (is-empty mylist)
                (return (reverse return-list)))
            (if (is-prime (car mylist))
                (setf return-list (cons (car mylist) return-list)))
            (setf mylist (cdr mylist)))))

(defun prime-factors (n) 
	(only-primes (list-factors n)))

(reduce 'max (prime-factors 600851475143)))






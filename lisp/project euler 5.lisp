;this is project euler problem 5:
;What is the smallest positive number 
;evenly divisible by all of the numbers from 1 to 20?
;solution: 232792560 

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

(let ((x 1) (mylist nil) (limit 20))
	(loop
		(when (> x limit) 
			(setf mylist (reverse mylist))
			(return))
		(setf mylist (cons x mylist))
		(setf x (+ x 1)))
	(apply 'lcm mylist))
	


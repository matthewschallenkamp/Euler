(load "W:\\programming\\Lisp\\mylib.lisp")

(defvar *primes* 
  (with-open-file 
    (stream "W:\\programming\\Lisp\\1e6 primes.txt") 
    (read stream)))

(defun rotate (list)
	(append (cdr list) (list (car list))))))

(defun list-rotations (n) 
  (loop for rotator = (rotate (digits->list n)) then (rotate rotator)
      collect (list->digits rotator)
      until (= (list->digits rotator) n)))

(defun prime? (n) (find n *primes* :test #'=))

(defun all-primes (list)
  (not (member nil (map 'list #'prime? list))))

(let ((total 0))
  (loop for i in *primes*
        when (all-primes (list-rotations i)) 
          do (progn (incf total) (print i)) 
        finally total)
  total)
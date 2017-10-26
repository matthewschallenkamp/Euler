
(defvar *primes*
  (map 'vector #'identity
     (with-open-file (stream "1e6 primes.txt")
  		(read stream))))

(defvar *primes-list*
  (map 'list #'identity *primes*))


(defun binary-search (value array)
  (let ((low 0)
        (high (1- (length array))))

    (do () ((< high low) nil)
      (let ((middle (floor (+ low high) 2)))

        (cond ((> (aref array middle) value)
               (setf high (1- middle)))

              ((< (aref array middle) value)
               (setf low (1+ middle)))

              (t (return t)))))))

(defun is-prime (n)
	(cond
   ((= n 1) nil)
   ((binary-search n *primes*) t)
 		(t
     (loop for item in *primes-list*
				until (> item (* n n))
				when (= 0 (mod n item))
				do (return nil)
				finally (return t)))))

(defun permutations (lst)
	(cond
		((not (= 0 (length lst)))
			(loop for item in lst
				append (loop for sub-perm in (permutations (remove item lst)) collect (cons item sub-perm))))
		(t (list nil))))

(defun combine (lst)
	(let ((s 0))
		(loop for item in lst
			do (setf s (+ (* s 10) item))
			finally (return s))))

(defun splits (lst)
	(cond
		((not (= 1 (length lst)))
			(loop for sub-splits in (splits (cdr lst))
					append (loop for item in sub-splits
							collect (cons (cons (car lst) item) (remove item sub-splits))) into res
		     	collect (cons (list (car lst)) sub-splits) into res
    		  finally (return res)))
		(t (list (list lst)))))

(defun inner-permutations (lst)
  (cond
    ((not (= 0 (length lst)))
     	(loop for sub-perm in (inner-permutations (cdr lst))
            append (loop for item in (permutations (car lst))
                         collect (cons item sub-perm))))
    (t (list nil))))

;(print (map 'list #'inner-permutations (splits (list 1 2 3)))

;(print (map nil #'inner-permutations (splits (list 1 2 3 4 5 6 7 8 9)))

(loop for lst in (splits (list 1 2 3 4 5 6 7 8 9))
      sum (loop for spot in (inner-permutations lst)
	      ; when (every #'is-prime (map 'list #'combine spot))
	      ; do (print (map 'list #'combine spot))
 	      when (every #'is-prime (map 'list #'combine spot))
 	      sum 1))

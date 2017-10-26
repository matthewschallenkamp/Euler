
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

(let ((ct 0) (sm 0) (a 0))
	(loop for i from 2
    always (< ct 25)
		when (not (is-prime i))
		when (= 1 (gcd i 10))
		do
		(progn
			(setf a (loop for j from 1 upto i
									for r = 1 then (1+ (* 10 r))
									until (= 0 (mod r i))
									finally (return j)))
			(when (= 0 (mod (1- i) a))
				(incf ct)
				(setf sm (+ sm i))
				(print (list i a)))))
 (print sm))

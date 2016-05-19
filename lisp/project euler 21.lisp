(defun sum-of-divisors (n)
  (let ((sum 0))
    (loop for i from 1 to (- n 1)
       do (when (= 0 (mod n i))
	    (setf sum (+ i sum)))
       finally (return sum))))

(defun amicable? (n)
  (let ((partner (sum-of-divisors n)))
    (if (= n partner)
	nil
	(if (= n (sum-of-divisors partner))
	    t
	    nil))))

(reduce #'+ 
	(loop 
	   for i from 1 to 10000
	   collect (if (amicable? i) i 0)))

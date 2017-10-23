(defvar *primes*
  (with-open-file
      (stream "1e6 primes.txt")
    (read stream)))

(let ((memo (make-hash-table)))
	(defun ct_sums (num top)
		(cond
			((= 0 num) 1)
			((> 0 num) 0)
			(t
				(setf (gethash (list num top) memo)
					(loop for item in *primes*
					     until (> item top)
					     sum (ct_sums (- num item) item)))))))

(loop for i from 1
	until (> 5000 (ct_sums i i))
	finally (print i))
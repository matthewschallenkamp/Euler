(defun eratosthenes (n)
  (declare (optimize speed (safety 0) (debug 0))
           (fixnum n))
  (let ((bit-vector (make-array n :initial-element 1 :element-type 'bit)))
    (loop for i from 2 upto (isqrt n) do
         (loop for j fixnum from i
            for index fixnum = (* i j)
            until (>= index n) do
            (setf (sbit bit-vector index) 0)))
    (loop for i from 2 below (length bit-vector)
       unless (zerop (sbit bit-vector i)) collect i)))

(defvar *primes* (eratosthenes 100000))

(defun factors (n)
	(loop for item in *primes*
		until (> item n)
		when (= 0 (mod n item))
		collect
			(loop until (not (= 0 (mod n item)))
				do (setf n (/ n item))
				finally (return item))))

(defun radpairs (n)
	(loop for i from 1 upto n
		collect (list (reduce #'* (factors i)) i)))

(nth 10000 (stable-sort (radpairs 100000) (lambda (l r) (< (car l) (car r)))))
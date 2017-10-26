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

(defvar *primes-list* (eratosthenes 10000000))

(defun expt-mod (n exponent modulus)
 (cond
   ((= 0 exponent) 1)
   ((= 1 exponent) (mod n modulus))
 	 (t (let ((sub (expt-mod n (truncate (/ exponent 2)) modulus)))
       (mod
         (* (if (oddp exponent) n 1) (* sub sub))
         modulus)))))

(loop for a in *primes-list*
      for n from 1
  when (= 0 (mod n 100))
  do (print (list n a))
	until (and (< 10000000000 (* a a)) (< 10000000000 (mod (+ (expt-mod (1- a) n (* a a)) (expt-mod (1+ a) n (* a a))) (* a a))))
	finally (print (list "this is a solution" n a)))



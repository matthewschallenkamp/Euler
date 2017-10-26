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

(defvar *primes* (eratosthenes 1000000))


(defun rep (n)
	(loop for j from 1 upto n
				for r = 1 then (1+ (* 10 r))
				finally (return r)))

(defun ldiv (numct den)
	(let ((memo (make-hash-table :test #'equal :size 120000)))
		(loop with i = 1
					for r = 1 then (mod (1+ (* 10 r)) den)
;					do (print (list i r (- numct i)))
;					do (print (loop for key being the hash-keys of memo
;                using (hash-value value)
;                collect (list key value)))
					when (gethash r memo)
					do
;						(progn
							(setf i (max i (- numct (mod (- numct (gethash r memo)) (- i (gethash r memo))))))
;							(print (list i (gethash r memo) r (- numct (gethash r memo)) (mod (- numct (gethash r memo)) (- i (gethash r memo))))))
					do (setf (gethash r memo) i)
					until (>= i numct)
					do (incf i)
					finally (return (= 0 r)))))

; initial bit ... oldidx .. newidx .. end
; we want n < end - oldidx / (newidx - oldidx)

(defvar res nil)

(setf res (loop for prime in *primes*
			do (print (list (length selected) prime))
			when (ldiv (expt 10 9) prime)
			collect prime into selected
			until (= 40 (length selected))
			finally (return selected)))

(reduce #'+ res)
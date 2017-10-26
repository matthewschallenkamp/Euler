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

(let ((memo (make-hash-table :test #'equal :size 120000)))
	(defun factors (n)
		(or (gethash n memo)
    	(setf (gethash n memo)
				(loop for item in *primes*
					until (> item n)
					when (= 0 (mod n item))
					collect
						(loop until (not (= 0 (mod n item)))
							do (setf n (/ n item))
							finally (return item)))))))

(let ((memo (make-hash-table :test #'equal :size 120000)))
	(defun rad (n)
		(or (gethash n memo)
			(setf (gethash n memo)
				(reduce #'* (factors n))))))

(defun optimizable ()
  (declare (optimize (speed 3) (safety 0)))
	(time
	  (loop for c from 2 upto 120000
	        for rc = (rad c) then (rad c)
			when (< (* 6 rc) c)
			sum
				(loop with sm = 0
							for a from 2
							for b from (- c 2) downto 1
							until (>= a b)
		     			when (= 1 (gcd a b))
		     			when (< (* (rad a) (rad b) rc) c)
							do (progn
									(print (list a b c (* (rad a) (rad b) rc)))
									(setf sm (+ c sm)))
							finally (return sm)) into s
			when (< (* (rad 1) (rad (1- c)) rc) c)
	   	sum c into s
	    finally (return s))))

(optimizable)

; lets say c has 2 factors, share no fractions with c
; c might reduce to 5 * 7 * ...
; a and b reduce to 2 and 3 respectively, that's still 6 * rad of c to care about
; only trouble is factors of 1
; so pull those out seperate, always calc

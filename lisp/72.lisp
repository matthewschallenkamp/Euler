(defvar *primes*
  (with-open-file
      (stream "1e6 primes.txt")
    (read stream)))

(defun totient (n)
  (let ((res n))
    (loop for i in *primes*
      until (or (> i n) (> i 3200))
      when (= 0 (mod n i))
      do (progn
          (loop while (= 0 (mod n i))
              do (setf n (/ n i)))
          (setf res (/ (* res (1- i)) i))))
    (if (= 0 (1- n))
      res
      (/ (* res (1- n)) n))))

(print (loop for i from 2 upto 1000000
	sum (totient i) into res
 	finally (return res)))

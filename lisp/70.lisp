(defvar *primes*
  (with-open-file
      (stream "1e6 primes.txt")
    (read stream)))

(defun digits->list (n)
  (map 'list #'digit-char-p (prin1-to-string n)))

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

(time
  (let ((rat 10000000) (num 0))
    (loop for k in *primes*
          do (loop for j in *primes*
                for i = (* k j) then (* k j)
                while (< i 10000000)
                for y = (totient i) then (totient i)
                when (and (< (/ i y) rat) (equal (sort (digits->list i) #'<) (sort (digits->list y) #'<)))
                do (progn
                     (setf rat (/ i y))
                     (setf num i))))
    (print rat)
    (print num)))


(time
  (let ((rat 10000000) (num 0))
    (loop for i from 2 to 10000000
        for y = 1 then (totient i)
        when (and (< (/ i y) rat) (equal (sort (digits->list i) #'<) (sort (digits->list y) #'<)))
        do (progn
             (setf rat (/ i y))
             (setf num i)))
    (print rat)
    (print num)))

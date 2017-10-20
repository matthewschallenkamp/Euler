(defvar *primes* 
  (with-open-file 
      (stream "1e6 primes.txt") 
    (read stream)))

(defun list-rotations (n) 
  (loop for rotator = (rotate (digits->list n)) then (rotate rotator)
      collect (list->digits rotator)
      until (= (list->digits rotator) n)))

(defun prime? (n) (find n *primes* :test #'=))

(defun all-primes (list)
  (not (member nil (map 'list #'prime? list))))

(loop for i in *primes*
      do (print i)
      counting (all-primes (list-rotations i)))

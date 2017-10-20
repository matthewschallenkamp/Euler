(defun fib (n)
  (if (> 3 n) 1
      (let ((a 1) (b 1) (i 2))
	(loop
	  (setf a (+ a b))
	  (incf i)
	  (when (= i n) (return a))
	  (setf b (+ a b))
	  (incf i)
	  (when (= i n) (return b))))))

(defun digits->list (n) 
  (map 'list #'digit-char-p (prin1-to-string n)))

(let ((i 3))
  (loop until
        (= 1000 (length (digits->list (fib i))))
        do (incf i)  
        finally (return i)))


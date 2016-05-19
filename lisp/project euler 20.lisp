(defun factorial (n)
  (let ((multiple 1))
    (loop
       (if (> 1 n)
	   (return multiple))
       (setf multiple (* multiple n))
       (setf n (- n 1)))))

(defun digits->list (n) 
  (map 'list #'digit-char-p (prin1-to-string n)))

(reduce #'+ (digits->list (factorial 100)))
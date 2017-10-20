(defun collatz (n)
  (if (evenp n)
      (/ n 2)
      (+ (* 3 n) 1)))


(defun collatz-length (n)
  (if (= 1 n)
      1
      (+ 1 (collatz-length (collatz n)))))

(defun find-first (item list)
  (let ((i 1))
    (loop
      (if (equal item (car list))
          (return i)
          (progn
            (setf list (cdr list))
            (setf i (+ i 1)))))))

(let ((lengths (loop for i from 1 to 1000000 collect (collatz-length i))))
  (find-first (reduce #'max lengths) lengths))

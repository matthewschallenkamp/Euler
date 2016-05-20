;find the first triangle number with over 500 divisors

(defun int-list (finish)
  (loop for i = 1 then (+ 1 i) until (> i finish) collect i))

(defmacro rtfor ((iterator start test increment return-value) &body body)
  "rfor and tfor in one"
  `(let ((,iterator ,start))
     (loop
       (if ,test (return ,return-value))
       ,@body
       (setf ,iterator (+ ,iterator ,increment)))))

(defun number-of-divisors (number)
  (let* ((dirt (int-list (sqrt number))) (gold 0))
    (loop
      (if (= 0 (length dirt)) (return (* 2 gold)))
      (if (= 0 (mod number (car dirt))) (setf gold (+ 1 gold)))
      (setf dirt (cdr dirt)))))

(let ((triangle 0) (divisors 0))
  (rtfor (i 1 (> divisors 500) 1 triangle)
    (setf triangle (+ triangle i))
    (setf divisors (number-of-divisors triangle))
    (print (list 'triangle i 'is triangle 'with divisors 'divisors))))


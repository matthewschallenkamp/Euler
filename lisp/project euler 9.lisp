;project euler problem 9:
;There exists exactly one Pythagorean triplet for which a + b + c = 1000.
;Find the product abc.
;solution 31875000

(defmacro rtfor ((iterator start test increment return-value) &body body)
  "rfor and tfor in one"
  `(let ((,iterator ,start))
     (loop
       (if ,test (return ,return-value))
       ,@body
       (setf ,iterator (+ ,iterator ,increment)))))

(let ((c 1) (value 0))
  (rtfor (a 1 (> a 1000) 1 value)
    (rtfor (b 1 (> b (- 1000 a)) 1 value)
      (setf c (- 1000 (+ a b)))
      (if (= (* c c) (+ (* a a) (* b b)))
          (setf value (* a b c))))))
		
		

;this is project euler problem 3:
;What is the largest prime factor of the number 600851475143?
;solution: 6857

(defun is-prime (n)
  "true if prime, false if not"
  (let ((divisor 2) (top (sqrt n)))
    (loop
      (if (> divisor top) (return t))
      (if (= 0 (mod n divisor)) (return nil))
      (setf divisor (+ divisor 1)))))

(loop for div = (floor (sqrt 600851475143)) then (1- div)
      when (and (zerop (mod 600851475143 div)) (is-prime div))
        return div)




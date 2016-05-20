(defun sum-of-divisors (n)
  (let ((sum 0))
    (loop for i from 1 to (- n 1)
          when (zerop (mod n i))
            sum i into sum 
          finally (return sum))))

(defun amicable? (n)
  (let ((partner (sum-of-divisors n)))
    (and (not (= n partner)) (= n (sum-of-divisors partner)))))

(loop 
  for i from 1 to 10000
  when (amicable? i)
    sum i into sum
  finally (return sum))

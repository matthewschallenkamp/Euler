;this is project euler problem 1:
;Find the sum of all the multiples of 3 or 5 below 1000.
;solution: 233168

(loop for i from 1 upto 999
      when (zerop (mod i 3))
        sum i into threes
      when (zerop (mod i 5))
        sum i into fives
      when (zerop (mod i 15))
        sum i into fifteens
      finally (return (- (+ threes fives) fifteens)))

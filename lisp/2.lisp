;this is project euler problem 2:
;By considering the terms in the Fibonacci sequence whose values do not exceed four million
;find the sum of the even-valued terms.
;solution: 4613732
(loop for a = 1 then b
      for b = 1 then c
      for c = 1 then (+ a b)
      when (> c 4000000)
        return total
      when (evenp c)
        sum c into total)

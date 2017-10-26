
(loop for i from 1000000
	until (and (= 1 (gcd i 10))
		(loop for j from 1 upto 1000000
					for r = 1 then (1+ (* 10 r))
					when (= 0 (mod j 5000))
					do (print (list i j))
					never (= 0 (mod r i))))
	finally (print i))
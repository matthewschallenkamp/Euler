
(time (print
	(let ((best_diff 1) (best))
		(loop for i from 1000000 downto 1
			do (loop for j from (truncate (* i (/ 3 7))) downto 1
					until (and (not (= (/ 3 7) (/ j i))) (< best_diff (- (/ 3 7) (/ j i))))
					when (not (= (/ 3 7) (/ j i)))
     			do (progn
							(setf best (list j i))
							(setf best_diff (- (/ 3 7) (/ j i)))
 							(print best))))
		best)))

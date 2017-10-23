

(defun triangle (ax ay bx by)
	(let ((a (+ (* ax ax) (* ay ay))) (b (+ (* bx bx) (* by by)))
				(c (+ (* (- bx ax) (- bx ax)) (* (- by ay) (- by ay)))))
		(and (< 0 a) (< 0 b) (< 0 c) (= (* 2 (max a b c)) (+ a b c)))))

((lambda (arg) (print arg) (print (length arg)))
	(loop for ix from 0 to 50
		append (loop for iy from 0 to 50
			append (loop for jx from 0 to 50
				append (loop for jy from iy to 50
					when (and (triangle ix iy jx jy) (or (> jy iy) (> jx ix)))
					collect (list ix iy jx jy))))))
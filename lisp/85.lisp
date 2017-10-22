; ok so we have to loop through the sizes
; then through the sizes of rectangles for the sum

(defun rect_ct (a b)
  (loop for sx from 1 upto a
        sum (loop for sy from 1 upto b
                 sum (* (1+ (- a sx)) (1+ (- b sy))) into res
                 finally (return res)) into res2
        finally (return res2)))

(let ((best nil) (bdiff 1005) (lim (* 2 (sqrt 2000000))))
	(loop for x from 1 upto lim
       do (loop for y from 1 upto lim
             for res = (abs (- 2000000 (rect_ct x y))) then (abs (- 2000000 (rect_ct x y)))
             when (> bdiff res)
             do (progn
                  (setf best (list x y res (rect_ct x y) (* x y)))
                  (setf bdiff res)
                  (print best))
             until (> res 2000000)))
 (print best))
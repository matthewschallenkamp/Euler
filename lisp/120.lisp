(defun expt-mod (n exponent modulus)
 (cond
   ((= 0 exponent) 1)
   ((= 1 exponent) (mod n modulus))
 	 (t (let ((sub (expt-mod n (truncate (/ exponent 2)) modulus)))
       (mod
         (* (if (oddp exponent) n 1) (* sub sub))
         modulus)))))

(defun rmax (a)
	(let ((b (1- a)) (c (1+ a)) (md (* a a)) (hit nil) (mx 0))
		(loop for n from 1
					for mb = (expt-mod b n md) then (expt-mod b n md)
					for mc = (expt-mod c n md) then (expt-mod c n md)
					until (member (list mb mc) hit :test #'equal)
					do (progn
						(setf hit (cons (list mb mc) hit))
						(setf mx (max mx (mod (+ mb mc) md)))))
  	mx))

(loop for a from 3 upto 1000
	do (print (list a (rmax a)))
	sum (rmax a))
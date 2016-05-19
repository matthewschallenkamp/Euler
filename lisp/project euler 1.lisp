;this is project euler problem 1:
;Find the sum of all the multiples of 3 or 5 below 1000.
;solution: 233168

(defun list-multiples-3-5 (n)	
   (let ((x 1) (total nil))
	(loop 
	     (if (or (> x n) (= x n)) 
	       (return (reverse total)))
	     (if (= 0 (mod x 5))
	       (setf total (cons x total)))
	     (if (= 0 (mod x 3))
	       (if (not (= 0 (mod x 5)))
	      (setf total (cons x total))))
         (setf x (+ x 1)))))

(defun sum_list (mylist) 
	(apply '+ mylist))

(sum_list (list-multiples-3-5 1000))
;this is project euler problem 6:
;Find the difference between the sum of the squares and the square of the sum
;of the first one hundred natural numbers.
;solution: 25164150 

(defun sum-of-squares (mylist)
  (let ((total 0))
    (loop
      (if (= 0 (length mylist))
	  (return total))
      (setf total (+ total (expt (car mylist ) 2 )))
      (setf mylist (cdr mylist)))))

(defun square-of-sum (mylist)
  (expt (apply '+ mylist) 2))

(let ((x 1) (mylist nil) (limit 100))
  (loop
    (if (> x limit) (return))
    (setf mylist (cons x mylist))
    (setf x (+ x 1)))
  (- (square-of-sum mylist) (sum-of-squares mylist)))
     

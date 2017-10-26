(defun digits->list (n)
  (map 'list #'digit-char-p (prin1-to-string n)))

;Find the sum of all the numbers less than 108 that are both palindromic and can be written as the sum of consecutive squares.

(defun palindromic (n)
  (equal (digits->list n) (reverse (digits->list n))))

(defun sqsum (n)
	(let ((s 1) (e 2) (sm 1))
		(loop
    	when (< sm n)
			do (progn
					(setf sm (+ sm (* e e)))
					(incf e))
			when (> sm n)
			do (progn
					(setf sm (- sm (* s s)))
     			(incf s))
			until (= (1+ s) e)
	   	until (= sm n)
			finally
   			(progn
         (return (not (= (1+ s) e)))))))

(loop for i from 2 upto (expt 10 8)
      when (and (palindromic i) (sqsum i))
      do (print i)
      when (and (palindromic i) (sqsum i))
      sum i)


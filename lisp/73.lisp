
(defun list->unique (lst)
	(let ((slst (sort lst #'<)))
		(cons (car slst)
			(loop for a in slst
				for b in (cdr slst)
				when (not (= a b))
				collect b))))

(time (print (length (list->unique
	(loop for i from 1 to 12000
		append (loop for j from 1 to 12000
				if (and (< (/ 1 3) (/ i j)) (> (/ 1 2) (/ i j)))
				collect (/ i j)))))))

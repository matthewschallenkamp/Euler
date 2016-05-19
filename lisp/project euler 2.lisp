;this is project euler problem 2:
;By considering the terms in the Fibonacci sequence whose values do not exceed four million
;find the sum of the even-valued terms.
;solution: 4613732

(defun list-fibonacci (under)
	"lists fibonacci numbers in order"
	(let ((fibs nil) 
		  (a 0) 
		  (b 1))
		(loop
			(setf a (+ a b))
			(if (> a under) 
				(return (reverse fibs)))
			(setf fibs (cons a fibs))
			(setf b (+ b a))
			(if (> b under) 
				(return (reverse fibs)))
			(setf fibs (cons b fibs)))))

(defun sum-list (mylist) 
	(apply '+ mylist))

(defun is-empty (mylist) 
    "true if empty, nil if not"
    (if (= 0 (length mylist)) t nil))

(defun even (n) 
	"true if even, nil if not"
	(if (= 0 (mod n 2)) t nil))

(defun remove-odds (mylist)
	"returns mylist with the odd numbers removed"
	(let ((return-list nil))
		(loop
			(if (is-empty mylist) (return (reverse return-list)))
			(if (even (car mylist))
				(setf return-list (cons (car mylist) return-list))) ;append to the return list
			(setf mylist (cdr mylist))))) ;remove one element from source each time

(sum-list (remove-odds (list-fibonacci 4000000)))
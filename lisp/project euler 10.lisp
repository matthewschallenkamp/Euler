;project euler problem 10:
;Find the sum of all the primes below two million.
;solution: 142913828922

;note that the runtime for this is well over an hour, 
;I will maybe revisit this someday and rewrite it to be more efficient, but not today.

(defun make-my-int-list (finish)
   (cons 2 (loop for i = 3 then (+ 2 i) until (> i finish) collect i)))

;rewriting as no recursion
(defun remove-divisibles (mylist divisor)
  (if (= 0 (length mylist)) ()
      (remove nil (cons (if (/= 0 (mod (car mylist) divisor))
			    (car mylist))
			(remove-divisibles (cdr mylist) divisor)))))

(defun remove-divisibles-nor (mylist divisor)
  (let ((return-list nil))  
    (loop
      (if (= 0 (length mylist)) (return (reverse return-list))) 
      (if (= 0 (mod (car mylist) divisor))
	  ()
	  (setf return-list (cons (car mylist) return-list)))
      (setf mylist (cdr mylist)))))

(defun nth-item (n mylist)
    (if (= n 1) 
        (car mylist) 
        (nth-item (1- n) (cdr mylist))))

(defun nth-cdr (n mylist)
    (if (= n 1) 
        (cdr mylist) 
        (nth-cdr (1- n) (cdr mylist))))

(defun upto-nth (n mylist)
  (if (= n 0)
      ()
      (cons (car mylist) 
	    (upto-nth (1- n) (cdr mylist)))))

(defun sieve (n)
  (let ((dirt (make-my-int-list n)) (x 2))
    (loop
      (print (nth-item x dirt))
      (setf dirt (nconc (upto-nth x dirt) 
			(remove-divisibles-nor (nth-cdr x dirt) 
					       (nth-item x dirt))))
      (if (> x n) (return dirt))
      (if (> (expt (nth-item x dirt) 2) n) 
	  (return dirt))
      (setf x (+ x 1)))))

(reduce '+ (sieve 2000000))
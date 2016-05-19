;this is project euler problem 7:
;What is the 10,001st prime number?
;solution: 


(defun make-int-list (from to)
  (let ((mylist nil))
    (loop
      (if (> from to) (return (reverse mylist)))
      (setf mylist (cons from mylist))
      (setf from (+ 1 from)))))

;rewriting with no recursion
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
  (let ((dirt (make-int-list 2 n)) (x 1))
    (loop
      (print (nth-item x dirt))
      (setf dirt (nconc (upto-nth x dirt) (remove-divisibles-nor (nth-cdr x dirt) (nth-item x dirt))))
      (if (> x n) (return dirt))
      (if (> (expt (nth-item x dirt) 2) n) (return dirt))
      (setf x (+ x 1)))))

(nth-item 10001 (sieve 120000)) ;any arbitrarially large int, if not large will return nil
(defun sum-of-divisors (n)
  (let ((sum 0))
    (loop for i from 1 to (- n 1)
       do (when (= 0 (mod n i))
	    (setf sum (+ i sum)))
       finally (return sum))))

(defun abundant? (n)
  (if (< n (sum-of-divisors n)) t nil))

;all numbers after 28123 can be made as a sum of two abundant numbers
(defvar *max* 28123)

(defvar *abundants* (loop for i from 2 to *max* when (abundant? i) collect i)))

(defun add-across (number list)
  "adds number to each item of list"
  (let ((rlist ()))
    (loop
       (if (= 0 (length list)) (return (reverse rlist)))
       (setf rlist (cons (+ number (car list)) rlist))
       (setf list (cdr list)))))

(defun adds-possible (parts list)
  (if (= 1 parts)
      list
      (let ((collector) (mylist list))
	(loop
	   (if (> (length mylist) 1)
	       (setf collector
		     (append (add-across (car mylist) 
				       (adds-possible (- parts 1) (cdr mylist)))
			   collector))
	       (return (remove-duplicates collector)))
	   (setf mylist (cdr mylist))))))

(defun remove-items (items list)
  (loop
     (if (= 0 (length items))
	 (return list))
     (setf list (remove (car items) list))
     (setf items (cdr items))))

(let ((numbers (adds-possible 2 *abundants*)))
  (reduce #'+ 
	  (remove-items numbers 
			(loop for i from 1 to *max* 
			   collect i))))

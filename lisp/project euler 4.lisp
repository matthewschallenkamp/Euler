;this is project euler problem 4:
;Find the largest palindrome made from the product of two 3-digit numbers.
;solution 906609

(defun nth-digit (n mynumber)
  (mod (ftruncate (/ mynumber (expt 10 (1- n)))) 10))

(defun nth-item (n mylist)
  (if (= n 1) 
      (car mylist) 
      (nth-item (1- n) (cdr mylist))))

(defun number-to-list (n)
  (let ((num-list nil))
    (loop
      (if (= n 0) (return num-list))
      (setf num-list (cons (nth-digit 1 n) num-list))
      (setf n (ftruncate (/ n 10))))))

(defun last-item (mylist)
  (nth-item (length mylist) mylist))

(defun is-palindrome (n-list)
  (let ((n-length (length n-list)))
    (if (or (= n-length 1) (= n-length 0)) 
        t
        (if (= (last-item n-list) (car n-list))
            (is-palindrome (reverse (cdr (reverse (cdr n-list))))) ;take off the first and last elements
            nil))))


(reduce
 'max
 (let ((a 100) (limit 999) (palindromes nil))
   (loop
     (if (> a limit) (return palindromes))
     (let ((b 100))
       (loop
             (if (> b limit) (return))
             (if (is-palindrome (number-to-list (* a b)))
                 (setf palindromes (cons (* a b) palindromes)))
             (setf b (+ b 1))))
     (setf a (+ a 1)))))

;;;this is a collection of all my functions and macros created during project euler

;(load "W:\\programming\\Lisp\\mylib.lisp")

;;;list processing

(defun rotate (list)
  (append (cdr list) (list (car list))))

(defun digits->list (n)
  (map 'list #'digit-char-p (prin1-to-string n)))

(defun list->digits (list)
  (let ((rlist (reverse list)) (power -1))
    (reduce #'+ 
            (loop 
              for digit in rlist 
              do (setf power (+ 1 power)) 
              collect (* digit (expt 10 power))))))

(defun last-item (mylist)
  (nth (length mylist) mylist))

(defun is-in (item list)
  "returns true of the number is in the list"
  (if (= 0 (length list)) nil
      (if (equal item (car list)) t
          (is-in item (cdr list)))))

(defun nth-cdr (n mylist)
    (if (<= n 1) 
        (cdr mylist) 
        (nth-cdr (1- n) (cdr mylist))))

(defun upto-nth (n mylist)
  (if (= n 0)
      ()
      (cons (car mylist) 
            (upto-nth (1- n) (cdr mylist)))))

(defun adds-possible (parts list)
  "returns all of the possible additions made from parts parts from the numbers in the list"
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

(defun add-across (number list)
  "adds number to each item of list"
  (let ((rlist ()))
    (loop
      (if (= 0 (length list)) (return (reverse rlist)))
      (setf rlist (cons (+ number (car list)) rlist))
      (setf list (cdr list)))))

;;;primes and divisors

(defun list-divisors (n)
  (let ((divisors))
    (loop for i from 1 to (- n 1)
          do (when (= 0 (mod n i))
               (setf divisors (cons i divisors)))
          finally (return divisors))))

(defun sum-of-divisors (n)
  (let ((sum 0))
    (loop for i from 1 to (- n 1)
          do (when (= 0 (mod n i))
               (setf sum (+ i sum)))
          finally (return sum))))

(let ((primes)) (max 0)
  (defun is-prime-sieve (n)
    (when (> n max) 
        (setf max n)
        (setf primes (sieve n)))
    (if (is-in n primes)
        t
        nil))
  (defun setup-is-prime-sieve (n)
    (setf primes (sieve n))
    (setf max n)))

(defun is-prime (n)
  "true if prime, nil if not"
  (let ((divisor 2) (top (sqrt n)))
    (loop
      (if (> divisor top) (return t))
      (if (= 0 (mod n divisor)) (return nil))
      (setf divisor (+ divisor 1)))))

(defun remove-divisibles (mylist divisor)
  (if (= 0 (length mylist)) ()
      (let ((rest (remove-divisibles (cdr mylist) divisor)))
        (if (/= 0 (mod (car mylist) divisor))
            (cons (car mylist) rest)
            rest))))

(defun remove-divisibles-norecursion (mylist divisor)
  (let ((return-list nil))  
    (loop
      (if (= 0 (length mylist)) (return (reverse return-list))) 
      (if (= 0 (mod (car mylist) divisor))
          ()
          (setf return-list (cons (car mylist) return-list)))
      (setf mylist (cdr mylist)))))

(defun sieve (n)
  "returns a list of the prime numbers upto n, extremely slow"
  (let ((dirt (cons 2 (loop for i from 3 to n by 2 collect i))) (x 0))
    (loop
      (print (nth x dirt))
      (setf dirt (append (upto-nth x dirt) (list (nth x dirt)) (remove-divisibles-norecursion (nthcdr x dirt) (nth x dirt))))
      (if (> (expt (nth x dirt) 2) n) (return dirt))
      (setf x (+ x 1)))))

(defun cleanse (primes step i)
  (if (<= i (length primes))
    (loop for n from i to (length primes) by step
      do (setf (nth (1- n) primes) nil)
      finally (return primes))
    primes))

(defun sieve-step (primes i)
  (if (< i (length primes))
    (loop for n from i by 2
      when (nth (1- n) primes) 
        do (progn
            (setf primes (cleanse primes (* 2 n) (* n n)))
            (print n))
      until (> (* n n) (length primes))
      finally (return primes))
    primes))

; I would love thos to be faster. 
; currently running 4.63 seconds for 1e5
; currently running 733+ seconds for 1e6

(defun prime-sieve (i)
  "returns a list of the prime numbers upto n, takes about 8 seconds for 1e5, 1140 for 1e6"
  (remove nil 
          (sieve-step 
              (progn 
                (if (= 0 (mod i 2)) (decf i))
                (let ((mylist ()))
                  (loop for n from i downto 3 by 2
                        do (setf mylist (cons n mylist)))
                  (append '(nil 2) mylist)))
              3)))

;;;number processing

(defun digits (n)
  "returns how many digits there are in the number"
  (length (digits->list (n))))

(defun factorial (n)
  "returns factorial of n"
  (let ((multiple 1))
    (loop
      (if (> 1 n)
          (return multiple))
      (setf multiple (* multiple n))
      (setf n (- n 1)))))

(defun bfactorial (n)
  (if (= 1 n)
      1
      (* n (factorial (- n 1)))))

;;;other mathematical formulas

(defun collatz (n)
  (if (evenp n)
      (/ n 2)
      (+ (* 3 n) 1)))

(defun collatz-chain (n)
  (if (= 1 n)
      (list 1)
      (cons n (collatz-chain (collatz n)))))

(defun collatz-length (n)
  "returns the length of the collatz chain for n"
  (if (= 1 n) 1
      (+ 1 (collatz-length (collatz n)))))

(defun amicable? (n)
  "returns t if n is amicable and nil if not"
  (let ((partner (sum-of-divisors n)))
    (if (= n partner)
        nil
        (if (= n (sum-of-divisors partner))
            t
            nil))))

(defun abundant? (n)
  "returns true if the number is abundant, nil if not"
  (if (< n (sum-of-divisors n)) t nil))

(defun fib (n)
  "returns the nth fiobonacci number"
  (if (> 3 n) 1
      (let ((a 1) (b 1) (i 2))
        (loop
          (setf a (+ a b))
          (incf i)
          (when (= i n) (return a))
          (setf b (+ a b))
          (incf i)
          (when (= i n) (return b))))))

;What is the sum of the digits of the number 2^1000?

(defun digits->list (n) 
  (map 'list #'digit-char-p (prin1-to-string n)))

(reduce #'+ (digits->list (expt 2 1000)))
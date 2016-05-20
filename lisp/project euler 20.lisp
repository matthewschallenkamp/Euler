(defun factorial (n)
  (reduce #'* (loop for i from n downto 1 collect i)))

(defun digits->list (n) 
  (map 'list #'digit-char-p (prin1-to-string n)))

(reduce #'+ (digits->list (factorial 100)))

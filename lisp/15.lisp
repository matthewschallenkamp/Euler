;How many routes are there through a 20�20 grid?
;never move back, only down or right

(defvar *found-grids* '((1 1 2) (1 0 1) (0 0 1)))
;stores as (x y moves)

(defun find-grid (x y)
  (let ((grids *found-grids*))
    (loop
      (if (= 0 (length grids))
          (return nil)
          (block both
            (if (or (and (= x (caar grids)) (= y (second (car grids))))
                    (and (= x (second (car grids))) (= y (caar grids))))
                (return (third (car grids))))
            (setf grids (cdr grids)))))))

(defun find-paths (x y)
  (if (or (= 0 x) (= 0 y)) 
      1
      (progn
	(let ((found (find-grid x y)))
	  (if found
              found
	      (push (list x y 
                          (+ (find-paths (- x 1) y) 
                             (find-paths x (- y 1))))
                    *found-grids*))
	  (find-grid x y)))))

(find-paths 20 20)

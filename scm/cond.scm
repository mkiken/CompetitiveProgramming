(define (doIt)
  (let ((m (read))) ;; not let!
	(cond
	  ((< m 100) "00")
	  ((and (>= m 100) (<= m 5000))
	   (let ((mm (/ m 100)))
		 (if (< mm 10)
			 (string-append "0" (number->string mm))
			 (number->string mm)
			 )
		 )
	   )
	  ((and (>= m 6000) (<= m 30000)) (number->string (+ (/ m 1000) 50)))
	  ((and (>= m 35000) (<= m 70000)) (number->string (+ (/ (- (/ m 1000) 30) 5) 80)))
	  ((>= 70000) "89")

	  (else "otherwise")
	  )
	)
  )

(display (doIt))
(newline)

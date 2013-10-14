(define (doIt)
  (let* ((h1 (read)) (h2 (read))) ;; not let!
	(begin
	  ;; (display h1)
	  ;; (newline)
	  ;; (display h2)
	  ;; (newline)
	  (display (- h1 h2))
	  (newline)
	  )
	)
  )

(doIt)

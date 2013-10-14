
;; 四捨五入
;;http://tips.lisp-users.org/common-lisp/index.cgi?%E5%9B%9B%E6%8D%A8%E4%BA%94%E5%85%A5%E3%81%99%E3%82%8B
(define (roundoff number)
  (floor (+ 0.5 number)))

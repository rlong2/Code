;;;; This program prints a Hello message to a user

(defun hello-you (*name*)
    (format t "Hello ~a!~%" *name*))
    
(hello-you "Splunk")

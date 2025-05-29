(ns hamming)

(defn distance [xs ys]
  (when (= (count xs) (count ys))
    (->> (map = xs ys)
         (filter false?)
         (count))))

(ns armstrong-numbers)

(defn- digits-reversed [x]
  (->> x
       (iterate #(quot % 10))
       (take-while #(> % 0))
       (map #(rem % 10))))

(defn- pow [base x]
  (->> (repeat x base)
       (apply *)))

(defn armstrong? [x]
  (let [ds (digits-reversed x)]
    (->> ds
         (map #(pow % (count ds)))
         (apply +)
         (= x))))

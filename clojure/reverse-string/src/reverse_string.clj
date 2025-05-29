(ns reverse-string)

(defn reverse-string [xs] (apply str (into '() xs)))

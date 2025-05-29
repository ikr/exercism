(ns bob
  (:require [clojure.string :as str]))

(defn- question? [x] (str/ends-with? x "?"))
(defn- all-caps? [x] (and (not (re-find #"[a-z]" x)) (re-find #"[A-Z]" x)))

(defn response-for
  [x]
  (let [trimmed (str/trim x)]
    (cond
      (empty? trimmed) "Fine. Be that way!"
      (and (question? trimmed) (all-caps? trimmed))  "Calm down, I know what I'm doing!"
      (all-caps? trimmed) "Whoa, chill out!"
      (question? trimmed) "Sure."
      :else "Whatever.")))

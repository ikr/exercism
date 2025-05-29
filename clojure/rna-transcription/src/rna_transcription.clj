(ns rna-transcription)

(defn- rna-nuc [dna-nuc]
  (get
   {\G \C, \C \G, \T \A, \A \U}
   dna-nuc))

(defn to-rna [dna]
  (let [rna-seq (map rna-nuc dna)
        indexed-error-values (->> rna-seq
                                  (map-indexed (fn [i x] {:index i, :value x}))
                                  (remove :value)
                                  (map :index)
                                  (map (fn [i] {:index i, :value (get i dna)})))]
    (assert
     (empty? indexed-error-values)
     (str "Unknown DNA nucleotides " (str indexed-error-values) " in " dna))
    (apply str rna-seq)))

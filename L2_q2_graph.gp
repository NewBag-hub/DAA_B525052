set title "Order of Growth"
set xlabel "n"
set ylabel "Growth"
set grid

plot x*log(x)/log(2) title "merge sort(O(n log₂ n))" with lines, \
     x*log(x)/log(3) title "modified merge sort(O(n log₃ n))" with lines
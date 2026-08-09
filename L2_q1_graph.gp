set title "Order of Growth"
set xlabel "n"
set ylabel "Growth"
set grid

plot x title "Unsorted Array(O(n))" with lines, \
     x title "Sorted Array(O(n))" with lines, \
     x title "Singly Linked Sorted(O(n))" with lines, \
     x title "Singly Linked Unsorted(O(n))" with lines, \
     x title "Doubly Linked Unsorted(O(n))" with lines, \
     x title "Doubly Linked Sorted(O(n))" with lines
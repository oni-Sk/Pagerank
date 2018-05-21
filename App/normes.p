set term png

set xlabel "itérations"
set ylabel "ln ( norme )"

set xrange [0:80]
set yrange [-12:0]

set title "wb-cs-stanford"
set output "../Docs/texRapport/plot-wb-cs-stanford.png"
plot "graphes/puissances-wb-cs-stanford.txt" using 1:2 title "puissances" with lines
#si aitken implénter ajouter à la ligne dessus => ", "graphes/aitken-wb-cs-stanford.txt" using 1:2 title "puissances" with lines"

set title "Stanford"
set output "../Docs/texRapport/plot-Stanford.png"
plot "graphes/puissances-Stanford.txt" using 1:2 title "puissances" with lines

set title "Stanford-Berkeley"
set output "../Docs/texRapport/plot-Stanford-Berkeley.png"
plot "graphes/puissances-Stanford_BerkeleyV2.txt" using 1:2 title "puissances" with lines

set title "in-2004"
set output "../Docs/texRapport/plot-in-2004.png"
plot "graphes/puissances-in-2004v2.txt" using 1:2 title "puissances" with lines

set title "wikipedia"
set output "../Docs/texRapport/plot-wikipedia.png"
plot "graphes/puissances-wikipedia-20051105V2.txt" using 1:2 title "puissances" with lines

set title "wb-edu"
set output "../Docs/texRapport/plot-wb-edu.png"
plot "graphes/puissances-wb-edu.txt" using 1:2 title "puissances" with lines
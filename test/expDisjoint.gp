set terminal png
set output 'expDisjoint.png'
set title 'Expérience Disjoint'
set xlabel 'n'
set ylabel 'nb_arêtes_tirées'

# Définir les plages des axes
set xrange [0:1000]  # Plage de x de 0 à 4000
set yrange [0:10000] # Plage de y de 0 à 4000

plot 'expDisjoint.txt' using 1:2 with lines title 'expDisjoint', \
     'expDisjoint.txt'using 1:3 with lines title "xlog(x)"
set output
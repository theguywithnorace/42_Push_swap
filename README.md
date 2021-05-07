# 42_Push_swap

Check memory leaks
if <5 mid = first value ?

ARG=`ruby -e "puts (-400..400).to_a.shuffle.join(' ')"` && ./push_swap  $ARG | ./checker $ARG

find_value_to_move
	// printf("value to mov at position : %d to mov low ? %d\n", all->p_tomov, all->is_tomov_low);

find_close_mid_values
	// printf("close mid values : low : %d [%d] hig : %d [%d] min : %d [%d]\n", all->v_low, all->p_low, all->v_hig, all->p_hig, all->min, all->p_min);




-> deux fois meme chiffre
-> 

-> need to free everything

->supprimer la fonction print_elt


Amener le chiffre le plus faible sur le dessus
    -> soit par le bas, s'il est dans la 2e moité
    -> soit par le haut s'il est dans la premiere moitié
        ->petite astuce pour savoir si sur la derniere operation on fait sa ou ra
Qunad il est au dessus on le stocke dans la deuxieme pile
A la fin quand la premiere pile est triée (donc avec tous  les chiffres les plus grands), on ramene la deuxieme pile au dessus



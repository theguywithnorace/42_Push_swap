# 42_Push_swap


Pivot en dernier element -> comme ca on le transfert une fois qu'on a passé tous les autres elements

A faire :
- option moins de trois cases jusqu'au pivot
- toutes les cases qui restent sont supérieures au pivot (pas la peine de les passer derrierre avant de les envoyer)


ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"` && ./push_swap  $ARG | ./checker $ARG




Debugger :
find_value_to_move
	// printf("value to mov at position : %d to mov low ? %d\n", all->p_tomov, all->is_tomov_low);

find_close_mid_values
	// printf("close mid values : low : %d [%d] hig : %d [%d] min : %d [%d]\n", all->v_low, all->p_low, all->v_hig, all->p_hig, all->min, all->p_min);

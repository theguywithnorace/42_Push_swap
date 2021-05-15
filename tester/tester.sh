A=`awk -v min=-100 -v max=100 'BEGIN{srand(); print int(min+rand()*(max-min+1))}'`;
# B=`awk -v min=$A -v max=$(($A+100)) 'BEGIN{srand(); print int(min+rand()*(max-min+1))}'`;
B=$(($A+$1));
ARG=`ruby -e "puts ($A..$B).to_a.shuffle.join(' ')"`;
output=$(../push_swap  $ARG | ../checker $ARG);
echo $output 
echo "min:" $A " max:" $B $ARG
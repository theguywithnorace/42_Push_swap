i=0
while true;do
    ARG=`ruby -e "puts (200..600).to_a.shuffle.join(' ')"`
    output=$(../push_swap  $ARG | ../checker $ARG)
    if [ $output != "OK" ]; then
        echo $ARG
        exit
        else
        echo $i " OK " 
        ((i=i+1))
        fi
        
    done

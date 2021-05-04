i=0
while true;do

    output=$(ARG=`ruby -e "puts (-10..10).to_a.shuffle.join(' ')"` && ./push_swap  $ARG | ./checker $ARG)
    echo $ARG    
    if [ $output != "OK" ]; then
        exit
        else
        echo "OK" $i
        ((i=i+1))
        fi
        
    done

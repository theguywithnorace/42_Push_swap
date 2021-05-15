#!/bin/bash

WORSE="0"
BEST="16777216"
MED="0"
COUNTER="0"
SUM="0"
TOTAL="0"
MAX=$3
trap "echo -e '\rWo\033[?25h\033[3B'; exit" INT

if [[ $# -gt 2 ]]
then
	echo -e "\033[?25l\c"
	while [[ ${COUNTER} -lt $2 ]]
	do
		NUM=$(($1 - 1))
		ARG=`ruby -e "puts (0..$NUM).to_a.shuffle.join(' ')"`
		TMP=`../push_swap -v $ARG | grep -e "-> Ex" | wc -l | bc`
		(( COUNTER += 1 ))
		PERCENT=$((COUNTER * 100 / $2))
		if [[ ${TMP} -gt ${MAX} ]]
		then
			(( TOTAL += 1 ))
		fi
		(( SUM += ${TMP} ))
		(( MED = ${SUM} / ${COUNTER} ))
		if [[ ${TMP} -gt ${WORSE} ]]
		then
			WORSE=${TMP}
		fi
		if [[ ${TMP} -lt ${BEST} ]]
		then
			BEST=${TMP}
		fi
		(( TOTAL2 = (( $TOTAL * 100) / ($COUNTER) )))
		echo -e "number of instruction over ${MAX} is = \033[31;1m${TOTAL}\033[0m percent = ${TOTAL2}"
		echo -e "Worst = \033[31;1m${WORSE}\033[0m instructions"
		echo -e "Average = \033[33;1m${MED}\033[0m instructions  "
		echo -e "Best = \033[36;1m${BEST}\033[0m instructions  "
		echo -e "\033[32;1m${PERCENT}\033[0m % done\r\033[4A\c"
	done
	echo -e "\033[?25h\033[3B"
else
	echo "./complexity [stack_size] [test number] [max instruction]"
 fi


#! /bin/bash

for i in *.pdf
do
    echo "i == $i"
    j=`basename -s .pdf $i`
    #echo "j == $j"
    epspdf $i $j.eps
    if test $? -ne 0 
    then 
    	echo "epspdf failed."; 
    	exit 1 
    else 
    	echo "epspdf succeeded." 
    fi 
done

exit 0

k=$j.jpg  
#echo "k == $k"  
echo "Converting $i to $k"  
convert $i $k  
if test $? -ne 0  
then  
	echo "convert failed.";  
	exit 1  
else  
	echo "convert succeeded."  
fi 

#!/bin/sh

make clean
echo "Cleanup complete!"

make 
if [ -f ./output/demo ];then  #注意空格
     echo "make complete!"
else
     echo "make failed!"
fi




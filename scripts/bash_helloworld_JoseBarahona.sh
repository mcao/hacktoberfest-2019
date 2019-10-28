# LANGUAGE: Bash
# AUTHOR: Jose Barahona
# GITHUB: https://github.com/jrab66

#!/bin/bash
HelloWorld(){
    echo "Hello World $NAME"
}

# end functions

#menu
if [ "$1" == "-h" ]; then
    echo "put your name : ./helloworld -n Jose"

elif [  "$1" == "-n" ]; then 
    if [ -z "$2" ]; then
        echo "use -h for help"
    else
        NAME=$2
        HelloWorld
    fi
elif [  "$1" == "" ]; then 
    echo " use help option -h "
fi
#end menu

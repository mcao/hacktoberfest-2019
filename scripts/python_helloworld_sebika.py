# LANGUAGE: Python3
# AUTHOR: Marinescu Sebastian
# GITHUB: https://github.com/sebika

import os
from random import randint

SUPER_SECRET_MESSAGE = "Hello, World!"
SUPER_SECRET_KEY = 69

def validateKey(key):
    if(key == SUPER_SECRET_KEY):
        return True
    return False

def main():
    current_key = 420
    MAX_TRIES = 1000000
    total_tries = 0
    while(validateKey(current_key) is not True):
        total_tries += 1
        if(total_tries > MAX_TRIES):
            print("Couldn't find it :((")
            os._exit(1)
        current_key = randint(1, 100)
    print(SUPER_SECRET_MESSAGE)

if __name__== "__main__":
    main()
    
        
#!/usr/bin/python3
if __name__ == "__main__":
    from hidden_4 import *
    all_fuction = dir ()
    for i in range(0, len(all_fuction)):
        if all_fuction[i][:2] != "__":
            print ("{:s}".format(all_fuction[i]))

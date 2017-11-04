#!/bin/bash

usage(){
    echo "Usage: $0 -n <num_core> -p <process_name>" >&2
    exit 1
}

while getopts "n:p:" option; do
    case $option in
	n)
	    num_core=$OPTARG
#	    echo "number of cores: $OPTARG" >&2
	    ;;
	p)
	    proc_name=$OPTARG
#	    echo "process name: $OPTARG" >&2
	    ;;
	\?)
#	    echo "Error: Invalid option: -$OPTARG" >&2
	    usage;
	    ;;
    esac
done

mpirun -n $num_core ./$proc_name

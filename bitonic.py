#!/usr/bin/python3

def print_list(x):
    for i in range(len(x) - 1):
        print(x[i], end=", ")
    print(x[-1])

def bitonic_sort(up, x):
    if len(x) <= 1:
        return x
    else:
        print("Merging [{}/16] ({}):".format(len(x), "UP" if up else "DOWN"))
        print_list(x)
        first = bitonic_sort(True, x[:len(x) // 2])
        second = bitonic_sort(False, x[len(x) // 2:])
        return bitonic_merge(up, first + second)

def bitonic_merge(up, x): 
    # assume input x is bitonic, and sorted list is returned 
    if len(x) == 1:
        return x
    else:
        swapped = bitonic_compare(up, x)
        first = bitonic_merge(up, x[:len(x) // 2])
        second = bitonic_merge(up, x[len(x) // 2:])
        ret = first + second
        print("RResult [{}/16] ({}):".format(len(ret), "UP" if up else "DOWN"))
        if swapped:
            print_list(ret)
        return ret
        
def bitonic_compare(up, x):
    dist = len(x) // 2
    swapped = False
    for i in range(dist):  
        if (x[i] > x[i + dist]) == up:
            x[i], x[i + dist] = x[i + dist], x[i] #swap
            swapped = True
    return swapped

bitonic_sort(True, [100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13])

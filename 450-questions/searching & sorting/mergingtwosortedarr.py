def merge(arr1, arr2): 
        arr1[:] = sorted(arr1+arr2)
        arr2.clear()
        return arr1

if __name__ =="__main__":
    arr1 = [1,3,5,7]
    arr2 = [0,2,6,8,9]
    arr3 = merge(arr1,arr2)
    print(*arr3)

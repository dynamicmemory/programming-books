def partition(arr: list[int], p: int, r: int) -> int:
    i: int = p - 1
    x: int = arr[r]
    temp: int 

    j: int = p
    while j != r:

        if arr[j] < x:
            i += 1
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp 
        j += 1

    temp = arr[r]
    arr[r] = arr[i+1]
    arr[i+1] = temp 
    return i + 1;


def quicksort(arr: list[int], p: int, r: int) -> None:
    if p < r:
        q = partition(arr, p, r)
        quicksort(arr, p, q-1)
        quicksort(arr, q+1, r)


if __name__ == "__main__":
    list_of_nums: list[int] = [9,3,1,4,0,8,7,5,2,6]
    
    print(list_of_nums)
    quicksort(list_of_nums, 0, 9)
    print(list_of_nums)


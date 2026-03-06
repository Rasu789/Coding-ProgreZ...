if __name__ == '__main__':
    N = int(input())
    my_list = []
    
    for _ in range(N):
        command, *args = input().split()
        
        args = list(map(int, args))
        
        if command == "print":
            print(my_list)
        else:
            getattr(my_list, command)(*args)

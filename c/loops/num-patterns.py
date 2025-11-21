stepper = int(input("Enter No: "))
for i in range(1,stepper+1):
    if i%2!=0:
        #For Odd
        start=1
        end=5
        while(start<=end):
            if start==1 or start==end :
                print(f"{' '*start}{'* '*5}")
            else:
                if start==3:
                    print(f"{' '*start}*   {i}   *")
                else:
                    print(f"{' '*start}*       *")
            start+=1
        if i!=stepper:
            print(f"{' '*(start-1)}{'= '*5}")
    else:
        #For Even
        start=5
        end=1
        while(start>=end):
            if start==1 or start==5:
                print(f"{' '*start}{'* '*5}")
            else:
                if start==3:
                    print(f"{' '*start}*   {i}   *")
                else:
                    print(f"{' '*start}*       *")
            start-=1
        if i!=stepper:
            print(f"{' '*(start+1)}{'= '*5}")
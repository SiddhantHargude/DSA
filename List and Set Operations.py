lst1=input("Enter elements(with space): ")
lst1=lst1.split(" ")
print(lst1)

def insert(lst):
    ele=input("Enter element to be inserted: ")
    lst.append(ele)
    return lst


def delete(lst):
    ele=input("Enter element to be deleted: ")
    if ele in lst:
        lst.remove(ele)
    else:
        print("Element not found !")    
    return lst    



def present(lst):
    ele=input("Enter element to check: ")
    if ele in lst:
        print("TRUE")
    else:
        print("FALSE")
    return 0        



def size(lst):
    print("Number of elements in list:",len(lst))
    return 0


def inter(lst,lst0):
    a=[]
    for i in lst:
        if i in lst0:
            a.append(i)
    return a

def dup(lst):
    newlst=[]
    for i in lst:
        if i not in newlst:
            newlst.append(i)
    return newlst        

def union(lst,lst0):
    a=[]
    for i in lst:
        a.append(i)
    for j in lst0:
        a.append(j)
    a=dup(a)    
    return a


def diff(lst,lst0):
    a=[]
    for i in lst:
        if i not in lst0:
            a.append(i)
    return a

def subset(lst,lst0):
    s=0
    for i in lst0:
        if i in lst:
            s=1
        else:
            s=0
    if s==1:
        print("set 2 is subset of set 1")
    else:
        print("set 2 is not subset of set 1")            
    return 0

flag=1
while flag==1:
    print("""
    1.Insert
    2.Delete
    3.Presence
    4.Number of elements
    5.Set Operations
    6.Exit      
    """)
    uip=int(input("Enter Choice: "))
    if uip==1:
        print(insert(lst1))
    elif uip==2:
        print(delete(lst1))
    elif uip==3:
        present(lst1)
    elif uip==4:
        size(lst1)
    elif uip==5:
        tp=1
        lst2=input("Enter elements for set1 (with space): ")
        lst2=lst2.split(" ")
        print(lst2)
        lst3=input("Enter elements for set2 (with space): ")
        lst3=lst3.split(" ")
        print(lst3)
        while tp==1:
            print("""
            1.Intersection
            2.Union
            3.Difference
            4.Subset
            5.Exit
            """)
            usip=int(input("Enter Choice: "))
            if usip==1:
                print(inter(lst2,lst3))
            elif usip==2:
                print(union(lst2,lst3))
            elif usip==3:
                print(diff(lst2,lst3))
            elif usip==4:
                subset(lst2,lst3)
            elif usip==5:
                tp=0
                break
            else:
                print("Enter valid choice !")
    elif uip==6:
        flag=0
        break
    else:
        print("Enter valid choice !")                  

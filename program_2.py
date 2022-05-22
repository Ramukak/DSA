s1 = []
s2 = []
how_many_set1 = int(input("how many elements in set 1:"))
for i in range(how_many_set1):
    ele = int(input("Enter the element"))
    if ele in s1:
        print("element is already present")
    else:
        s1.append(ele)
        print("element addded")


how_many_set2 = int(input("how many elements in set 2:"))
for i in range(how_many_set2):
    ele = int(input("Enter the element"))
    if ele in s2:
        print("element is already present")
    else:
        s2.append(ele)
        print("element addded")


def add_element(set_list):
    ele = int(input("Enter element to add : "))
    if ele in set_list:
        print("element is already present")
    else:
        set_list.append(ele)
        print("element addded")


def intersection():
    l = []
    for i in s1:
        if i in s2:
            l.append(i)
    print(l)


def uninon():
    l = []
    for i in s2:
        l.append(i)
    for i in s1:
        if i not in l:
            l.append(i)
    print(l)


def differance_of_list():
    l = []
    for i in s1:
        if i not in s2:
            l.append(i)
    print(l)


def subset(list1, list2):
    for i in list1:
        if i not in list2:
            print("not a subset")
            break
    else:
        print("it is subset")


print("element in s1 are", s1)
print("element in s2 are", s2)
print("adding element in s1")
add_element(s1)
add_element(s1)
print("adding element in s2")
add_element(s2)
add_element(s2)
print(s1, s2)
print("intersection is : ")
intersection()
print("uninon is : ")
intersection()
print("Differance of list is : ")
differance_of_list()
print("is s1 subset of s2  : ")
subset(s1, s2)
print("is s2 subset of s1  : ")
subset(s2, s1)

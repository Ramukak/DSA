size = int(input("Enter the number of clients "))
client_list = [None] * size


def add_client():
    client_id = int(input("client id"))
    name = input("client name")
    telephone = input("client telephone")
    client_details = [client_id, name, telephone]

    index = client_id % size
    # Inserting record using linear
    # probing in case of collision
    for i in range(size):
        if client_list[index] == None:
            client_list[index] = client_details
            print("adding data", index, i, client_details)
            break
        else:
            index = (index + 1) % size


def search_client():
    client_id = int(input("client id"))
    index = client_id % size
    for i in range(size):
        if client_list[index] != None:
            if client_list[index][0] == client_id:
                print("client isa found at index ", index, client_list[index])
                break
        else:
            index = (index + 1) % size
    else:
        print("element is not found")


def delete_client():
    client_id = int(input("client id"))
    index = client_id % size
    for i in range(size):
        if client_list[index] != None:
            if client_list[index][0] == client_id:
                client_list[index] = None
                print("cliet delted")
                break
        else:
            index = (index + 1) % size
    else:
        print("element is not found")

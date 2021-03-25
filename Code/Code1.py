'''
Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
testare la funzione dequeue per svuotare la coda.
'''
def dequeue(queue):
    return queue.pop(0)

def enqueue(queue, element):
    queue.append(element)

def main():
    coda=[]

    num=int(input("Inserire un numero: "))
    enqueue(coda,num)
    while input("Vuoi continuare (Inserire n per terminare l'input): ")!='n':
        num=int(input("Inserire un numero: "))
        enqueue(coda,num)
    
    for _ in range(len(coda)):
        print(dequeue(coda))
        
if __name__ =="__main__":
    main()
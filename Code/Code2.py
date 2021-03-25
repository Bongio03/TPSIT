'''
Scrivere una funzione che inverta una coda, ovvero produca una coda invertendo l’ordine
degli elementi della coda di partenza. Suggerimento: utilizzare una pila.
'''
def enqueue(queue, element):
    queue.append(element)


def dequeue(queue):
    return queue.pop(0)


def push(stack, element):
    stack.append(element)


def pop(stack):
    return stack.pop()

def main():
    coda=[]
    pilaTemp=[]

    num=int(input("Inserire un numero: "))
    enqueue(coda,num)
    while input("Vuoi continuare (Inserire n per terminare l'input): ")!='n':
        num=int(input("Inserire un numero: "))
        enqueue(coda,num)
    
    for _ in range(len(coda)):
        push(pilaTemp,dequeue(coda))
    
    for _ in range(len(pilaTemp)):
        enqueue(coda,pop(pilaTemp))
    
    for element in coda:
        print(element)


if __name__=="__main__":
    main()

    

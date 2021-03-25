'''
Implementare le pile e i metodi pop() e push() utilizzando una coda con i suoi metodi
enqueue() and dequeue()
'''

def enqueue(queue, element):
    queue.append(element)


def dequeue(queue):
    return queue.pop(0)


def push(coda, element):
    codaTemp= []
    for _ in range(len(coda)):
        enqueue(codaTemp, dequeue(coda))
    enqueue(coda, element)
    for element in codaTemp:
        enqueue(coda, element)

def pop(coda):
    return dequeue(coda)


def main():
    coda = []
    print("Inserire 5 numeri")
    for k in range(1,6):
        num=int(input(f"{k}. Inserire: "))
        push(coda,num)
    print(coda)
    pop(coda)
    print(coda)

if __name__ == '__main__':
    main()
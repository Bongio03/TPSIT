'''
Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
testare la funzione dequeue per svuotare la coda.
'''
def dequeue(queue):                     #Funzione per svuotare la coda
    return queue.pop(0)

def enqueue(queue, element):            #Funzione per caricare la coda
    queue.append(element)

def main():
    coda=[]                             #In python la coda  è semplicemente una lista

    num=int(input("Inserire un numero: "))          #Input del primo elemento. In seguito, in base alle scelte dell'utente, verrano aggiunti altri elementi o meno
    enqueue(coda,num)                               #Viene inserito l'elemento nella coda
    while input("Vuoi continuare (Inserire n per terminare l'input): ")!='n':
        num=int(input("Inserire un numero: "))
        enqueue(coda,num)                     
    
    for _ in range(len(coda)):          #Ciclo for utilizzato per stamapre tutti gli eleemnti che vengono tolti dalla lista coda
        print(dequeue(coda))
        
if __name__ =="__main__":
    main()

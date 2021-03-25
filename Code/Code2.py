'''
Scrivere una funzione che inverta una coda, ovvero produca una coda invertendo l’ordine
degli elementi della coda di partenza. Suggerimento: utilizzare una pila.
'''
def enqueue(queue, element):                    #Funzione per caricare la coda
    queue.append(element)


def dequeue(queue):                             #Funzione per svuotare la coda
    return queue.pop(0)


def push(stack, element):                       #Funzione per il caricamento delle pile 
    stack.append(element)


def pop(stack):                                 #Funzione per togliere elementi dalle pile 
    return stack.pop()

def main():
    coda=[]                                     #coda che viene caricata dall'utente
    pilaTemp=[]                                 #pila d'appoggio per l'inversione 

    num=int(input("Inserire un numero: "))      #Inseriemnto degli input 
    enqueue(coda,num)
    while input("Vuoi continuare (Inserire n per terminare l'input): ")!='n':
        num=int(input("Inserire un numero: "))
        enqueue(coda,num)
    
    for _ in range(len(coda)):                  #La coda viene svuotata e la pila viene riempita
        push(pilaTemp,dequeue(coda))
    
    for _ in range(len(pilaTemp)):              #La pila viene svuota e la coda viene riempita, ma con l'ordine inverso 
        enqueue(coda,pop(pilaTemp))
    
    for element in coda:                        #Stampa di tutti gli elementi inseriti nella coda
        print(element)


if __name__=="__main__":
    main()

    

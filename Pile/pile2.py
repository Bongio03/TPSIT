def push_(stack, element):
    stack.append(element)

def pop_(stack):
    return stack.pop()

def is_open(element):
    if element== '(' or element== '[' or element == '{' : 
        return 1
    else:
        return 0

def is_close(element):
    if element == ')' or element== ']' or element== '}':
        return 1
    else:
        return 0

def main():
    errore=0
    pila=[]
    n_open=0
    n_close=0
    espressione=input("Inserire un espressione matematica: ")
    for elemento in espressione:
        if is_open(elemento)==1:
            push_(pila,elemento)
            n_open+=1
        if is_close(elemento)==1:
            n_close+=1
            if elemento==")":
                ultimo=pop_(pila)
                if ultimo!='(':
                    errore=1
                    break
            elif elemento=="]":
                ultimo=pop_(pila)
                if ultimo!='[':
                    errore=1
                    break
            elif elemento=="}":
                ultimo=pop_(pila)
                if ultimo!='{':
                    errore=1
                    break
    if(n_open!=n_close):
        errore==1
    if(errore==1):
        print("L'esspressione inserita ha degli errori")
    else:
        print("L'espressione inserita è corretta")        
    
if __name__ == "__main__":
    main()
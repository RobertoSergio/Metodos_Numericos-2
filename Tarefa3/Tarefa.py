import math

def f(x):
    return pow((math.sin(2 * x) + 4 * pow(x,2) + 3 * x), 2)
    
def Abordagem_fechada(xi, xf):
    h = (xf-xi)/3
    res= (3*h/8)*(f(xi)+3*f(xi+h)+3*f(xi+2*h)+f(xi+3*h))
    return res

def Abordagem_aberta(xi, xf):
    h = (xf-xi)/6
    return ((h)/10)*(33*f(xi)-42*f(xi+h)+78*f(xi+2*h)-42*f(xi+3*h)+33*f(xi+4*h))

def integracao(xi,xf,epsilon,metodo):
    delta = 0
    Erro = 0
    Res = 0
    ResAnt = 0
    N=2
    integ = True
    interacao = 0
    while integ:
        interacao += 1  
        delta =(xf-xi)/N
        res_int = 0
        for i in range(N):
            Xi = xi +i*delta
            Xf = xi + delta
            if(metodo == 1):
                res_int += Abordagem_aberta(Xi, Xf)
            if(metodo == 2):
                res_int += Abordagem_fechada(Xi, Xf)
        print("---------------------------------------------")
        print(f"          Interação: {interacao}")
        print(f"          Resultado: {res_int}")
        print("---------------------------------------------")
        N*=2
        ResAnt = Res
        Res = res_int
        Erro = abs(Res - ResAnt)
        if(Erro < epsilon):
            integ = False
        if(interacao>=5):
            integ = False
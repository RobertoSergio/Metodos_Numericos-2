from Tarefa import integracao

print("---------------------------------------------")
print("-------------------Tarefa 3------------------")
print("---------------------------------------------\n")
print("A funcao usada sera: (sen(2x) + 4*(x)^2 + 3x)^2\n")

programa = True
while programa:
    xi = int(input("Escreva o valor de xi:"))
    xf = int(input("Escreva o valor de xf:"))
    epilson = float(input("Escreva o valor do erro:"))
    print("Escolha a abordagem desejada: ")
    print("1: Abordagem Aberta ")
    print("2: Abordagem Fechada ")
    escolha = int(input("Digite o número da abordagem que você quer: "))
    if escolha == 1:
        print("Você escolheu a Abordagem Aberta")
        integracao(xi, xf, epilson, escolha)
    if escolha == 2:
        print("Você escolheu a Abordagem Fechada")
        integracao(xi, xf, epilson, escolha)
    print("\n---------------------------------------------")
    print("1-Rodar o programa novamente ")
    print("2-Sair do programa")
    print("---------------------------------------------")
    novamente = int(input("Digite a sua escolha?"))
    if novamente == 1:
        programa=True
    if novamente == 2:
        programa=False
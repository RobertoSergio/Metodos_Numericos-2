from algoritmos import metodo_de_householder, metodo_da_potencia_regular
import numpy as np


if __name__ == "__main__":
    A = np.array(
        [
            [40, 8, 4, 2, 1],
            [8, 30, 12, 6, 2],
            [4, 12, 20, 1, 2],
            [2, 6, 1, 25, 4],
            [1, 2, 2, 4, 5],
        ]
    )

    A_tridiag, H_acumulada = metodo_de_householder(A)

    # Item 1
    print("1)")
    print("Matriz Tridiagonal A':")
    print(A_tridiag)
    print("\nMatriz Acumulada H:")
    print(H_acumulada)
    print("\n-------------------------------------\n")

    # Item 3 - Método da Potência Regular
    v0 = np.ones(A_tridiag.shape[0])  # Vetor inicial (chute)
    eps = 1e-9  #
    max_iter = 1000

    lambda_dominante, autovetor_dominante = metodo_da_potencia_regular(
        A_tridiag, v0, eps, max_iter
    )

    print("3)")
    print("Autovalor dominante (lambda):", lambda_dominante)
    print("Autovetor correspondente (v):", autovetor_dominante)
    print("\n-------------------------------------\n")

    # Item 4 - Encontrar os autovetores da matriz A usando H e autovetores de A'
    # Fórmula: x_i = H * v_i
    autovetores_A = np.dot(H_acumulada, autovetor_dominante.reshape(-1, 1))

    print("4)")
    print("Autovetores da matriz A:")
    print(autovetores_A)
    print("\n-------------------------------------\n")

    # Item 5 - Encontrar todos os autovalores da matriz A
    autovalores_A = np.linalg.eigvals(A)

    print("5)")
    print("Autovalores da matriz A:")
    print(autovalores_A)
    print("\n-------------------------------------\n")

    print("\nATIVIDADE - AULA 22")

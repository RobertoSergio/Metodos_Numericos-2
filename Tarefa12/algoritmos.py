import numpy as np


def metodo_de_householder(A):
    """
    Aplica o método de Householder para transformar a matriz A em uma matriz tridiagonal.

    Parâmetros:
    A : np.array
        Matriz simétrica a ser transformada.

    Retorna:
    A_tridiag : np.array
        Matriz tridiagonal resultante.
    H_acumulada : np.array
        Matriz acumulada das transformações de Householder.
    """
    n = A.shape[0]
    H_acumulada = np.eye(n)  # Inicia a matriz acumulada como identidade
    A_tridiag = A.copy()  # Cria uma cópia da matriz A para ser modificada

    for i in range(n - 2):
        # Inicializar vetores
        w = np.zeros(n)  # Vetor nulo com n elementos
        w_linha = np.zeros(n)  # Vetor nulo com n elementos

        # Copiar os elementos abaixo da diagonal da coluna i da matriz A_tridiag
        # para as respectivas posições no vetor w, isto é, da posição i+1 até o final
        w[i + 1 : n] = A_tridiag[i + 1 : n, i]

        # Calcular o comprimento do vetor w
        Lw = np.linalg.norm(w)

        # Copiar Lw na posição i+1 do vetor w'
        w_linha[i + 1] = Lw

        # Calcular o vetor N
        N = w - w_linha

        # Normalizar o vetor N
        n_vec = N / np.linalg.norm(N)

        # Montar a matriz de Householder
        H_i = np.eye(n) - 2 * np.outer(n_vec, n_vec.T)

        # Atualizar a matriz tridiagonal
        A_tridiag = H_i @ A_tridiag @ H_i

        # Acumular as transformações de Householder
        H_acumulada = H_acumulada @ H_i

    return A_tridiag, H_acumulada


def metodo_da_potencia_regular(A, v0, eps=1e-9, max_iter=1000):
    """
    Método da Potência Regular para encontrar o autovalor dominante e o autovetor correspondente.

    Parâmetros:
    A : np.array
        Matriz quadrada para a qual o autovalor dominante será encontrado.
    v0 : np.array
        Vetor inicial (chute inicial).
    eps : float
        Tolerância para a convergência.
    max_iter : int
        Número máximo de iterações.

    Retorna:
    lambda_1 : float
        Autovalor dominante estimado.
    v : np.array
        Autovetor correspondente ao autovalor dominante.
    """
    v = v0
    lambda_antigo = 0.0

    for _ in range(max_iter):
        # Passo 4: Copiar lambda antigo para o novo
        lambda_novo = lambda_antigo

        # Passo 5: Copiar v antigo para v novo (antes de normalizar)
        v_velho = v

        # Passo 6: Normalizar o vetor v_velho
        x1_velho = v_velho / np.linalg.norm(v_velho)

        # Passo 7: Calcular o vetor não normalizado v_novo = A * x1_velho
        v_novo = np.dot(A, x1_velho)

        # Passo 8: Calcular a nova estimativa de lambda
        lambda_novo = np.dot(x1_velho.T, v_novo)

        # Verificar a convergência
        if np.abs((lambda_novo - lambda_antigo) / lambda_novo) < eps:
            break

        # Preparar para a próxima iteração
        lambda_antigo = lambda_novo
        v = v_novo

    return lambda_novo, x1_velho

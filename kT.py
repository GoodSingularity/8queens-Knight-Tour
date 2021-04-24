#Sprawdz czy kordynaty sa wewnatrz szachownicy
def isSafe(x, y):
    return not (x < 0 or y < 0 or x >= N or y >= N)
def solution(pos, board, x, y):
    if pos >= N * N:
        for r in board:
            print(r)
        print()
        # backtrack przed zwroceniem
        board[x][y] = 0
        return
#Rekurencyjna funkcja wykonujaca knight's tour uzywajac backtracking
def Recursion(board, x, y, pos):
    #Oznacz aktualnie odwiedzane pole
    board[x][y] = pos
     # Jezeli wszystkie pola zostaly odwiedzone, wypisz rozwiazanie
    solution(pos, board, x, y)

    #Wszystkie mozliwe ruchy rycerza
    movesRow = [2, 1, -1, -2, -2, -1, 1, 2, 2]
    movesCol = [1, 2, 2, 1, -1, -2, -2, -1, 1]
    for l in range(8):
        #Nowa pozycja na szachownicy
        newX, newY = x + movesRow[l], y + movesCol[l]

        # jezeli mozna wrzucic na nowa pozycje, bo spelnia warunek ze jest na tablicy i nie jest jeszcze odwiedzona
        if isSafe(newX, newY):
            if board[newX][newY] == 0:
                #Rekurencja nowych pozycji
                Recursion(board, newX, newY, pos + 1)

    # Jezeli nie spelnia warunku, cofnij
    board[x][y] = 0


if __name__ == '__main__':

    N = 8
    #Szachownica 8x8. Zapisuje porzadek w jakim pola sa odwiedzane.
    board = [[0 for x in range(N)] for y in range(N)]
    pos = 1
    #Zacznij w rogu (0, 0)
    Recursion(board, 0, 0, pos)

def CheckIfPalindrome(cadena):
    lista = []
    lista2 = []

    for i in cadena:
        lista.append(i)
        lista2.append(i)

    lista2.reverse()
    print(lista)
    print(lista2)
    if (lista != lista2):
        print("No es palindromo")

    print("Es palindromo")


CheckIfPalindrome(input("Introduzca una cadena: "))


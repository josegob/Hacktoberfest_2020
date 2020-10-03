def funcion_vocales(palabra):
	contador = 0
	vocales = ['a','e','i','o','u']
	for i in palabra:
		if i in vocales:
			contador+=1

	print("La palabra introducida tiene " + str(contador) + " vocales")


funcion_vocales("ornitorrinco")

# recebe o valor a ser retirado e o armazena em "valor"
valor = int(input("insira o valor a ser retirado: "))

# ========================= calcula quantas notas de cada tipo são necessárias =========================

#lida com notas de 100
quantidade_cem = valor // 100 # determina quantas notas de 100 serão entregues sem ultrapassar o valor.
valor = valor % 100 # muda "valor" para um novo valor descontando as notas de 100 que serão entregues

#lógica análoga para os demais valores
quantidade_cinquenta = valor // 50
valor = valor % 50

quantidade_vinte = valor // 20
valor = valor % 20

quantidade_dez = valor // 10
valor = valor % 10

quantidade_cinco = valor // 5
valor = valor % 5

quantidade_dois = valor // 2
valor = valor % 2

#lida com moedas de 1
quantidade_um = valor # após a entrega das notas de 2, todo o valor restante será entregue em moedas de 1

# imprime os valores com suas respectivas mensagens
print(quantidade_cem, "nota(s) de 100\n", quantidade_cinquenta, "nota(s) de 50\n", quantidade_vinte, "nota(s) de 20\n", quantidade_dez, "nota(s) de 10\n", quantidade_cinco, "nota(s) de 5\n", quantidade_dois, "nota(s) de 2\n", quantidade_um, "moeda(s) de 1")

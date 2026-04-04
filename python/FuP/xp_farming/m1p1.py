# recebe o valor a ser retirado e o armazena em "valor"
valor = int(input("insira o valor a ser retirado: "))

# calcula quantas notas de cada tipo são necessárias

#lida com notas de 100
quantidade_cem = valor // 100 # determina quantas notas de 100 serão entregues sem ultrapassar o valor.
valor = valor % 100 # muda "valor" para um novo valor descontando as notas de 100 que serão entregues

#lida com notas de 50
quantidade_cinquenta = valor // 50 # determina quantas notas de 50 serão entregues sem ultrapassar o novo valor.
valor = valor % 50 # muda "valor" para um novo valor descontando as notas de 50 que serão entregues

#lida com notas de 20
quantidade_vinte = valor // 20 # determina quantas notas de 20 serão entregues sem ultrapassar o novo valor.
valor = valor % 20 # muda "valor" para um novo valor descontando as notas de 20 que serão entregues

#lida com notas de 10
quantidade_dez = valor // 10 # determina quantas notas de 10 serão entregues sem ultrapassar o novo valor.
valor = valor % 10 # muda "valor" para um novo valor descontando as notas de 10 que serão entregues

#lida com notas de 5
quantidade_cinco = valor // 5 # determina quantas notas de 5 serão entregues sem ultrapassar o novo valor.
valor = valor % 5 # muda "valor" para um novo valor descontando as notas de 5 que serão entregues

#lida com notas de 2
quantidade_dois = valor // 2 # determina quantas notas de 2 serão entregues sem ultrapassar o novo valor.
valor = valor % 2 # muda "valor" para um novo valor descontando as notas de 2 que serão entregues

#lida com moedas de 1
quantidade_um = valor # após a entrega das notas de 2, todo o valor restante será entregue em moedas de 1

# imprime os valores com suas respectivas mensagens
print(quantidade_cem, "nota(s) de 100\n", quantidade_cinquenta, "nota(s) de 50\n", quantidade_vinte, "nota(s) de 20\n", quantidade_dez, "nota(s) de 10\n", quantidade_cinco, "nota(s) de 5\n", quantidade_dois, "nota(s) de 2\n", quantidade_um, "moeda(s) de 1")

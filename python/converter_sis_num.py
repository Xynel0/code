# Converte partindo de um decimal
def decimal_input(d):
    # define 'b', 'h' e 'o' como strings vazias    
    b = ""
    h = ""
    o = ""
    h_digitos = "0123456789ABCDEF" # armazena em uma string os dígitos usados em hexadecimal.
   
    # define que se o decimal inserido for 0, qualquer conversão será 0
    if d == 0:
        b = "0"
        h = "0"
        o = "0"
        
    # caso o valor seja maior que 0, executa a conversão para as demais bases
    else:
        #define uma variável para cada loop de conversão cujo valor é o decimal inserido.
        db = d
        dh = d
        do = d
       
        # loop de conversão para binário.
        while db > 0: 
            b = str(db % 2) + b # coloca o valor do resto de cada divisão no início da string b
            db = db // 2 # atualiza o valor da variável db para que a próxima divisão não seja feita com db original
        
        # loop de conversão para hexadecimal
        while dh > 0:
            h = h_digitos[dh % 16] + h
            dh = dh // 16
        
        # loop de conversão para octal
        while do > 0:
            o = str(do % 8) + o 
            do = do // 8
    return(b, o, h) # retorna os três valores


# converte a partir de um binário
def binary_input(b):
    d = 0 #define o valor decimal como 0
    for i in range(len(b)):
        digito_de_interesse = int(b[len(b) - 1 - i]) # conta o dígito de trás para frente
        d = d + digito_de_interesse * (2 ** i) # aplicamos a fórmula e obtemos o valor decimal
    _, o, h = decimal_input(d) #define 3 variáveis, descartando a primeira, cujos valores são dados pela função decimal_input a partir da entrada do binário recém convertido em decimal.
    print("decimal: ",d, "\noctal: ", o, "\nhexadecimal: ", h) #imprime o valor decimal obtido pela função binary_input junto com os valores octal e hexadecimal obtidos pela função decimal_input

# converte a partir de um octal
def octal_input(o):
    d = 0
    for i in range(len(o)):
        digito_de_interesse = int(o[len(o) - 1 - i])
        d = d + digito_de_interesse * (8 ** i)
    b, _, h = decimal_input(d)
    print("decimal: ",d, "\nbinário ", b, "\nhexadecimal: ", h)

# converte a partir de um hexadecimal
def hexadecimal_input(h):
    h_digitos = "0123456789ABCDEF"
    d = 0
    for i in range(len(h)):
        digito_de_interesse = (h[len(h) - 1 - i]) # como hexadecimal aceita A-F, o dígito de interesse coleta apenas uma string do dígito especificado
        vh = h_digitos.index(digito_de_interesse) # aqui é convertida a string para seu valor numérico (A-F = 10-15)
        d = d + vh * (16 ** i)
    b, o, _ = decimal_input(d)
    print("decimal: ",d, "\noctal: ", o, "\nbinário: ", b)

# muda o valor da variável após cada loop para decidir se continua ou não.
def continuar():
    while True:
        cont = str(input("Deseja converter mais algum número?(S/N)\n")).strip().capitalize()
        if cont == "S":
            cont = 1
            return(cont)
        elif cont == "N":
            cont = 0
            return(cont)
        else:
            print("Por favor, digite 's' ou 'n'.")

# inicia o programa
print("Olá, bem vindo ao conversor de números!")
cont = 1 # define continuar como 1
while cont == 1: # enquanto cont permanecer como 1, o programa se mantém em execução

    # define o tipo de conversão a ser feito e chama a função correta
    tipo = str(input("a partir de qual sistema será feita a conversão?\nDigite 2 ou b para binário, 8 ou o para octal,\n16 ou h para hexadecimal e 10 ou d para decimal:\n")).lower().lstrip()
    if tipo == "d" or tipo == "10":
            
        # lida com conversões partindo da base decimal
        while True:
            try: # valida se o input é um inteiro
                d = int(input("digite o valor: "))
                if d >= 0: # filtra valores negativos.
                    b, o, h = decimal_input(d) # chama a função para entradas decimais
                    print("binário: ",b, "\noctal: ", o, "\nhexadecimal: ", h)
                    break # encerra o while True mais próximo acima
                else:
                    print("conversão de valores menores que 0 indisponível")
            except ValueError: # lida com entradas que não sejam inteiros
                print("Por favor, digite um número natural.")
        cont = continuar() # chama a função que pode mudar o valor de 'cont' para decidir se o programa será ou não executado novamente

    elif tipo == "b" or tipo == "2":  
        # lida com conversões partindo da base binária
        while True:
            try: # valida se o input é um inteiro
                b = int(input("digite o valor: "))
                if b >= 0 and all(c in "01" for c in str(b)): # valida se o input só contém 0s e 1s 
                    resultado = binary_input(str(b)) # chama a função para entradas binárias
                    break
                elif b >= 0:
                    print("por favor, digite um número binário.")
                else:
                    print("conversão de valores menores que 0 indisponível")
            except ValueError:
                print("Por favor, digite um número binário.")
        cont = continuar()

    elif tipo == "o" or tipo == "8":
        # lida com conversões partindo da base octal
        while True:
            try:
                o = int(input("digite o valor: "))
                if o >= 0 and all(c in "01234567" for c in str(o)): # valida se o input só contém dígitos de 0 a 7
                    resultado = octal_input(str(o))
                    break
                elif o >= 0:
                    print("Por favor, digite um número octal.")
                else:
                    print("conversão de valores menores que 0 indisponível")
            except ValueError:
                print("Por favor, digite um número octal.")
        cont = continuar()

    elif tipo == "h" or tipo == "16":
        # lida com conversões partindo da base hexadecimal
        while True:
            h = str(input("digite o valor: ")).strip().upper()
            if all(c in "0123456789ABCDEF" for c in h): # valida se o input só contém dígitos de 0 a 9 e A a F
                resultado = hexadecimal_input(h)
                break
            else:
                print("Por favor, digite um número hexadecimal.")
        cont = continuar()
    else:
        print("sistema numérico inválido")

else: # se 'cont' for 0, ou diferente de 1, imprime a saída abaixo e finaliza a execução do programa(somente a primeira opção deve ocorrer no programa)
    print("Tenha um bom dia (:")

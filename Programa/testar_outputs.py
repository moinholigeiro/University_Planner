def comparar_arquivos(arquivo1, arquivo2):
    with open(arquivo1, 'r', encoding='utf-8') as f1, open(arquivo2, 'r', encoding='utf-8') as f2:
        linhas1 = f1.readlines()
        linhas2 = f2.readlines()

    max_linhas = max(len(linhas1), len(linhas2))

    for i in range(max_linhas):
        linha1 = linhas1[i].rstrip('\n') if i < len(linhas1) else "<sem linha>"
        linha2 = linhas2[i].rstrip('\n') if i < len(linhas2) else "<sem linha>"

        if linha1 != linha2:
            print(f"🔹 Diferença na linha {i+1}:")
            print(f"  Arquivo 1: {linha1}")
            print(f"  Arquivo 2: {linha2}")
            print()

if __name__ == "__main__":
    comparar_arquivos('../Arquivos/Planejamento por período.txt', '../Arquivos/Planejamento por período - CORRETO.txt')
    comparar_arquivos('../Arquivos/Planejamento por prioridade.txt', '../Arquivos/Planejamento por prioridade - CORRETO.txt')

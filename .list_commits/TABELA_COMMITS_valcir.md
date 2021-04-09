Leia o arquivo ~/.list_commits/TABELA_COMMITS_valcir.md com o indice para maiores informacoes;
Read the file ~ /.list_commits/TABELA_COMMITS_valcir.md with the index for more information;

VALCIR01{
    - Realizado levantamento de requisitos, descricao do Arduino Nano V3 (atmega 328p);
    - Realizado o desenvolvimento locigo dos multiplexadores e realizado separação de dados e criterios de importancia dos pinos;
    - Tabela verdade com descrição de itens, possibilidades; (Revisar para mais aprimoramento)
    - Imagens e logos de artes criados;
    - Imagem de pinagem do arduino no diretorio ~/.arts;
    - Criado "tabela" para codigos e descrições anotados parecidos com programacao C++;
}

VALCIR02{
    - Renomeado aqruivo TABELA_COMITTS para TABELA_COMITTS_valcir;
    - Criado e movido para o diretorio ~/.list_commits;
}

VALCIR03{
    - Renomeado pasta "Conexoes-Wirings-Diagrama-Diagram" para "Conexoes_Diagrama";
    - Criado o arquivo de configuracao .gitignore e teste do mesmo;
}

VALCIR04{
    - Adicionado pasta datasheet com pdfs de espeficações tecnicas dos componentes;
    - Alteracao do arquivo ~/.gitignore para inorar a mesma;
}

VALCIR05{
    - mc3d - Modelo Computadorizado 3D;
    - Adicionado pasta "~/.mc3d" para modelos 3D do projeto;
    - Adicionado o mesmo no .gitignore;
    - Levantado dados tecenicos do Modulo CD e imagem salva na pasta ~/.arts;
}

VALCIR06{
    - pcb - Printed Circuit Board(Placa de Circuito Impresso);
    - Adicionado pasta "/.pcb" para desenenhos/diagramas do cirtcuito logico e eletrico;
}

VALCIR07{
    - Corrigido problema do projeto utilizando o SimulIDE SR4 x64 Windows;
    - Utilizado na simulacao o CI cd74ch4067;
    - Upload da pasta .pcb e seus dados;
}

VALCIR08{
    - Renomeado pastas para ingles:
    - .modulosCan -> .modulesCan;
    - Conexoes_Diagrama -> Wirings_Diagram;
    - Corrigido indexacao dos pinos conforme a tabela verdade na pasta ~/.logics/ITENS-NECESSIDADE.xlsx
    - Iniciado programação de algoritmo(fluxograma) no software DIA;
    - Adicionado informacao sobre pastas no readme principal;
}

VALCIR09{
    - Programado pinos e variaveis no arquivo [Interduinoface_v1](https://github.com/ValcirPolettini/InterDuinoFace_V1/blob/main/Interduinoface_v1.ino)
    - Alteracao do readme para linkar os textos aos arquivos correspondentes;
    - Alteracao planilha ITENS-NECESSIDADES.xlsx <- "ORD.";
    - Adicionado biblioteca [arduino-ad-mux-lib 3.0 - 2021/04](https://github.com/stechio/arduino-ad-mux-lib) para operar demux de 16 canais em libraries autor: [stechio](https://github.com/stechio);
    - Alteracao do arquivo [Mux.h]() para aceitar 16 em vez 8 canais;
    - Adicionado pasta [.androidControls](https://github.com/ValcirPolettini/InterDuinoFace_V1/tree/main/.androidCotrols) para o projeto do apk q ira monitorar a porta serial atras de comandos para controlar brilho, som e tela do RealDash;
}

VALCIR10{
    - Adicionado parametro em [.gitignore]() para exclusão da pasta [.vscode]();
}

VALCIR11{
    - Iniciado programacao e teste de leitura do motiplexador utilizando o SimullIDE.
}
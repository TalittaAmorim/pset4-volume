// Modifica o volume de um arquivo de áudio

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Número de bytes no cabeçalho .wav
const int HEADER_SIZE = 44;

typedef uint8_t BYTE; 

int main(int argc, char *argv[])
{
    // Verifique os argumentos da linha de comando
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Abrir arquivos e determinar o fator de escalonamento
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Não é possivel ler um arquivo.\n");
        return 1;
    }

    float factor = atof(argv[3]);
    BYTE header[HEADER_SIZE]; 

    // TODO: Copiar cabeçalho do arquivo de entrada para o arquivo de saída
    fread(header, sizeof(header), 1, input);
    fwrite(header, sizeof(header),1,output);
    
    // TODO: Ler amostras do arquivo de entrada e escrever dados atualizados no arquivo de saída
    
    // 2 bytes
    int16_t buffer;
    
    while(fread(&buffer, sizeof(buffer), 1, input)) 
    { 
        // multiplicar cada amostra pelo factor e gravar a nova amostra no arquivo de saída.
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
      
    // Fechar arquivos 
    fclose(input);
    fclose(output);
}

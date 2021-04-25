/*
 * Langage: Portuguese(BR) / English (by Google)
 * Por favor, usar esse padrão de fios para conexões do seu projeto.
 * Please use this wire pattern for your project's connections.
 * MODULO:          | TRAÇÃO / DRIVE|TRACTION             |
 * CAN ALTO(HIGHT): | LARANJA E PRETO / ORANGE & BLACK    |
 * CAN BAIXO(LOW):  | LARANJA E MARROM / ORANGE & BRAWN   |
 * *******************************************************|
 * MODULO:          | CONFORTO / COMFORT                  |
 * CAN ALTO(HIGHT): | LARANJA E VERDE  / ORANGE & GREEN   |
 * CAN BAIXO(LOW):  | LARANJA E MARROM / ORANGE & BRAWN   |
 * *******************************************************|
 * MODULO:          | INFOTENIMENTO / INFOTENMENT         |
 * CAN ALTO(HIGHT): | LARANJA E VIOLETA / ORANGE & VIOLET |
 * CAN BAIXO(LOW):  | LARANJA E MARROM  / ORANGE & BRAWN  |
 *  
 */

/*
 * Sinal: S0 -> Pino: D2 | Pino 2;
 * Sinal: S1 -> Pino: D4 | Pino 4;
 * Sinal: S2 -> Pino: D7 | Pino 7;
 * Sinal: S3 -> Pino: D8 | Pino 8;
 * Sinal: A0 -> Pino: A0 | Pino 19;(Conforme imagem: .arts\Arduino-Nano-Pin-Description-952x1024-1-768x826.jpg
 * Sinal: A1 -> Pino: A1 | Pino 20;(Conforme imagem: .arts\Arduino-Nano-Pin-Description-952x1024-1-768x826.jpg
 * Sinal: D0 -> Pino: D6 | Pino 6;
 * Sinal: D1 -> Pino: D5 | Pino 5;
 * 
 * BDX: | BYTE: | Sinal DEMUX: | DESCRICAO:
 * 0    | 0000  | A00:         | TENSÃO BATERIA;
 * 1    | 0001  | A01:         | VACUMETRO;
 * 2    | 0010  | A02:         | PRESSÃO COMBUSTIVEL;
 * 3    | 0011  | A03:         | TEMP. AMBIENTE;
 * 4    | 0100  | A04:         | -
 * 5    | 0101  | A05:         | -
 * 6    | 0110  | A06:         | -
 * 7    | 0111  | A07:         | -
 * 8    | 1000  | A08:         | -
 * 9    | 1001  | A09:         | -
 * 10   | 1010  | A10:         | -
 * 11   | 1011  | A11:         | -
 * 12   | 1100  | A12:         | -
 * 13   | 1101  | A13:         | -
 * 14   | 1110  | A14:         | -
 * 15   | 1111  | A15:         | -
 * -------------------------------------------------
 * 0    | 0000  | A16:         | PRESSÃO DE OLEO;
 * 1    | 0001  | A17:         | TEMP. OLEO;
 * 2    | 0010  | A18:         | VAZÃO DE COMBUSTIVEL;
 * 3    | 0011  | A19:         | -
 * 4    | 0100  | A20:         | -
 * 5    | 0101  | A21:         | -
 * 6    | 0110  | A22:         | -
 * 7    | 0111  | A23:         | -
 * 8    | 1000  | A24:         | -
 * 9    | 1001  | A25:         | -
 * 10   | 1010  | A26:         | -
 * 11   | 1011  | A27:         | -
 * 12   | 1100  | A28:         | -
 * 13   | 1101  | A29:         | -
 * 14   | 1110  | A30:         | -
 * 15   | 1111  | A31:         | -
 * -------------------------------------------------
 * 0    | 0000  | D00:         | CEBOLÃO OLEO MOTOR:
 * 1    | 0001  | D01:         | SETA ESQUERDA;
 * 2    | 0010  | D02:         | PISCA LERTA;
 * 3    | 0011  | D03:         | NIVEL FLUIDO FREIO;
 * 4    | 0100  | D04:         | FAROL;
 * 5    | 0101  | D05:         | MARHCA 1;
 * 6    | 0110  | D06:         | MARCHA 3;
 * 7    | 0111  | D07:         | MARCHA 5;
 * 8    | 1000  | D08:         | PORTA 1;
 * 9    | 1001  | D09:         | PORTA 2;
 * 10   | 1010  | D10:         | PORTA 4;
 * 11   | 1011  | D11:         | -
 * 12   | 1100  | D12:         | -
 * 13   | 1101  | D13:         | -
 * 14   | 1110  | D14:         | -
 * 15   | 1111  | D15:         | -
 * -------------------------------------------------
 * 0    | 0000  | D16:         | CEBOLAO TEMP RADIADOR;
 * 1    | 0001  | D17:         | SETA DIREITA;
 * 2    | 0010  | D18:         | SINAL FREIO DE MAO;
 * 3    | 0011  | D19:         | LIMPADOR PARA BRISA;
 * 4    | 0100  | D20:         | FAROL ALTO;
 * 5    | 0101  | D21:         | MARCHA 2;
 * 6    | 0110  | D22:         | MARCHA 4;
 * 7    | 0111  | D23:         | MARCHA 6;
 * 8    | 1000  | D24:         | PORTA 6;
 * 9    | 1001  | D25:         | PORTA 3;
 * 10   | 1010  | D26:         | PORTA 5;
 * 11   | 1011  | D27:         | -
 * 12   | 1100  | D28:         | -
 * 13   | 1101  | D29:         | -
 * 14   | 1110  | D30:         | -
 * 15   | 1111  | D31:         | -
 */

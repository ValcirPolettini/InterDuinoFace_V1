/*
 * Translate - Portuguese(Brazil)
 * Data criação: 21/03/2021
 * Autor: Valcir Polettini
 * Pagina: facebook.com/
 * GitHub: 
 * Compilador utilizado: - Arduino IDE 1.8.13
 * RealDash - 1.6.3
 * Android - 4.1.1(Tablet DL 1603 -> Rockchip RK2929)
 * Virtual serial port -
 * InterVisualFace - v1
 * 
 * Frame padrao CAN:
 * |SOF - Start of Frame | IDENTIFIER(11bits)   | RTR(1bit) - Remote Transmission Request | IDE(1bit) - IDentifer Extension | R0(1bit) | DLC(4bits) - Data Lenght Code | BYTES DATA(64bits)         | CRC(16bits) - Cyclic Redundancy Check | ACK(2bits) - Acknowledge | EOF(7bits) - End of Frame | IFS(7bits) - Iner-Frame Space |
 * |sof                  | 00000000000          |  0                                      |  0                              | 0        | 0000                          | 8 bytes -> 64 bits         | 00000000000000 0                      | 0 0                      | 0000000                   | 0000000                       |
 * 
 * Frame Estendido CAN:
 * |SOF - Start of Frame | IDENTIFIER(11bits)   | SRR - Substitute Remote Request | IDENTIFIER(18bits) | RTR(1bit) - Remote Transmission Request | IDE(1bit) - IDentifer Extension | R0(1bit) | DLC(4bits) - Data Lenght Code | BYTES DATA(64bits)         | CRC(16bits) - Cyclic Redundancy Check | ACK(2bits) - Acknowledge | EOF(7bits) - End of Frame | IFS(7bits) - Iner-Frame Space |
 * |sof                  | 00000000000          |                                 | 000000000000000000 |  0                                      |  0                              | 0        | 0000                          | 8 bytes -> 64 bits         | 00000000000000 0                      | 0 0                      | 0000000                   | 0000000                       |
 * List frame index for :
 * * Please use this wire pattern for your project's connections.
 * MODULO:          | TRAÇÃO / DRIVE|TRACTION             |
 * CAN ALTO(HIGHT): | LARANJA E PRETO / ORANGE & BLACK    |
 * CAN BAIXO(LOW):  | LARANJA E MARROM / ORANGE & BRAWN   |
 * *******************************************************|
 * BYTE: | List frame index for TRAÇÃO / DRIVE|TRACTION:
 * 
 * * Please use this wire pattern for your project's connections.
 * MODULO:          | CONFORTO / COMFORT                  |
 * CAN ALTO(HIGHT): | LARANJA E VERDE  / ORANGE & GREEN   |
 * CAN BAIXO(LOW):  | LARANJA E MARROM / ORANGE & BRAWN   |
 * *******************************************************|
 * BYTE: | List frame index for CONFORTO / COMFORT
 * 
 * * Please use this wire pattern for your project's connections.
 * MODULO:          | INFOTENIMENTO / INFOTENMENT         |
 * CAN ALTO(HIGHT): | LARANJA E VIOLETA / ORANGE & VIOLET |
 * CAN BAIXO(LOW):  | LARANJA E MARROM  / ORANGE & BRAWN  |
 * *******************************************************|
 * BYTE: | List frame index for INFOTENIMENTO / INFOTENMENT
 * 
 */

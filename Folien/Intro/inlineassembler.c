#define CONTROL_REGISTER 0x1001
#define RECEIVE_REGISTER 0x1002
#define ACTIVATE 0x12
#define TIMEOUT 1000
volatile unsigned char receive;
/* Variable soll im Speicher abgelegt werden, da im
Assemblerteil darauf zugegriffen wird: _receive */
void main() {
int time; receive = 0;
for (time = 0; (receive != ACTIVATE) &&
(time < TIMEOUT); time++){
/* Empfangenes Datum wird durch CTRL_REG erkannt
Kopieren des Empfangsregisters in receive */
asm{
btst.b #4,CONTROL_REGISTER
bne _l1
move.b RECEIVE_REGISTER,_receive
_l1:
}}}


void bin2hex(byte *param_1,int param_2)

{
  char *pcVar1;
  uint uVar2;
  char *pcVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  
  uVar2 = param_2 * 2 + 1;
  uVar6 = uVar2 & 3;
  if ((int)uVar2 < 1) {
    uVar6 = -(-uVar2 & 3);
  }
  pcVar3 = (char *)_cgcalloc(uVar2 + (4 - uVar6),1,"util.c",DAT_00045fe4,0x315);
  if (0 < param_2) {
    pbVar4 = param_1;
    pcVar1 = pcVar3;
    do {
      pbVar5 = pbVar4 + 1;
      *pcVar1 = "0123456789abcdefbin2hex"[*pbVar4 >> 4];
      pcVar1[1] = "0123456789abcdefbin2hex"[*pbVar4 & 0xf];
      pbVar4 = pbVar5;
      pcVar1 = pcVar1 + 2;
    } while (pbVar5 != param_1 + param_2);
    pcVar3 = pcVar3 + param_2 * 2;
  }
  *pcVar3 = '\0';
  return;
}


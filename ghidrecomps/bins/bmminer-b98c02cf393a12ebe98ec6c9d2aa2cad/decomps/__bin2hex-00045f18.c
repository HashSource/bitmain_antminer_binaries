
void __bin2hex(undefined *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined *puVar3;
  
  if (0 < param_3) {
    pbVar1 = param_2;
    puVar3 = param_1 + 2;
    do {
      pbVar2 = pbVar1 + 1;
      puVar3[-2] = "0123456789abcdefbin2hex"[*pbVar1 >> 4];
      puVar3[-1] = "0123456789abcdefbin2hex"[*pbVar1 & 0xf];
      pbVar1 = pbVar2;
      puVar3 = puVar3 + 2;
    } while (pbVar2 != param_2 + param_3);
    param_1[param_3 * 2] = 0;
    return;
  }
  *param_1 = 0;
  return;
}


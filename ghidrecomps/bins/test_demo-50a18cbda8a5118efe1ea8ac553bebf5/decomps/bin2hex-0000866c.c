
void bin2hex(char *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  
  if (param_3 != 0) {
    pbVar2 = param_2;
    do {
      pbVar1 = pbVar2 + 1;
      sprintf(param_1,DAT_0000868c,(uint)*pbVar2);
      pbVar2 = pbVar1;
      param_1 = param_1 + 2;
    } while (pbVar1 != param_2 + param_3);
  }
  return;
}


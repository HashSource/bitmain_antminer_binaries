
int OPENSSL_strlcat(byte *param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  
  if (param_3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (uint)*param_1;
    if (uVar4 != 0) {
      pbVar3 = param_1 + 1;
      do {
        param_3 = param_3 + -1;
        uVar4 = (int)pbVar3 - (int)param_1;
        if (param_3 == 0) break;
        bVar1 = *pbVar3;
        pbVar3 = pbVar3 + 1;
      } while (bVar1 != 0);
    }
  }
  iVar2 = OPENSSL_strlcpy();
  return iVar2 + uVar4;
}


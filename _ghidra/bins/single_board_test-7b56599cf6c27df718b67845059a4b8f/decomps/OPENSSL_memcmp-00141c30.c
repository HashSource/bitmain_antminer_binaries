
int OPENSSL_memcmp(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  if (param_3 == 0) {
    return 0;
  }
  bVar1 = *param_2;
  if ((uint)*param_1 - (uint)bVar1 == 0) {
    pbVar3 = param_1 + 1;
    while (pbVar3 != param_1 + param_3) {
      bVar2 = *pbVar3;
      param_2 = param_2 + 1;
      pbVar3 = pbVar3 + 1;
      if ((uint)bVar2 - (uint)*param_2 != 0) {
        return (uint)bVar2 - (uint)*param_2;
      }
    }
  }
  return (uint)*param_1 - (uint)bVar1;
}



undefined4 tls_parse_stoc_early_data(int param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  uint uVar6;
  
  uVar6 = param_2[1];
  if (param_3 == 0x2000) {
    if (3 < uVar6) {
      pbVar5 = (byte *)*param_2;
      bVar4 = *pbVar5;
      bVar1 = pbVar5[1];
      bVar2 = pbVar5[2];
      bVar3 = pbVar5[3];
      *param_2 = pbVar5 + 4;
      param_2[1] = uVar6 - 4;
      if (uVar6 - 4 == 0) {
        *(uint *)(*(int *)(param_1 + 0x474) + 0x1e0) =
             (uint)bVar3 | (uint)bVar1 << 0x10 | (uint)bVar4 << 0x18 | (uint)bVar2 << 8;
        return 1;
      }
    }
    ossl_statem_fatal(param_1,0x32,0x21a,0xae,"ssl/statem/extensions_clnt.c",0x791);
    return 0;
  }
  if (uVar6 != 0) {
    ossl_statem_fatal(param_1,0x32,0x21a,0x6e,"ssl/statem/extensions_clnt.c",0x79c);
    return 0;
  }
  if ((*(int *)(param_1 + 0x5b0) != 0) && (*(int *)(param_1 + 0x8c) != 0)) {
    *(undefined4 *)(param_1 + 0x5ac) = 2;
    return 1;
  }
  ossl_statem_fatal(param_1,0x2f,0x21a,0x6e,"ssl/statem/extensions_clnt.c",0x7a8);
  return 0;
}


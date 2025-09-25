
undefined4
tls_parse_all_extensions
          (int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x404) + 0xf4);
  if (iVar3 != -0x1a) {
    iVar1 = 0;
    do {
      iVar2 = iVar1 + 1;
      iVar1 = tls_parse_extension(param_1,iVar1,param_2,param_3,param_4,param_5);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = iVar2;
    } while (iVar3 + 0x1a != iVar2);
  }
  if (param_6 != 0) {
    iVar3 = param_3 + 0x270;
    puVar4 = &ext_defs;
    do {
      while( true ) {
        HintPreloadData(puVar4 + 0x37);
        if (((code *)puVar4[7] == (code *)0x0) || ((param_2 & puVar4[1]) == 0)) break;
        iVar1 = (*(code *)puVar4[7])(param_1,param_2,*(undefined4 *)(param_3 + 8));
        if (iVar1 == 0) {
          return 0;
        }
        param_3 = param_3 + 0x18;
        puVar4 = puVar4 + 8;
        if (param_3 == iVar3) {
          return 1;
        }
      }
      param_3 = param_3 + 0x18;
      puVar4 = puVar4 + 8;
    } while (param_3 != iVar3);
  }
  return 1;
}



void __libc_csu_init(EVP_PKEY_CTX *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code **ppcVar4;
  
  iVar1 = DAT_0002ba5c;
  iVar2 = DAT_0002ba58;
  iVar3 = DAT_0002ba58 + 0x2ba30;
  _init(param_1);
  iVar1 = (iVar1 + 0x2ba36) - iVar3 >> 2;
  if (iVar1 != 0) {
    ppcVar4 = (code **)(iVar2 + 0x2ba2c);
    iVar2 = 0;
    do {
      ppcVar4 = ppcVar4 + 1;
      iVar2 = iVar2 + 1;
      (**ppcVar4)(param_1,param_2,param_3,*ppcVar4,param_4);
    } while (iVar2 != iVar1);
  }
  return;
}



void __libc_csu_init(EVP_PKEY_CTX *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code **ppcVar3;
  int iVar4;
  
  iVar1 = DAT_00097b74;
  iVar4 = DAT_00097b70 + 0x97b38;
  _init(param_1);
  iVar4 = iVar4 - (int)(code **)(iVar1 + 0x97b40) >> 2;
  if (iVar4 == 0) {
    return;
  }
  iVar2 = 0;
  ppcVar3 = (code **)(iVar1 + 0x97b40);
  do {
    iVar2 = iVar2 + 1;
    (**ppcVar3)(param_1,param_2,param_3);
    ppcVar3 = ppcVar3 + 1;
  } while (iVar4 != iVar2);
  return;
}



void OPENSSL_LH_doall_arg(int *param_1,code *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == (int *)0x0) {
    return;
  }
  iVar4 = param_1[3] + -1;
  if (iVar4 < 0) {
    return;
  }
  iVar3 = (param_1[3] + 0x3fffffff) * 4;
  do {
    puVar1 = *(undefined4 **)(*param_1 + iVar3);
    while (puVar1 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)puVar1[1];
      (*param_2)(*puVar1,param_3);
      puVar1 = puVar2;
    }
    iVar4 = iVar4 + -1;
    iVar3 = iVar3 + -4;
  } while (iVar4 != -1);
  return;
}



void OPENSSL_LH_doall(int *param_1,code *param_2)

{
  undefined4 uVar1;
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
    puVar2 = *(undefined4 **)(*param_1 + iVar3);
    while (puVar2 != (undefined4 *)0x0) {
      uVar1 = *puVar2;
      puVar2 = (undefined4 *)puVar2[1];
      (*param_2)(uVar1);
    }
    iVar4 = iVar4 + -1;
    iVar3 = iVar3 + -4;
  } while (iVar4 != -1);
  return;
}


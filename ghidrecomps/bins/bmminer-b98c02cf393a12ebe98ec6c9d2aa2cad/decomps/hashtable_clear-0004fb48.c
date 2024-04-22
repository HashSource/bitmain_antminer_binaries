
void hashtable_clear(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  hashtable_do_clear();
  iVar1 = 1 << (param_1[2] & 0xff);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)param_1[1];
    puVar3 = puVar2;
    do {
      puVar3[1] = param_1 + 3;
      puVar4 = puVar3 + 2;
      *puVar3 = param_1 + 3;
      puVar3 = puVar4;
    } while (puVar2 + iVar1 * 2 != puVar4);
  }
  param_1[4] = param_1 + 3;
  param_1[3] = param_1 + 3;
  param_1[6] = param_1 + 5;
  param_1[5] = param_1 + 5;
  *param_1 = 0;
  return;
}


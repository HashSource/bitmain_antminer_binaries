
undefined4 hashtable_init(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  *param_1 = 0;
  param_1[2] = 3;
  puVar1 = (undefined4 *)jsonp_malloc(0x40);
  param_1[1] = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  puVar5 = param_1 + 3;
  param_1[4] = puVar5;
  param_1[3] = puVar5;
  iVar4 = 1 << (param_1[2] & 0xff);
  param_1[6] = param_1 + 5;
  param_1[5] = param_1 + 5;
  if (iVar4 != 0) {
    puVar2 = puVar1;
    do {
      puVar2[1] = puVar5;
      puVar3 = puVar2 + 2;
      *puVar2 = puVar5;
      puVar2 = puVar3;
    } while (puVar3 != puVar1 + iVar4 * 2);
  }
  return 0;
}


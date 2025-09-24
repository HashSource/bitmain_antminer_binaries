
undefined4 tls1_set_groups(undefined4 *param_1,int *param_2,int param_3,int param_4)

{
  int *piVar1;
  void *ptr;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined2 *puVar8;
  uint uVar9;
  
  if (param_4 == 0) {
    ERR_put_error(0x14,0x275,0x10f,"ssl/t1_lib.c",0x15e);
    return 0;
  }
  ptr = CRYPTO_malloc(param_4 << 1,"ssl/t1_lib.c",0x161);
  if (ptr == (void *)0x0) {
    ERR_put_error(0x14,0x275,0x41,"ssl/t1_lib.c",0x162);
    uVar2 = 0;
  }
  else {
    uVar9 = 0;
    piVar7 = (int *)(param_3 + -4);
    iVar6 = 0;
    puVar8 = (undefined2 *)((int)ptr + -2);
    do {
      iVar3 = 0;
      piVar7 = piVar7 + 1;
      uVar4 = 0;
      while( true ) {
        piVar1 = (int *)((int)&nid_list + iVar3);
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 0xc;
        if (*piVar7 == *piVar1) break;
        if (uVar4 == 0x1e) goto LAB_000fa822;
      }
      uVar5 = 1 << (uVar4 & 0xff);
      if ((uVar9 & uVar5) != 0) {
LAB_000fa822:
        CRYPTO_free(ptr);
        return 0;
      }
      iVar6 = iVar6 + 1;
      uVar9 = uVar9 | uVar5;
      puVar8 = puVar8 + 1;
      *puVar8 = (short)uVar4;
    } while (param_4 != iVar6);
    CRYPTO_free((void *)*param_1);
    uVar2 = 1;
    *param_1 = ptr;
    *param_2 = param_4;
  }
  return uVar2;
}


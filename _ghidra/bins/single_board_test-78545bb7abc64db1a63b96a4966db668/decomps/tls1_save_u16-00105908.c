
undefined4 tls1_save_u16(undefined4 *param_1,undefined4 *param_2,uint *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  void *ptr;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined2 *puVar7;
  
  uVar6 = param_1[1];
  if (uVar6 == 0) {
    return 0;
  }
  if ((uVar6 & 1) == 0) {
    uVar6 = uVar6 >> 1;
    ptr = CRYPTO_malloc(uVar6 << 1,"ssl/t1_lib.c",0x713);
    if (ptr == (void *)0x0) {
      ERR_put_error(0x14,0x274,0x41,"ssl/t1_lib.c",0x714);
      return 0;
    }
    if (uVar6 == 0) {
LAB_0010599c:
      CRYPTO_free((void *)*param_2);
      *param_2 = ptr;
      *param_3 = uVar6;
      return 1;
    }
    uVar3 = param_1[1];
    if (1 < uVar3) {
      puVar7 = (undefined2 *)((int)ptr + -2);
      uVar4 = 0;
      puVar5 = (undefined1 *)*param_1;
      do {
        uVar1 = *puVar5;
        uVar4 = uVar4 + 1;
        uVar2 = puVar5[1];
        uVar3 = uVar3 - 2;
        *param_1 = puVar5 + 2;
        param_1[1] = uVar3;
        puVar7 = puVar7 + 1;
        *puVar7 = CONCAT11(uVar1,uVar2);
        if (uVar6 == uVar4) goto LAB_0010599c;
        puVar5 = puVar5 + 2;
      } while (1 < uVar3);
    }
    CRYPTO_free(ptr);
  }
  return 0;
}


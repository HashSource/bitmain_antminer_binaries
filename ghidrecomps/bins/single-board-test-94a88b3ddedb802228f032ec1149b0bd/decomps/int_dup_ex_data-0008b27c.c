
undefined4 int_dup_ex_data(undefined4 param_1,_STACK **param_2,_STACK **param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *ptr;
  void *pvVar4;
  _STACK *p_Var5;
  int iVar6;
  int iVar7;
  void **ppvVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  void *local_2c [2];
  
  if (*param_3 != (_STACK *)0x0) {
    iVar1 = def_get_class();
    if (iVar1 == 0) {
      return 0;
    }
    CRYPTO_lock(5,2,DAT_0008b48c,0x1d2);
    iVar2 = sk_num(*(_STACK **)(iVar1 + 4));
    iVar3 = sk_num(*param_3);
    if (iVar3 < iVar2) {
      iVar2 = iVar3;
    }
    if (iVar2 < 1) {
      CRYPTO_lock(6,2,DAT_0008b48c,0x1df);
      return 1;
    }
    ptr = CRYPTO_malloc(iVar2 << 2,DAT_0008b48c,0x1d8);
    if (ptr == (void *)0x0) {
      CRYPTO_lock(6,2,DAT_0008b48c,0x1df);
      ERR_put_error(0xf,0x6a,0x41,DAT_0008b48c,0x1e1);
      return 0;
    }
    if (iVar2 < 9) {
      iVar3 = 0;
    }
    else {
      iVar7 = (int)ptr + 0x28;
      iVar3 = 0;
      do {
        pvVar4 = sk_value(*(_STACK **)(iVar1 + 4),iVar3);
        *(void **)(iVar7 + -0x28) = pvVar4;
        HintPreloadData(iVar7);
        pvVar4 = sk_value(*(_STACK **)(iVar1 + 4),iVar3 + 1);
        *(void **)(iVar7 + -0x24) = pvVar4;
        pvVar4 = sk_value(*(_STACK **)(iVar1 + 4),iVar3 + 2);
        *(void **)(iVar7 + -0x20) = pvVar4;
        pvVar4 = sk_value(*(_STACK **)(iVar1 + 4),iVar3 + 3);
        *(void **)(iVar7 + -0x1c) = pvVar4;
        pvVar4 = sk_value(*(_STACK **)(iVar1 + 4),iVar3 + 4);
        *(void **)(iVar7 + -0x18) = pvVar4;
        pvVar4 = sk_value(*(_STACK **)(iVar1 + 4),iVar3 + 5);
        *(void **)(iVar7 + -0x14) = pvVar4;
        pvVar4 = sk_value(*(_STACK **)(iVar1 + 4),iVar3 + 6);
        *(void **)(iVar7 + -0x10) = pvVar4;
        iVar6 = iVar3 + 7;
        iVar3 = iVar3 + 8;
        pvVar4 = sk_value(*(_STACK **)(iVar1 + 4),iVar6);
        *(void **)(iVar7 + -0xc) = pvVar4;
        iVar7 = iVar7 + 0x20;
      } while (iVar3 != (iVar2 - 9U & 0xfffffff8) + 8);
    }
    ppvVar8 = (void **)((int)ptr + (iVar3 + -1) * 4);
    do {
      iVar7 = iVar3 + 1;
      pvVar4 = sk_value(*(_STACK **)(iVar1 + 4),iVar3);
      ppvVar8 = ppvVar8 + 1;
      *ppvVar8 = pvVar4;
      iVar3 = iVar7;
    } while (iVar7 < iVar2);
    CRYPTO_lock(6,2,DAT_0008b48c,0x1df);
    iVar1 = 0;
    puVar9 = (undefined4 *)((int)ptr + -4);
    do {
      if ((*param_3 == (_STACK *)0x0) || (iVar3 = sk_num(*param_3), iVar3 <= iVar1)) {
        local_2c[0] = (void *)0x0;
      }
      else {
        local_2c[0] = sk_value(*param_3,iVar1);
      }
      puVar9 = puVar9 + 1;
      puVar10 = (undefined4 *)*puVar9;
      if ((puVar10 != (undefined4 *)0x0) && ((code *)puVar10[4] != (code *)0x0)) {
        (*(code *)puVar10[4])(param_2,param_3,local_2c,iVar1,*puVar10,puVar10[1]);
      }
      pvVar4 = local_2c[0];
      p_Var5 = *param_2;
      if (p_Var5 == (_STACK *)0x0) {
        p_Var5 = sk_new_null();
        *param_2 = p_Var5;
        if (p_Var5 != (_STACK *)0x0) goto LAB_0008b3e4;
        ERR_put_error(0xf,0x66,0x41,DAT_0008b48c,0x267);
      }
      else {
LAB_0008b3e4:
        iVar3 = sk_num(p_Var5);
        do {
          if (iVar1 < iVar3) {
            sk_set(*param_2,iVar1,pvVar4);
            goto LAB_0008b408;
          }
          iVar3 = iVar3 + 1;
          iVar7 = sk_push(*param_2,(void *)0x0);
        } while (iVar7 != 0);
        ERR_put_error(0xf,0x66,0x41,DAT_0008b48c,0x26f);
      }
LAB_0008b408:
      iVar1 = iVar1 + 1;
    } while (iVar1 != iVar2);
    CRYPTO_free(ptr);
  }
  return 1;
}


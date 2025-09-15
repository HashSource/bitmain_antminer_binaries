
void int_free_ex_data(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *ptr;
  void *pvVar3;
  int iVar4;
  _STACK *p_Var5;
  int iVar6;
  code *pcVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  if ((ex_data != 0) && (iVar1 = def_get_class(), iVar1 != 0)) {
    CRYPTO_lock(5,2,"ex_data.c",0x1fb);
    iVar2 = sk_num(*(_STACK **)(iVar1 + 4));
    if (iVar2 < 1) {
      CRYPTO_lock(6,2,"ex_data.c",0x205);
    }
    else {
      ptr = (undefined4 *)CRYPTO_malloc(iVar2 << 2,"ex_data.c",0x1fe);
      if (ptr == (undefined4 *)0x0) {
        CRYPTO_lock(6,2,"ex_data.c",0x205);
        ERR_put_error(0xf,0x6b,0x41,"ex_data.c",0x207);
        return;
      }
      if (iVar2 < 9) {
        iVar6 = 0;
      }
      else {
        puVar8 = ptr + 10;
        iVar6 = 0;
        do {
          pvVar3 = sk_value(*(_STACK **)(iVar1 + 4),iVar6);
          puVar8[-10] = pvVar3;
          HintPreloadData(puVar8);
          pvVar3 = sk_value(*(_STACK **)(iVar1 + 4),iVar6 + 1);
          puVar8[-9] = pvVar3;
          pvVar3 = sk_value(*(_STACK **)(iVar1 + 4),iVar6 + 2);
          puVar8[-8] = pvVar3;
          pvVar3 = sk_value(*(_STACK **)(iVar1 + 4),iVar6 + 3);
          puVar8[-7] = pvVar3;
          pvVar3 = sk_value(*(_STACK **)(iVar1 + 4),iVar6 + 4);
          puVar8[-6] = pvVar3;
          pvVar3 = sk_value(*(_STACK **)(iVar1 + 4),iVar6 + 5);
          puVar8[-5] = pvVar3;
          pvVar3 = sk_value(*(_STACK **)(iVar1 + 4),iVar6 + 6);
          puVar8[-4] = pvVar3;
          iVar4 = iVar6 + 7;
          iVar6 = iVar6 + 8;
          pvVar3 = sk_value(*(_STACK **)(iVar1 + 4),iVar4);
          puVar8[-3] = pvVar3;
          puVar8 = puVar8 + 8;
        } while (iVar6 != (iVar2 - 9U & 0xfffffff8) + 8);
      }
      puVar8 = ptr + iVar6 + -1;
      do {
        pvVar3 = sk_value(*(_STACK **)(iVar1 + 4),iVar6);
        iVar6 = iVar6 + 1;
        puVar8 = puVar8 + 1;
        *puVar8 = pvVar3;
      } while (iVar6 < iVar2);
      CRYPTO_lock(6,2,"ex_data.c",0x205);
      iVar1 = 0;
      puVar8 = ptr;
      do {
        puVar9 = (undefined4 *)*puVar8;
        if ((puVar9 != (undefined4 *)0x0) && (pcVar7 = (code *)puVar9[3], pcVar7 != (code *)0x0)) {
          p_Var5 = (_STACK *)*param_3;
          if (p_Var5 != (_STACK *)0x0) {
            iVar6 = sk_num(p_Var5);
            if (iVar1 < iVar6) {
              p_Var5 = (_STACK *)sk_value((_STACK *)*param_3,iVar1);
              puVar9 = (undefined4 *)*puVar8;
              pcVar7 = (code *)puVar9[3];
            }
            else {
              puVar9 = (undefined4 *)*puVar8;
              p_Var5 = (_STACK *)0x0;
              pcVar7 = (code *)puVar9[3];
            }
          }
          (*pcVar7)(param_2,p_Var5,param_3,iVar1,*puVar9,puVar9[1]);
        }
        iVar1 = iVar1 + 1;
        puVar8 = puVar8 + 1;
      } while (iVar1 != iVar2);
      CRYPTO_free(ptr);
    }
    if ((_STACK *)*param_3 != (_STACK *)0x0) {
      sk_free((_STACK *)*param_3);
      *param_3 = 0;
    }
  }
  return;
}


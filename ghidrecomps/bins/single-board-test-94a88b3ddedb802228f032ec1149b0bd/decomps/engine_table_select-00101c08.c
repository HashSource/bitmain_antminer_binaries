
_LHASH * engine_table_select(_LHASH **param_1,undefined4 param_2)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  _LHASH *p_Var4;
  int iVar5;
  undefined4 local_28 [5];
  
  p_Var4 = *param_1;
  if (p_Var4 != (_LHASH *)0x0) {
    ERR_set_mark();
    CRYPTO_lock(9,0x1e,DAT_00101cbc,0x103);
    if ((*param_1 == (_LHASH *)0x0) ||
       (local_28[0] = param_2, pvVar2 = lh_retrieve(*param_1,local_28), pvVar2 == (void *)0x0)) {
      p_Var4 = (_LHASH *)0x0;
    }
    else if (((*(int *)((int)pvVar2 + 8) == 0) || (iVar3 = engine_unlocked_init(), iVar3 == 0)) &&
            (piVar1 = DAT_00101cc0, *(int *)((int)pvVar2 + 0xc) == 0)) {
      iVar3 = 0;
      do {
        iVar5 = iVar3 + 1;
        p_Var4 = (_LHASH *)sk_value(*(_STACK **)((int)pvVar2 + 4),iVar3);
        if (p_Var4 == (_LHASH *)0x0) goto LAB_00101c94;
        iVar3 = iVar5;
      } while (((p_Var4->error < 1) && (*piVar1 << 0x1f < 0)) ||
              (iVar5 = engine_unlocked_init(), iVar5 == 0));
      if ((p_Var4 != *(_LHASH **)((int)pvVar2 + 8)) &&
         (iVar3 = engine_unlocked_init(p_Var4), iVar3 != 0)) {
        if (*(int *)((int)pvVar2 + 8) != 0) {
          engine_unlocked_finish(*(int *)((int)pvVar2 + 8),0);
        }
        *(_LHASH **)((int)pvVar2 + 8) = p_Var4;
      }
LAB_00101c94:
      *(undefined4 *)((int)pvVar2 + 0xc) = 1;
    }
    else {
      p_Var4 = *(_LHASH **)((int)pvVar2 + 8);
      *(undefined4 *)((int)pvVar2 + 0xc) = 1;
    }
    CRYPTO_lock(10,0x1e,DAT_00101cbc,0x14a);
    ERR_pop_to_mark();
  }
  return p_Var4;
}



void * engine_table_select(undefined4 *param_1,undefined4 param_2)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined4 local_28 [5];
  
  pvVar3 = (void *)*param_1;
  if (pvVar3 != (void *)0x0) {
    ERR_set_mark();
    CRYPTO_lock(9,0x1e,"eng_table.c",0x103);
    if (((_LHASH *)*param_1 == (_LHASH *)0x0) ||
       (local_28[0] = param_2, pvVar1 = lh_retrieve((_LHASH *)*param_1,local_28),
       pvVar1 == (void *)0x0)) {
      pvVar3 = (void *)0x0;
    }
    else if (((*(int *)((int)pvVar1 + 8) == 0) || (iVar2 = engine_unlocked_init(), iVar2 == 0)) &&
            (*(int *)((int)pvVar1 + 0xc) == 0)) {
      iVar2 = 0;
      do {
        iVar4 = iVar2 + 1;
        pvVar3 = sk_value(*(_STACK **)((int)pvVar1 + 4),iVar2);
        if (pvVar3 == (void *)0x0) goto LAB_0019b234;
        iVar2 = iVar4;
      } while (((*(int *)((int)pvVar3 + 0x5c) < 1) && (table_flags << 0x1f < 0)) ||
              (iVar4 = engine_unlocked_init(), iVar4 == 0));
      if ((pvVar3 != *(void **)((int)pvVar1 + 8)) &&
         (iVar2 = engine_unlocked_init(pvVar3), iVar2 != 0)) {
        if (*(int *)((int)pvVar1 + 8) != 0) {
          engine_unlocked_finish(*(int *)((int)pvVar1 + 8),0);
        }
        *(void **)((int)pvVar1 + 8) = pvVar3;
      }
LAB_0019b234:
      *(undefined4 *)((int)pvVar1 + 0xc) = 1;
    }
    else {
      pvVar3 = *(void **)((int)pvVar1 + 8);
      *(undefined4 *)((int)pvVar1 + 0xc) = 1;
    }
    CRYPTO_lock(10,0x1e,"eng_table.c",0x14a);
    ERR_pop_to_mark();
  }
  return pvVar3;
}


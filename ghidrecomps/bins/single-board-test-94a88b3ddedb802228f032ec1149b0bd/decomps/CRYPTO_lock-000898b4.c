
void CRYPTO_lock(int mode,int type,char *file,int line)

{
  int iVar1;
  CRYPTO_dynlock_value *pCVar2;
  undefined4 *ptr;
  int iVar3;
  _STACK *p_Var4;
  int iVar5;
  code *pcVar6;
  
  iVar1 = DAT_00089900;
  if (-1 < type) {
    if (*(code **)(DAT_00089900 + 0x10) != (code *)0x0) {
      (**(code **)(DAT_00089900 + 0x10))();
    }
    return;
  }
  if (*(int *)(DAT_00089900 + 8) == 0) {
    return;
  }
  pCVar2 = CRYPTO_get_dynlock_value(type);
  if (pCVar2 != (CRYPTO_dynlock_value *)0x0) {
    (**(code **)(iVar1 + 8))(mode,pCVar2,file,line);
    CRYPTO_destroy_dynlockid(type);
    return;
  }
  CRYPTO_lock_part_0(0,0);
  iVar1 = DAT_00089a18;
  if (*(int *)(DAT_00089a18 + 4) == 0) {
    ERR_put_error(0xf,0x67,100,DAT_00089a1c,0xf8);
    return;
  }
  if (*(code **)(DAT_00089a18 + 0x10) != (code *)0x0) {
    (**(code **)(DAT_00089a18 + 0x10))(9,0x1d,DAT_00089a1c,0xfb);
  }
  iVar5 = DAT_00089a18;
  if (*(int *)(iVar1 + 0x20) == 0) {
    p_Var4 = sk_new_null();
    *(_STACK **)(iVar5 + 0x20) = p_Var4;
    if (p_Var4 == (_STACK *)0x0) {
      pcVar6 = *(code **)(iVar5 + 0x10);
      if (pcVar6 != (code *)0x0) {
        (*pcVar6)(10,0x1d,DAT_00089a1c,0xfe);
      }
      iVar5 = 0xff;
      goto LAB_000899ce;
    }
  }
  if (*(code **)(iVar1 + 0x10) != (code *)0x0) {
    (**(code **)(iVar1 + 0x10))(10,0x1d,DAT_00089a1c,0x102);
  }
  ptr = (undefined4 *)CRYPTO_malloc(8,DAT_00089a1c,0x104);
  iVar5 = 0x106;
  if (ptr != (undefined4 *)0x0) {
    pcVar6 = *(code **)(iVar1 + 4);
    *ptr = 1;
    iVar3 = (*pcVar6)(DAT_00089a1c,0x10a);
    iVar5 = DAT_00089a18;
    ptr[1] = iVar3;
    if (iVar3 != 0) {
      if (*(code **)(iVar5 + 0x10) != (code *)0x0) {
        (**(code **)(iVar5 + 0x10))(9,0x1d,DAT_00089a1c,0x111);
      }
      iVar5 = sk_find(*(_STACK **)(iVar1 + 0x20),(void *)0x0);
      if (iVar5 == -1) {
        iVar5 = sk_push(*(_STACK **)(DAT_00089a18 + 0x20),ptr);
        iVar5 = iVar5 + -1;
      }
      else {
        sk_set(*(_STACK **)(DAT_00089a18 + 0x20),iVar5,ptr);
      }
      if (*(code **)(iVar1 + 0x10) != (code *)0x0) {
        (**(code **)(iVar1 + 0x10))(10,0x1d,DAT_00089a1c,0x121);
      }
      if (iVar5 != -1) {
        return;
      }
      (**(code **)(iVar1 + 0xc))(ptr[1],DAT_00089a1c,0x124);
      CRYPTO_free(ptr);
      return;
    }
    CRYPTO_free(ptr);
    iVar5 = 0x10d;
  }
LAB_000899ce:
  ERR_put_error(0xf,0x67,0x41,DAT_00089a1c,iVar5);
  return;
}


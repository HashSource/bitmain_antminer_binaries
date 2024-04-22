
void CRYPTO_destroy_dynlockid(int i)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *ptr;
  
  iVar1 = DAT_00089848;
  if (i != 0) {
    i = ~i;
  }
  if (*(int *)(DAT_00089848 + 0xc) != 0) {
    if (*(code **)(DAT_00089848 + 0x10) != (code *)0x0) {
      (**(code **)(DAT_00089848 + 0x10))(9,0x1d,DAT_0008984c,0x133);
    }
    iVar2 = DAT_00089848;
    if ((*(_STACK **)(iVar1 + 0x20) == (_STACK *)0x0) ||
       (iVar3 = sk_num(*(_STACK **)(iVar1 + 0x20)), iVar3 <= i)) {
      if (*(code **)(iVar1 + 0x10) != (code *)0x0) {
        (**(code **)(iVar1 + 0x10))(10,0x1d,DAT_0008984c,0x136);
        return;
      }
      return;
    }
    ptr = (int *)sk_value(*(_STACK **)(iVar2 + 0x20),i);
    if ((ptr == (int *)0x0) || (iVar3 = *ptr, *ptr = iVar3 + -1, 0 < iVar3 + -1)) {
      ptr = (int *)0x0;
    }
    else {
      sk_set(*(_STACK **)(iVar2 + 0x20),i,(void *)0x0);
    }
    if (*(code **)(iVar1 + 0x10) != (code *)0x0) {
      (**(code **)(iVar1 + 0x10))(10,0x1d,DAT_0008984c,0x148);
    }
    if (ptr != (int *)0x0) {
      (**(code **)(iVar1 + 0xc))(ptr[1],DAT_0008984c,0x14b);
      CRYPTO_free(ptr);
      return;
    }
  }
  return;
}


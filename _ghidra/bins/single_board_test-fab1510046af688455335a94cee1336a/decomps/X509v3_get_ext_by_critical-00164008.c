
int X509v3_get_ext_by_critical(stack_st_X509_EXTENSION *x,int crit,int lastpos)

{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  
  if (x != (stack_st_X509_EXTENSION *)0x0) {
    uVar3 = lastpos + 1U & ~((int)(lastpos + 1U) >> 0x1f);
    uVar1 = sk_num(&x->stack);
    if ((int)uVar3 < (int)uVar1) {
      if (crit == 0) {
        do {
          pvVar2 = sk_value(&x->stack,uVar3);
          if (*(int *)((int)pvVar2 + 4) < 1) {
            return uVar3;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 != uVar1);
      }
      else {
        do {
          pvVar2 = sk_value(&x->stack,uVar3);
          if (0 < *(int *)((int)pvVar2 + 4)) {
            return uVar3;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 != uVar1);
      }
    }
  }
  return -1;
}


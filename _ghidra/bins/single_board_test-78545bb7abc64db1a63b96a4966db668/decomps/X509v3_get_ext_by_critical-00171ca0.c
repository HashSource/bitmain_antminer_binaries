
int X509v3_get_ext_by_critical(stack_st_X509_EXTENSION *x,int crit,int lastpos)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (x == (stack_st_X509_EXTENSION *)0x0) {
    return -1;
  }
  uVar3 = lastpos + 1U & ~((int)(lastpos + 1U) >> 0x1f);
  uVar1 = OPENSSL_sk_num();
  if ((int)uVar3 < (int)uVar1) {
    if (crit == 0) {
      do {
        iVar2 = OPENSSL_sk_value(x,uVar3);
        if (*(int *)(iVar2 + 4) < 1) {
          return uVar3;
        }
        uVar3 = uVar3 + 1;
      } while (uVar1 != uVar3);
    }
    else {
      do {
        iVar2 = OPENSSL_sk_value(x,uVar3);
        if (0 < *(int *)(iVar2 + 4)) {
          return uVar3;
        }
        uVar3 = uVar3 + 1;
      } while (uVar1 != uVar3);
    }
  }
  return -1;
}



int X509_PURPOSE_set(int *p,int purpose)

{
  int iVar1;
  int local_2c [8];
  
  if ((8 < purpose - 1U) &&
     (((local_2c[0] = purpose, *DAT_000cba04 == (_STACK *)0x0 ||
       (iVar1 = sk_find(*DAT_000cba04,local_2c), iVar1 == -1)) || (iVar1 == -10)))) {
    ERR_put_error(0x22,0x8d,0x92,DAT_000cba08,0x94);
    return 0;
  }
  *p = purpose;
  return 1;
}


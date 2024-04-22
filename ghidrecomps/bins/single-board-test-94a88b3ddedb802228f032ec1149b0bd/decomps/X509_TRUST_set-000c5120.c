
int X509_TRUST_set(int *t,int trust)

{
  int iVar1;
  int local_28 [7];
  
  if ((7 < trust - 1U) &&
     (((local_28[0] = trust, *DAT_000c5160 == (_STACK *)0x0 ||
       (iVar1 = sk_find(*DAT_000c5160,local_28), iVar1 == -1)) || (iVar1 == -9)))) {
    ERR_put_error(0xb,0x8d,0x7b,DAT_000c5164,0xab);
    return 0;
  }
  *t = trust;
  return 1;
}


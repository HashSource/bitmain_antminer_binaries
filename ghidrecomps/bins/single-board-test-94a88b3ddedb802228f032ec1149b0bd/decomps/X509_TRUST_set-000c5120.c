
int X509_TRUST_set(int *t,int trust)

{
  int iVar1;
  int local_28 [7];
  
  if ((7 < trust - 1U) &&
     (((local_28[0] = trust, trtable == (_STACK *)0x0 ||
       (iVar1 = sk_find(trtable,local_28), iVar1 == -1)) || (iVar1 == -9)))) {
    ERR_put_error(0xb,0x8d,0x7b,"x509_trs.c",0xab);
    return 0;
  }
  *t = trust;
  return 1;
}



int DSA_sign(int type,uchar *dgst,int dlen,uchar *sig,uint *siglen,DSA *dsa)

{
  DSA_SIG *a;
  uint uVar1;
  uchar *local_14;
  
  local_14 = sig;
  RAND_seed(dgst,dlen);
  a = DSA_do_sign(dgst,dlen,dsa);
  if (a == (DSA_SIG *)0x0) {
    *siglen = 0;
  }
  else {
    uVar1 = ASN1_item_i2d((ASN1_VALUE *)a,&local_14,DAT_000a4884);
    *siglen = uVar1;
    DSA_SIG_free(a);
  }
  return (uint)(a != (DSA_SIG *)0x0);
}


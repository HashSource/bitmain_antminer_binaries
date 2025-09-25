
int DSA_sign(int type,uchar *dgst,int dlen,uchar *sig,uint *siglen,DSA *dsa)

{
  DSA_SIG *a;
  uint uVar1;
  uchar *local_c;
  
  local_c = sig;
  a = DSA_do_sign(dgst,dlen,dsa);
  if (a != (DSA_SIG *)0x0) {
    uVar1 = i2d_DSA_SIG(a,&local_c);
    *siglen = uVar1;
    DSA_SIG_free(a);
    return 1;
  }
  *siglen = 0;
  return 0;
}


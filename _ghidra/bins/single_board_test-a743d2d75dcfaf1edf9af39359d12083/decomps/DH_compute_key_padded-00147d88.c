
int DH_compute_key_padded(uchar *key,BIGNUM *pub_key,DH *dh)

{
  size_t __n;
  int iVar1;
  size_t sVar2;
  size_t __n_00;
  int iVar3;
  
  __n = (*dh->meth->compute_key)(key,pub_key,dh);
  sVar2 = __n;
  if (0 < (int)__n) {
    iVar1 = BN_num_bits(dh->p);
    iVar3 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar3 = iVar1 + 7;
    }
    sVar2 = iVar3 >> 3;
    __n_00 = sVar2 - __n;
    if (0 < (int)__n_00) {
      memmove(key + __n_00,key,__n);
      memset(key,0,__n_00);
    }
  }
  return sVar2;
}


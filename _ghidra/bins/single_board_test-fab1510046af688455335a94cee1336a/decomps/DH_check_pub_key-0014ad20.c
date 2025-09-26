
int DH_check_pub_key(DH *dh,BIGNUM *pub_key,int *codes)

{
  BIGNUM *a;
  int iVar1;
  BIGNUM *b;
  
  *codes = 0;
  a = BN_new();
  if (a == (BIGNUM *)0x0) {
    return 0;
  }
  BN_set_word(a,1);
  iVar1 = BN_cmp(pub_key,a);
  b = dh->p;
  if (iVar1 < 1) {
    *codes = *codes | 1;
  }
  BN_copy(a,b);
  BN_sub_word(a,1);
  iVar1 = BN_cmp(pub_key,a);
  if (-1 < iVar1) {
    *codes = *codes | 2;
  }
  BN_free(a);
  return 1;
}


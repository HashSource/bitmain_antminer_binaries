
int BN_lshift(BIGNUM *r,BIGNUM *a,int n)

{
  int iVar1;
  
  if (-1 < n) {
    iVar1 = bn_lshift_fixed_top();
    bn_correct_top(r);
    return iVar1;
  }
  ERR_put_error(3,0x91,0x77,"crypto/bn/bn_shift.c",0x56);
  return 0;
}


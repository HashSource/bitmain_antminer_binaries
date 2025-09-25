
bool ec_key_simple_oct2priv(int param_1,uchar *param_2,int param_3)

{
  BIGNUM *pBVar1;
  
  pBVar1 = *(BIGNUM **)(param_1 + 0x14);
  if (pBVar1 == (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)BN_secure_new();
    *(BIGNUM **)(param_1 + 0x14) = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) {
      ERR_put_error(0x10,0x103,0x41,"crypto/ec/ec_key.c",0x29b);
      return false;
    }
  }
  pBVar1 = BN_bin2bn(param_2,param_3,pBVar1);
  if (pBVar1 == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0x103,3,"crypto/ec/ec_key.c",0x29f);
  }
  return pBVar1 != (BIGNUM *)0x0;
}


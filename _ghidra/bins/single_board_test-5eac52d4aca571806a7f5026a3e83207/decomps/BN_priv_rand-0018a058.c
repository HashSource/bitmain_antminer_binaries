
BIGNUM * BN_priv_rand(BIGNUM *param_1,int param_2,int param_3,int param_4)

{
  int num;
  byte *s;
  int iVar1;
  BIGNUM *pBVar2;
  byte bVar3;
  uint uVar4;
  
  if (param_2 == 0) {
    if (param_4 == 0 && param_3 == -1) {
      BN_set_word(param_1,0);
      return (BIGNUM *)0x1;
    }
  }
  else if ((-1 < param_2) && (param_3 < 1 || param_2 != 1)) {
    num = param_2 + 7 >> 3;
    uVar4 = param_2 - 1U & 7;
    s = (byte *)CRYPTO_malloc(num,"crypto/bn/bn_rand.c",0x27);
    if (s == (byte *)0x0) {
      ERR_put_error(3,0x7f,0x41,"crypto/bn/bn_rand.c",0x29);
      pBVar2 = (BIGNUM *)0x0;
    }
    else {
      iVar1 = RAND_priv_bytes(s,num);
      pBVar2 = (BIGNUM *)0x0;
      if (0 < iVar1) {
        if (param_3 < 0) {
          bVar3 = *s;
        }
        else if (param_3 == 0) {
          bVar3 = (byte)(1 << uVar4) | *s;
        }
        else if (uVar4 == 0) {
          bVar3 = 1;
          s[1] = s[1] | 0x80;
        }
        else {
          bVar3 = *s | (byte)(3 << (uVar4 - 1 & 0xff));
        }
        *s = bVar3 & ~(byte)(0xff << uVar4 + 1);
        if (param_4 != 0) {
          s[num + -1] = s[num + -1] | 1;
        }
        pBVar2 = BN_bin2bn(s,num,param_1);
        if (pBVar2 != (BIGNUM *)0x0) {
          pBVar2 = (BIGNUM *)0x1;
        }
      }
    }
    CRYPTO_clear_free(s,num,"crypto/bn/bn_rand.c",0x58);
    return pBVar2;
  }
  ERR_put_error(3,0x7f,0x76,"crypto/bn/bn_rand.c",0x5d);
  return (BIGNUM *)0x0;
}



EC_POINT * EC_POINT_bn2point(EC_GROUP *param_1,BIGNUM *param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  int iVar1;
  uchar *buf;
  int iVar2;
  size_t len;
  
  iVar1 = BN_num_bits(param_2);
  iVar2 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar2 = iVar1 + 7;
  }
  len = iVar2 >> 3;
  if (len == 0) {
    len = 1;
  }
  buf = (uchar *)CRYPTO_malloc(len,"crypto/ec/ec_print.c",0x2b);
  if (buf == (uchar *)0x0) {
    ERR_put_error(0x10,0x118,0x41,"crypto/ec/ec_print.c",0x2c);
    param_3 = (EC_POINT *)0x0;
  }
  else {
    iVar2 = BN_bn2binpad(param_2,buf,len);
    if (iVar2 == 0) {
      CRYPTO_free(buf);
      param_3 = (EC_POINT *)0x0;
    }
    else {
      if (param_3 == (EC_POINT *)0x0) {
        param_3 = EC_POINT_new(param_1);
        if (param_3 == (EC_POINT *)0x0) {
          CRYPTO_free(buf);
          return (EC_POINT *)0x0;
        }
        iVar2 = EC_POINT_oct2point(param_1,param_3,buf,len,param_4);
        if (iVar2 == 0) {
          EC_POINT_clear_free(param_3);
          goto LAB_001ad8c6;
        }
      }
      else {
        iVar2 = EC_POINT_oct2point(param_1,param_3,buf,len,param_4);
        if (iVar2 == 0) {
LAB_001ad8c6:
          CRYPTO_free(buf);
          return (EC_POINT *)0x0;
        }
      }
      CRYPTO_free(buf);
    }
  }
  return param_3;
}


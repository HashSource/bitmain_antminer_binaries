
BIGNUM * srp_Calc_xy(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3)

{
  int iVar1;
  int iVar2;
  void *data;
  EVP_MD *type;
  BIGNUM *pBVar3;
  uchar auStack_2c [20];
  
  iVar1 = BN_num_bits(param_3);
  if (((param_3 != param_1) && (iVar2 = BN_ucmp(param_1,param_3), -1 < iVar2)) ||
     ((param_3 != param_2 && (iVar2 = BN_ucmp(param_2,param_3), -1 < iVar2)))) {
    return (BIGNUM *)0x0;
  }
  iVar2 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar2 = iVar1 + 7;
  }
  iVar2 = iVar2 >> 3;
  data = CRYPTO_malloc(iVar2 << 1,"crypto/srp/srp_lib.c",0x22);
  if (((data != (void *)0x0) && (iVar1 = BN_bn2binpad(param_1,data,iVar2), -1 < iVar1)) &&
     (iVar1 = BN_bn2binpad(param_2,(int)data + iVar2,iVar2), -1 < iVar1)) {
    type = EVP_sha1();
    iVar1 = EVP_Digest(data,iVar2 << 1,auStack_2c,(uint *)0x0,type,(ENGINE *)0x0);
    if (iVar1 != 0) {
      pBVar3 = BN_bin2bn(auStack_2c,0x14,(BIGNUM *)0x0);
      goto LAB_0016250c;
    }
  }
  pBVar3 = (BIGNUM *)0x0;
LAB_0016250c:
  CRYPTO_free(data);
  return pBVar3;
}


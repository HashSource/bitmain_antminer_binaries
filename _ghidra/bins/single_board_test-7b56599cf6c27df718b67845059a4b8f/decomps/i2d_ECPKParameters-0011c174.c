
int i2d_ECPKParameters(EC_GROUP *param_1,uchar **out)

{
  int iVar1;
  int iVar2;
  
  iVar1 = EC_GROUP_get_ecpkparameters(param_1,0);
  if (iVar1 == 0) {
    ERR_put_error(0x10,0xbf,0x78,"crypto/ec/ec_asn1.c",0x3de);
    return 0;
  }
  iVar2 = i2d_ECPKPARAMETERS(iVar1,out);
  if (iVar2 != 0) {
    ECPKPARAMETERS_free(iVar1);
    return iVar2;
  }
  ERR_put_error(0x10,0xbf,0x79,"crypto/ec/ec_asn1.c",0x3e2);
  ECPKPARAMETERS_free(iVar1);
  return 0;
}


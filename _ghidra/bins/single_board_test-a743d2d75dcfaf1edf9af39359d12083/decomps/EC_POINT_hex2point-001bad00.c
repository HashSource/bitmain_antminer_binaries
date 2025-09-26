
EC_POINT * EC_POINT_hex2point(EC_GROUP *param_1,char *param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  int iVar1;
  EC_POINT *pEVar2;
  BIGNUM *local_14;
  
  local_14 = (BIGNUM *)0x0;
  iVar1 = BN_hex2bn(&local_14,param_2);
  if (iVar1 == 0) {
    pEVar2 = (EC_POINT *)0x0;
  }
  else {
    pEVar2 = EC_POINT_bn2point(param_1,local_14,param_3,param_4);
    BN_clear_free(local_14);
  }
  return pEVar2;
}


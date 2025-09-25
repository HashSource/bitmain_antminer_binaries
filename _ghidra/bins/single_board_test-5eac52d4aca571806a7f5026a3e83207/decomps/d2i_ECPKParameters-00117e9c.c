
EC_GROUP * d2i_ECPKParameters(EC_GROUP **param_1,uchar **in,long len)

{
  int *piVar1;
  EC_GROUP *pEVar2;
  uchar *local_1c [2];
  
  local_1c[0] = *in;
  piVar1 = (int *)d2i_ECPKPARAMETERS(0,local_1c);
  if (piVar1 == (int *)0x0) {
    ERR_put_error(0x10,0x91,0x75,"crypto/ec/ec_asn1.c",0x3c1);
    ECPKPARAMETERS_free(0);
    pEVar2 = (EC_GROUP *)0x0;
  }
  else {
    pEVar2 = (EC_GROUP *)EC_GROUP_new_from_ecpkparameters();
    if (pEVar2 == (EC_GROUP *)0x0) {
      ERR_put_error(0x10,0x91,0x7f,"crypto/ec/ec_asn1.c",0x3c7);
      ECPKPARAMETERS_free(piVar1);
    }
    else {
      if (*piVar1 == 1) {
        *(undefined4 *)(pEVar2 + 0x18) = 1;
      }
      if (param_1 != (EC_GROUP **)0x0) {
        EC_GROUP_free(*param_1);
        *param_1 = pEVar2;
      }
      ECPKPARAMETERS_free(piVar1);
      *in = local_1c[0];
    }
  }
  return pEVar2;
}



void priv_encode_gost(PKCS8_PRIV_KEY_INFO *param_1,EVP_PKEY *param_2)

{
  int iVar1;
  ASN1_OBJECT *aobj;
  void *pval;
  ASN1_INTEGER *a;
  BIGNUM *bn;
  uchar *local_1c;
  
  bn = (BIGNUM *)0x0;
  iVar1 = EVP_PKEY_base_id(param_2);
  aobj = OBJ_nid2obj(iVar1);
  pval = (void *)encode_gost_algor_params(param_2);
  local_1c = (uchar *)0x0;
  if (pval != (void *)0x0) {
    iVar1 = EVP_PKEY_base_id(param_2);
    if (iVar1 == 0x32b) {
      bn = (BIGNUM *)EVP_PKEY_get0(param_2);
      if (bn != (BIGNUM *)0x0) {
        bn = EC_KEY_get0_private_key((EC_KEY *)bn);
      }
    }
    else if ((iVar1 == 0x32c) && (bn = (BIGNUM *)EVP_PKEY_get0(param_2), bn != (BIGNUM *)0x0)) {
      bn = (BIGNUM *)bn[1].dmax;
    }
    a = BN_to_ASN1_INTEGER(bn,(ASN1_INTEGER *)0x0);
    iVar1 = i2d_ASN1_INTEGER(a,&local_1c);
    ASN1_INTEGER_free(a);
    PKCS8_pkey_set0(param_1,aobj,0,0x10,pval,local_1c,iVar1);
  }
  return;
}


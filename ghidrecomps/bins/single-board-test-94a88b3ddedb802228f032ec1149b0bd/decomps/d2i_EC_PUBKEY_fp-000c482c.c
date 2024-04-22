
EC_KEY * d2i_EC_PUBKEY_fp(FILE *fp,EC_KEY **eckey)

{
  EC_KEY *pEVar1;
  
  pEVar1 = (EC_KEY *)ASN1_d2i_fp(EC_KEY_new + 1,d2i_EC_PUBKEY + 1,fp,eckey);
  return pEVar1;
}


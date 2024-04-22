
EC_KEY * PEM_read_EC_PUBKEY(FILE *fp,EC_KEY **x,undefined1 *cb,void *u)

{
  EC_KEY *pEVar1;
  
  pEVar1 = (EC_KEY *)PEM_ASN1_read(d2i_EC_PUBKEY + 1,"PUBLIC KEY",fp,x,cb,u);
  return pEVar1;
}


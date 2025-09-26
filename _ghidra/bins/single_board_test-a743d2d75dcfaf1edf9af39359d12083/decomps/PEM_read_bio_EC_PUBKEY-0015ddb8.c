
EC_KEY * PEM_read_bio_EC_PUBKEY(BIO *bp,EC_KEY **x,undefined1 *cb,void *u)

{
  EC_KEY *pEVar1;
  
  pEVar1 = (EC_KEY *)PEM_ASN1_read_bio((undefined1 *)0x156d75,"PUBLIC KEY",bp,x,cb,u);
  return pEVar1;
}


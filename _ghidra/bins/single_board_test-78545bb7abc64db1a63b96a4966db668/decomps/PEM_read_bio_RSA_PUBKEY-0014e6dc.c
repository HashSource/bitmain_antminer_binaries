
RSA * PEM_read_bio_RSA_PUBKEY(BIO *bp,RSA **x,undefined1 *cb,void *u)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)PEM_ASN1_read_bio((undefined1 *)0x177c91,"PUBLIC KEY",bp,x,cb,u);
  return pRVar1;
}


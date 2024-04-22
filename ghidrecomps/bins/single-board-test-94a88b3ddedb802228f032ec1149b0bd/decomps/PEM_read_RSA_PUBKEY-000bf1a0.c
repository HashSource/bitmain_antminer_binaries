
RSA * PEM_read_RSA_PUBKEY(FILE *fp,RSA **x,undefined1 *cb,void *u)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)PEM_ASN1_read(d2i_RSA_PUBKEY + 1,"PUBLIC KEY",fp,x,cb,u);
  return pRVar1;
}


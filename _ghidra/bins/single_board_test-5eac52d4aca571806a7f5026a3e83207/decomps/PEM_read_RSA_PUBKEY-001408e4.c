
RSA * PEM_read_RSA_PUBKEY(FILE *fp,RSA **x,undefined1 *cb,void *u)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)PEM_ASN1_read((undefined1 *)0x169e69,"PUBLIC KEY",fp,x,cb,u);
  return pRVar1;
}


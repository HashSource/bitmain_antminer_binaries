
int PEM_write_RSA_PUBKEY(FILE *fp,RSA *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write((undefined1 *)0x177cd5,"PUBLIC KEY",fp,x,(EVP_CIPHER *)0x0,(uchar *)0x0,0,
                         (undefined1 *)0x0,(void *)0x0);
  return iVar1;
}


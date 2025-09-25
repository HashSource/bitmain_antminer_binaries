
int PEM_write_ECPKParameters(FILE *fp,EC_GROUP *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write((undefined1 *)0x117f25,"EC PARAMETERS",fp,x,(EVP_CIPHER *)0x0,(uchar *)0x0,
                         0,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}


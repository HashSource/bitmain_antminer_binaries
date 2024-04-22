
int i2d_PBKDF2PARAM(PBKDF2PARAM *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bd4dc);
  return iVar1;
}


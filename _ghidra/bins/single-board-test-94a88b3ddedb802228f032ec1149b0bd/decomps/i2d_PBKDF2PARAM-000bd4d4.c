
int i2d_PBKDF2PARAM(PBKDF2PARAM *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PBKDF2PARAM_it);
  return iVar1;
}


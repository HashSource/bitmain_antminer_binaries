
int i2d_AUTHORITY_KEYID(AUTHORITY_KEYID *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&AUTHORITY_KEYID_it);
  return iVar1;
}


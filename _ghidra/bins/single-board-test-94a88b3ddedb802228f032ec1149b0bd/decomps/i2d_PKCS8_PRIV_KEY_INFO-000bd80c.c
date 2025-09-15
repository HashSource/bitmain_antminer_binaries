
int i2d_PKCS8_PRIV_KEY_INFO(PKCS8_PRIV_KEY_INFO *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&PKCS8_PRIV_KEY_INFO_it);
  return iVar1;
}


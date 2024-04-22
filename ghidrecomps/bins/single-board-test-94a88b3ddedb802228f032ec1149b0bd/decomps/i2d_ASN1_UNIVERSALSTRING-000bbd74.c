
int i2d_ASN1_UNIVERSALSTRING(ASN1_UNIVERSALSTRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbd7c);
  return iVar1;
}


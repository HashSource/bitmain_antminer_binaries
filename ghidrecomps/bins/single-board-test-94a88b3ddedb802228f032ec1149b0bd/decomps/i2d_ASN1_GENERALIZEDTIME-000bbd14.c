
int i2d_ASN1_GENERALIZEDTIME(ASN1_GENERALIZEDTIME *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbd1c);
  return iVar1;
}


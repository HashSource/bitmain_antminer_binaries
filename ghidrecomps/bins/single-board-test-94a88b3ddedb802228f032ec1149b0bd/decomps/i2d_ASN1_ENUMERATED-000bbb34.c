
int i2d_ASN1_ENUMERATED(ASN1_ENUMERATED *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbb3c);
  return iVar1;
}



int i2d_NOTICEREF(NOTICEREF *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000ca59c);
  return iVar1;
}


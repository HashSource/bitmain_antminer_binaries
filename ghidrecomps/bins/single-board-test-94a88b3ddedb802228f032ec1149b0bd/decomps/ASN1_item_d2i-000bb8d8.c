
ASN1_VALUE * ASN1_item_d2i(ASN1_VALUE **val,uchar **in,long len,ASN1_ITEM *it)

{
  int iVar1;
  ASN1_VALUE *pAVar2;
  ASN1_VALUE *local_34;
  ASN1_TLC local_30;
  
  local_34 = (ASN1_VALUE *)0x0;
  if (val == (ASN1_VALUE **)0x0) {
    val = &local_34;
  }
  local_30.valid = '\0';
  iVar1 = ASN1_item_ex_d2i(val,in,len,it,-1,0,'\0',&local_30);
  if (iVar1 < 1) {
    pAVar2 = (ASN1_VALUE *)0x0;
  }
  else {
    pAVar2 = *val;
  }
  return pAVar2;
}


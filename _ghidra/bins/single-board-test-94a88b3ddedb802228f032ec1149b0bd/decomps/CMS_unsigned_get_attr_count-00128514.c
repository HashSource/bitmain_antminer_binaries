
int CMS_unsigned_get_attr_count(CMS_SignerInfo *si)

{
  int iVar1;
  
  iVar1 = X509at_get_attr_count(*(_STACK **)(si + 0x18));
  return iVar1;
}


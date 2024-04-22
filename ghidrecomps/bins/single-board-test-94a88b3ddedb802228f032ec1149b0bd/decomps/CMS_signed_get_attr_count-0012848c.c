
int CMS_signed_get_attr_count(CMS_SignerInfo *si)

{
  int iVar1;
  
  iVar1 = X509at_get_attr_count(*(_STACK **)(si + 0xc));
  return iVar1;
}


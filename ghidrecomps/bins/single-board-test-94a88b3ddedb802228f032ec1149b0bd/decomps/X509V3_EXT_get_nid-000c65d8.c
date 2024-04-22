
X509V3_EXT_METHOD * X509V3_EXT_get_nid(int nid)

{
  _STACK **pp_Var1;
  X509V3_EXT_METHOD **ppXVar2;
  int iVar3;
  X509V3_EXT_METHOD *pXVar4;
  int *local_4c;
  int local_48 [14];
  
  if (-1 < nid) {
    local_4c = local_48;
    local_48[0] = nid;
    ppXVar2 = (X509V3_EXT_METHOD **)OBJ_bsearch_(&local_4c,DAT_000c6620,0x2a,4,DAT_000c661c);
    pp_Var1 = DAT_000c6624;
    if (ppXVar2 != (X509V3_EXT_METHOD **)0x0) {
      return *ppXVar2;
    }
    if ((*DAT_000c6624 != (_STACK *)0x0) && (iVar3 = sk_find(*DAT_000c6624,local_48), iVar3 != -1))
    {
      pXVar4 = (X509V3_EXT_METHOD *)sk_value(*pp_Var1,iVar3);
      return pXVar4;
    }
  }
  return (X509V3_EXT_METHOD *)0x0;
}


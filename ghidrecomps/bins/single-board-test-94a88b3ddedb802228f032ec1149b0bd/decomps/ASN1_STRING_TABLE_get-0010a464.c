
ASN1_STRING_TABLE * ASN1_STRING_TABLE_get(int nid)

{
  _STACK **pp_Var1;
  ASN1_STRING_TABLE *pAVar2;
  int iVar3;
  int local_24 [5];
  
  local_24[0] = nid;
  pAVar2 = (ASN1_STRING_TABLE *)OBJ_bsearch_(local_24,DAT_0010a4a8,0x13,0x14,DAT_0010a4a4);
  pp_Var1 = DAT_0010a4ac;
  if (pAVar2 == (ASN1_STRING_TABLE *)0x0) {
    if ((*DAT_0010a4ac != (_STACK *)0x0) && (iVar3 = sk_find(*DAT_0010a4ac,local_24), -1 < iVar3)) {
      pAVar2 = (ASN1_STRING_TABLE *)sk_value(*pp_Var1,iVar3);
    }
  }
  return pAVar2;
}


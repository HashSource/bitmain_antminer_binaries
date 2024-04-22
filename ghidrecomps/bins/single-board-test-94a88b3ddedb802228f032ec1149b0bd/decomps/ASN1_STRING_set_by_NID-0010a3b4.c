
ASN1_STRING * ASN1_STRING_set_by_NID(ASN1_STRING **out,uchar *in,int inlen,int inform,int nid)

{
  _STACK **pp_Var1;
  void *pvVar2;
  ulong mask;
  int iVar3;
  ASN1_STRING *pAVar4;
  ASN1_STRING *local_38;
  int local_34 [6];
  
  local_38 = (ASN1_STRING *)0x0;
  if (out == (ASN1_STRING **)0x0) {
    out = &local_38;
  }
  local_34[0] = nid;
  pvVar2 = OBJ_bsearch_(local_34,DAT_0010a458,0x13,0x14,DAT_0010a454);
  pp_Var1 = DAT_0010a460;
  if ((pvVar2 == (void *)0x0) &&
     (((*DAT_0010a460 == (_STACK *)0x0 || (iVar3 = sk_find(*DAT_0010a460,local_34), iVar3 < 0)) ||
      (pvVar2 = sk_value(*pp_Var1,iVar3), pvVar2 == (void *)0x0)))) {
    iVar3 = ASN1_mbstring_copy(out,in,inlen,inform,*DAT_0010a45c & 0x2806);
  }
  else {
    mask = *(uint *)((int)pvVar2 + 0xc);
    if (-1 < *(int *)((int)pvVar2 + 0x10) << 0x1e) {
      mask = mask & *DAT_0010a45c;
    }
    iVar3 = ASN1_mbstring_ncopy(out,in,inlen,inform,mask,*(long *)((int)pvVar2 + 4),
                                *(long *)((int)pvVar2 + 8));
  }
  if (iVar3 < 1) {
    pAVar4 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar4 = *out;
  }
  return pAVar4;
}


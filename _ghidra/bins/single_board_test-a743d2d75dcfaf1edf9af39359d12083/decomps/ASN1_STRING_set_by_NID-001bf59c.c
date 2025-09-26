
ASN1_STRING * ASN1_STRING_set_by_NID(ASN1_STRING **out,uchar *in,int inlen,int inform,int nid)

{
  void *pvVar1;
  ulong mask;
  int iVar2;
  ASN1_STRING *pAVar3;
  ASN1_STRING *local_38;
  int local_34 [6];
  
  local_38 = (ASN1_STRING *)0x0;
  if (out == (ASN1_STRING **)0x0) {
    out = &local_38;
  }
  local_34[0] = nid;
  pvVar1 = OBJ_bsearch_(local_34,&tbl_standard,0x13,0x14,(cmp *)0x1bf4dd);
  if ((pvVar1 == (void *)0x0) &&
     (((stable == (_STACK *)0x0 || (iVar2 = sk_find(stable,local_34), iVar2 < 0)) ||
      (pvVar1 = sk_value(stable,iVar2), pvVar1 == (void *)0x0)))) {
    iVar2 = ASN1_mbstring_copy(out,in,inlen,inform,global_mask & 0x2806);
  }
  else {
    mask = *(uint *)((int)pvVar1 + 0xc);
    if (-1 < *(int *)((int)pvVar1 + 0x10) << 0x1e) {
      mask = mask & global_mask;
    }
    iVar2 = ASN1_mbstring_ncopy(out,in,inlen,inform,mask,*(long *)((int)pvVar1 + 4),
                                *(long *)((int)pvVar1 + 8));
  }
  if (iVar2 < 1) {
    pAVar3 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar3 = *out;
  }
  return pAVar3;
}


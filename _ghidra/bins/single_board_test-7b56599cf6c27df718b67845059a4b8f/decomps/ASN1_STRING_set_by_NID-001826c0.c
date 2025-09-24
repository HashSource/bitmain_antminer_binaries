
ASN1_STRING * ASN1_STRING_set_by_NID(ASN1_STRING **out,uchar *in,int inlen,int inform,int nid)

{
  ASN1_STRING_TABLE *pAVar1;
  int iVar2;
  ASN1_STRING *pAVar3;
  ASN1_STRING **out_00;
  ulong mask;
  ASN1_STRING *local_24;
  
  local_24 = (ASN1_STRING *)0x0;
  out_00 = &local_24;
  if (out != (ASN1_STRING **)0x0) {
    out_00 = out;
  }
  pAVar1 = ASN1_STRING_TABLE_get(nid);
  if (pAVar1 == (ASN1_STRING_TABLE *)0x0) {
    iVar2 = ASN1_mbstring_copy(out_00,in,inlen,inform,global_mask & 0x2806);
  }
  else {
    mask = pAVar1->mask;
    if (-1 < (int)(pAVar1->flags << 0x1e)) {
      mask = mask & global_mask;
    }
    iVar2 = ASN1_mbstring_ncopy(out_00,in,inlen,inform,mask,pAVar1->minsize,pAVar1->maxsize);
  }
  if (iVar2 < 1) {
    pAVar3 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar3 = *out_00;
  }
  return pAVar3;
}


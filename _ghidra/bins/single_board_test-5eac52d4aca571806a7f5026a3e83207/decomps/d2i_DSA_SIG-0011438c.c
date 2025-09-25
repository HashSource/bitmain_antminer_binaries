
DSA_SIG * d2i_DSA_SIG(DSA_SIG **v,uchar **pp,long length)

{
  DSA_SIG *pDVar1;
  
  pDVar1 = (DSA_SIG *)ASN1_item_d2i((ASN1_VALUE **)v,pp,length,(ASN1_ITEM *)&DSA_SIG_it);
  return pDVar1;
}


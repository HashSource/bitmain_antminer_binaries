
ECDSA_SIG * d2i_ECDSA_SIG(ECDSA_SIG **sig,uchar **pp,long len)

{
  ECDSA_SIG *pEVar1;
  
  pEVar1 = (ECDSA_SIG *)ASN1_item_d2i((ASN1_VALUE **)sig,pp,len,(ASN1_ITEM *)&ECDSA_SIG_it);
  return pEVar1;
}


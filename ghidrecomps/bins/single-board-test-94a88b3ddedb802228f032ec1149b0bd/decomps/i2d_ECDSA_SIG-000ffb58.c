
int i2d_ECDSA_SIG(ECDSA_SIG *sig,uchar **pp)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)sig,pp,(ASN1_ITEM *)&ECDSA_SIG_it);
  return iVar1;
}


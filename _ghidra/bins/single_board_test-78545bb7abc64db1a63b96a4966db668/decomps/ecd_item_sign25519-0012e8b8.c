
undefined4 ecd_item_sign25519(void)

{
  ASN1_OBJECT *pAVar1;
  X509_ALGOR *in_r3;
  X509_ALGOR *in_stack_00000000;
  
  pAVar1 = OBJ_nid2obj(0x43f);
  X509_ALGOR_set0(in_r3,pAVar1,-1,(void *)0x0);
  if (in_stack_00000000 != (X509_ALGOR *)0x0) {
    pAVar1 = OBJ_nid2obj(0x43f);
    X509_ALGOR_set0(in_stack_00000000,pAVar1,-1,(void *)0x0);
  }
  return 3;
}


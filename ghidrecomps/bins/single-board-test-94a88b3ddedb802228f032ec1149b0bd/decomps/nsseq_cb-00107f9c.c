
undefined4 nsseq_cb(int param_1,undefined4 *param_2)

{
  ASN1_OBJECT *pAVar1;
  ASN1_OBJECT **ppAVar2;
  
  if (param_1 != 1) {
    return 1;
  }
  ppAVar2 = (ASN1_OBJECT **)*param_2;
  pAVar1 = OBJ_nid2obj(0x4f);
  *ppAVar2 = pAVar1;
  return 1;
}



undefined4 add_attribute(int *param_1,int param_2,int param_3,void *param_4)

{
  int iVar1;
  ASN1_OBJECT *o;
  X509_ATTRIBUTE *pXVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar1 = OPENSSL_sk_new_null();
    *param_1 = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    for (iVar3 = 0; iVar1 = OPENSSL_sk_num(iVar1), iVar3 < iVar1; iVar3 = iVar3 + 1) {
      pXVar2 = (X509_ATTRIBUTE *)OPENSSL_sk_value(*param_1,iVar3);
      o = X509_ATTRIBUTE_get0_object(pXVar2);
      iVar1 = OBJ_obj2nid(o);
      if (iVar1 == param_2) {
        X509_ATTRIBUTE_free(pXVar2);
        pXVar2 = X509_ATTRIBUTE_create(param_2,param_3,param_4);
        if (pXVar2 == (X509_ATTRIBUTE *)0x0) {
          return 0;
        }
        iVar1 = OPENSSL_sk_set(*param_1,iVar3,pXVar2);
        goto joined_r0x00147786;
      }
      iVar1 = *param_1;
    }
  }
  pXVar2 = X509_ATTRIBUTE_create(param_2,param_3,param_4);
  if (pXVar2 == (X509_ATTRIBUTE *)0x0) {
    return 0;
  }
  iVar1 = OPENSSL_sk_push(*param_1,pXVar2);
joined_r0x00147786:
  if (iVar1 == 0) {
    X509_ATTRIBUTE_free(pXVar2);
    return 0;
  }
  return 1;
}


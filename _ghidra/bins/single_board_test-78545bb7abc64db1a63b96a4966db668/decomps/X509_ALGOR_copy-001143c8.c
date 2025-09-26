
int X509_ALGOR_copy(undefined4 *param_1,undefined4 *param_2)

{
  ASN1_OBJECT *pAVar1;
  ASN1_TYPE *a;
  int iVar2;
  
  if (param_1 == (undefined4 *)0x0 || param_2 == (undefined4 *)0x0) {
    return 0;
  }
  if ((ASN1_OBJECT *)*param_1 != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free((ASN1_OBJECT *)*param_1);
  }
  *param_1 = 0;
  if ((ASN1_TYPE *)param_1[1] != (ASN1_TYPE *)0x0) {
    ASN1_TYPE_free((ASN1_TYPE *)param_1[1]);
  }
  pAVar1 = (ASN1_OBJECT *)*param_2;
  param_1[1] = 0;
  if (pAVar1 != (ASN1_OBJECT *)0x0) {
    pAVar1 = OBJ_dup(pAVar1);
    *param_1 = pAVar1;
    if (pAVar1 == (ASN1_OBJECT *)0x0) {
      return 0;
    }
  }
  if (param_2[1] != 0) {
    a = ASN1_TYPE_new();
    param_1[1] = a;
    if (a == (ASN1_TYPE *)0x0) {
      return 0;
    }
    iVar2 = ASN1_TYPE_set1(a,*(int *)param_2[1],(void *)((int *)param_2[1])[1]);
    if (iVar2 != 0) {
      iVar2 = 1;
    }
    return iVar2;
  }
  return 1;
}



undefined4 make_addressPrefix(undefined4 *param_1,void *param_2,uint param_3,int param_4)

{
  IPAddressOrRange *a;
  ASN1_STRING *str;
  int iVar1;
  ASN1_BIT_STRING *pAVar2;
  int iVar3;
  
  a = IPAddressOrRange_new();
  if (((int)param_3 < 0) ||
     (a == (IPAddressOrRange *)0x0 ||
      param_3 != param_4 * 8 && (int)(param_3 + param_4 * -8) < 0 == SBORROW4(param_3,param_4 * 8)))
  {
    return 0;
  }
  str = (a->u).addressPrefix;
  a->type = 0;
  if (str == (ASN1_BIT_STRING *)0x0) {
    str = ASN1_BIT_STRING_new();
    (a->u).addressPrefix = str;
    if (str == (ASN1_BIT_STRING *)0x0) goto LAB_0017a00a;
  }
  iVar3 = (int)(param_3 + 7) >> 3;
  iVar1 = ASN1_BIT_STRING_set(str,param_2,iVar3);
  if (iVar1 != 0) {
    pAVar2 = (a->u).addressPrefix;
    param_3 = param_3 & 7;
    pAVar2->flags = pAVar2->flags & 0xfffffff8U | 8;
    if (param_3 != 0) {
      iVar3 = iVar3 + -1;
      pAVar2->data[iVar3] = pAVar2->data[iVar3] & ~(byte)(0xff >> param_3);
      ((a->u).addressPrefix)->flags = 8 - param_3 | ((a->u).addressPrefix)->flags;
    }
    *param_1 = a;
    return 1;
  }
LAB_0017a00a:
  IPAddressOrRange_free(a);
  return 0;
}


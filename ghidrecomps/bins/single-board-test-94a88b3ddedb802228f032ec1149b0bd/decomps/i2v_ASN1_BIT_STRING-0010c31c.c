
stack_st_CONF_VALUE *
i2v_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,ASN1_BIT_STRING *bits,stack_st_CONF_VALUE *extlist)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  stack_st_CONF_VALUE *local_14 [2];
  
  local_14[0] = extlist;
  if (*(int *)((int)method->usr_data + 4) != 0) {
    iVar3 = (int)method->usr_data + 0xc;
    do {
      while( true ) {
        HintPreloadData(iVar3 + 0x4c);
        iVar2 = ASN1_BIT_STRING_get_bit(bits,*(int *)(iVar3 + -0xc));
        if (iVar2 == 0) break;
        X509V3_add_value(*(char **)(iVar3 + -8),(char *)0x0,local_14);
        piVar1 = (int *)(iVar3 + 4);
        iVar3 = iVar3 + 0xc;
        if (*piVar1 == 0) {
          return local_14[0];
        }
      }
      piVar1 = (int *)(iVar3 + 4);
      iVar3 = iVar3 + 0xc;
    } while (*piVar1 != 0);
  }
  return local_14[0];
}



undefined4 X509V3_EXT_free(int param_1,ASN1_VALUE *param_2)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int *local_54;
  int local_50 [15];
  
  local_54 = local_50;
  if (-1 < param_1) {
    local_50[0] = param_1;
    piVar1 = (int *)OBJ_bsearch_(&local_54,&standard_exts,0x2a,4,(cmp *)0x1671fd);
    if (piVar1 == (int *)0x0) {
      if ((ext_list == (_STACK *)0x0) || (iVar3 = sk_find(ext_list,local_50), iVar3 == -1))
      goto LAB_00167386;
      pvVar2 = sk_value(ext_list,iVar3);
    }
    else {
      pvVar2 = (void *)*piVar1;
    }
    if (pvVar2 != (void *)0x0) {
      if (*(ASN1_ITEM **)((int)pvVar2 + 8) != (ASN1_ITEM *)0x0) {
        ASN1_item_free(param_2,*(ASN1_ITEM **)((int)pvVar2 + 8));
        return 1;
      }
      if (*(code **)((int)pvVar2 + 0x10) != (code *)0x0) {
        (**(code **)((int)pvVar2 + 0x10))(param_2);
        return 1;
      }
      ERR_put_error(0x22,0xa5,0xa8,"v3_lib.c",0x8c);
      return 0;
    }
  }
LAB_00167386:
  ERR_put_error(0x22,0xa5,0xa8,"v3_lib.c",0x82);
  return 0;
}


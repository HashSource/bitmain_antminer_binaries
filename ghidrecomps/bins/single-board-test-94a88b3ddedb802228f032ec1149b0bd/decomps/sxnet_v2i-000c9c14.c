
undefined4 sxnet_v2i(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  int iVar1;
  void *pvVar2;
  ASN1_INTEGER *izone;
  int iVar3;
  char *user;
  SXNET *local_1c;
  
  local_1c = (SXNET *)0x0;
  iVar3 = 0;
  while( true ) {
    iVar1 = sk_num(param_3);
    if (iVar1 <= iVar3) {
      return local_1c;
    }
    pvVar2 = sk_value(param_3,iVar3);
    user = *(char **)((int)pvVar2 + 8);
    izone = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,*(char **)((int)pvVar2 + 4));
    if (izone == (ASN1_INTEGER *)0x0) break;
    iVar1 = SXNET_add_id_INTEGER(&local_1c,izone,user,-1);
    iVar3 = iVar3 + 1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  ERR_put_error(0x22,0x7d,0x83,DAT_000c9c7c,0x9d);
  return 0;
}



undefined4 sxnet_v2i(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  SXNET *local_14;
  
  local_14 = (SXNET *)0x0;
  iVar2 = 0;
  do {
    iVar1 = OPENSSL_sk_num(param_3);
    if (iVar1 <= iVar2) {
      return local_14;
    }
    iVar1 = OPENSSL_sk_value(param_3,iVar2);
    iVar1 = SXNET_add_id_asc(&local_14,*(char **)(iVar1 + 4),*(char **)(iVar1 + 8),-1);
    iVar2 = iVar2 + 1;
  } while (iVar1 != 0);
  return 0;
}


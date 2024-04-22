
EVP_PKEY_METHOD * EVP_PKEY_meth_find(int type)

{
  _STACK **pp_Var1;
  int iVar2;
  undefined4 *puVar3;
  int *local_78;
  int local_74 [27];
  
  pp_Var1 = DAT_000b3860;
  local_78 = local_74;
  local_74[0] = type;
  if ((*DAT_000b3860 == (_STACK *)0x0) || (iVar2 = sk_find(*DAT_000b3860,local_78), iVar2 < 0)) {
    puVar3 = (undefined4 *)OBJ_bsearch_(&local_78,DAT_000b3868,7,4,DAT_000b3864);
    if (puVar3 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)*puVar3;
    }
  }
  else {
    puVar3 = (undefined4 *)sk_value(*pp_Var1,iVar2);
  }
  return (EVP_PKEY_METHOD *)puVar3;
}


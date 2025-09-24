
int SSL_get_signature_type_nid(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x260);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(iVar2 + 0x10);
    iVar2 = 1;
    *param_2 = *puVar1;
  }
  return iVar2;
}


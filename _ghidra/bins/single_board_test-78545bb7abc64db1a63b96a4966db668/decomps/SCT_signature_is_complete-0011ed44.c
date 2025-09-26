
int SCT_signature_is_complete(int param_1)

{
  int iVar1;
  
  iVar1 = SCT_get_signature_nid();
  if (((iVar1 != 0) && (iVar1 = *(int *)(param_1 + 0x2c), iVar1 != 0)) &&
     (iVar1 = *(int *)(param_1 + 0x30), iVar1 != 0)) {
    iVar1 = 1;
  }
  return iVar1;
}


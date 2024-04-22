
int EC_GROUP_check_discriminant(EC_GROUP *group,BN_CTX *ctx)

{
  int iVar1;
  
  if (*(code **)(*(int *)group + 0x24) == (code *)0x0) {
    ERR_put_error(0x10,0xab,0x42,DAT_000a1280,0x1dd);
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(*(int *)group + 0x24))();
  }
  return iVar1;
}


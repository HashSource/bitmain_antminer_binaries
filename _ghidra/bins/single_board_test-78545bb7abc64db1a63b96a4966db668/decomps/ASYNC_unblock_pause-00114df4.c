
void ASYNC_unblock_pause(void)

{
  int iVar1;
  undefined4 in_r3;
  
  iVar1 = OPENSSL_init_crypto(0x100,0,0,in_r3,in_r3);
  if ((((iVar1 != 0) && (iVar1 = async_get_ctx(), iVar1 != 0)) && (*(int *)(iVar1 + 4) != 0)) &&
     (*(int *)(iVar1 + 8) != 0)) {
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -1;
    return;
  }
  return;
}


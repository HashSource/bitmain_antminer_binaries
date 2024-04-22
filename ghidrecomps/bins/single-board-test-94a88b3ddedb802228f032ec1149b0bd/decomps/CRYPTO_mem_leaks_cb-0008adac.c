
void CRYPTO_mem_leaks_cb(undefined1 *cb)

{
  int iVar1;
  undefined1 *local_c;
  
  iVar1 = DAT_0008ade4;
  if (*(int *)(DAT_0008ade4 + 0x18) != 0) {
    local_c = cb;
    CRYPTO_lock(9,0x1b,DAT_0008ade8,0x33a);
    lh_doall_arg(*(_LHASH **)(iVar1 + 0x18),DAT_0008adec,&local_c);
    CRYPTO_lock(10,0x1b,DAT_0008ade8,0x33d);
  }
  return;
}


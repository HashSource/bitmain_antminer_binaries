
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SSL_get_ex_data_X509_STORE_CTX_idx(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0007c930;
  iVar2 = *DAT_0007c930;
  if (iVar2 < 0) {
    CRYPTO_lock(9,0xc,DAT_0007c934,0x94);
    iVar2 = *piVar1;
    if (iVar2 < 0) {
      iVar2 = X509_STORE_CTX_get_ex_new_index
                        (0,DAT_0007c938,(undefined1 *)0x0,(undefined1 *)0x0,(undefined1 *)0x0);
      *piVar1 = iVar2;
    }
    CRYPTO_lock(10,0xc,DAT_0007c934,0x9b);
  }
  return iVar2;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void EVP_cleanup(void)

{
  OBJ_NAME_cleanup(2);
  OBJ_NAME_cleanup(1);
  OBJ_NAME_cleanup(-1);
  EVP_PBE_cleanup();
  if (*DAT_000b1590 == 2) {
    *DAT_000b1590 = 0;
    OBJ_cleanup();
  }
  OBJ_sigid_free();
  return;
}


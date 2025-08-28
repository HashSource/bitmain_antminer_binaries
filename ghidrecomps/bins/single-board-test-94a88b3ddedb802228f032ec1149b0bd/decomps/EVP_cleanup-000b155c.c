
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void EVP_cleanup(void)

{
  OBJ_NAME_cleanup(2);
  OBJ_NAME_cleanup(1);
  OBJ_NAME_cleanup(-1);
  EVP_PBE_cleanup();
  if (obj_cleanup_defer == 2) {
    obj_cleanup_defer = 0;
    OBJ_cleanup();
  }
  OBJ_sigid_free();
  return;
}



void obj_cleanup_int(void)

{
  if (added != 0) {
    OPENSSL_LH_set_down_load(added,0);
    OPENSSL_LH_doall(added,0x142509);
    OPENSSL_LH_doall(added,0x142519);
    OPENSSL_LH_doall(added,0x142525);
    OPENSSL_LH_free(added);
    added = 0;
  }
  return;
}


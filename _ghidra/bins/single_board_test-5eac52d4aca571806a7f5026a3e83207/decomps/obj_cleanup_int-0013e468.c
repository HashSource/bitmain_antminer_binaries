
void obj_cleanup_int(void)

{
  if (added != 0) {
    OPENSSL_LH_set_down_load(added,0);
    OPENSSL_LH_doall(added,0x13e2b9);
    OPENSSL_LH_doall(added,0x13e2c9);
    OPENSSL_LH_doall(added,0x13e2d5);
    OPENSSL_LH_free(added);
    added = 0;
  }
  return;
}


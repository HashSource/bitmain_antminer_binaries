
void obj_cleanup_int(void)

{
  if (added != 0) {
    OPENSSL_LH_set_down_load(added,0);
    OPENSSL_LH_doall(added,0x14c0e1);
    OPENSSL_LH_doall(added,0x14c0f1);
    OPENSSL_LH_doall(added,0x14c0fd);
    OPENSSL_LH_free(added);
    added = 0;
  }
  return;
}


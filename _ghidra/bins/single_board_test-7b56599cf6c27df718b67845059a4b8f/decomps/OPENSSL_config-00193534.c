
void OPENSSL_config(char *config_name)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  local_14 = 0;
  local_c = 0;
  if (config_name != (char *)0x0) {
    local_10 = __strdup();
  }
  local_c = 0x32;
  OPENSSL_init_crypto(0x40,0,&local_14);
  return;
}


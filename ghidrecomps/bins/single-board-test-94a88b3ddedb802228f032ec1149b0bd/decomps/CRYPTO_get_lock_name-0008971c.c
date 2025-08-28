
char * CRYPTO_get_lock_name(int type)

{
  int iVar1;
  char *pcVar2;
  
  if (type < 0) {
    return "dynamic";
  }
  if (type < 0x29) {
    return (&lock_names)[type];
  }
  iVar1 = sk_num(app_locks);
  if (iVar1 < type + -0x29) {
    return "ERROR";
  }
  pcVar2 = (char *)sk_value(app_locks,type + -0x29);
  return pcVar2;
}


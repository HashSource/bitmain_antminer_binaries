
void CTLOG_STORE_load_default_file(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ossl_safe_getenv("CTLOG_FILE");
  if (iVar1 != 0) {
    CTLOG_STORE_load_file(param_1,iVar1);
    return;
  }
  CTLOG_STORE_load_file(param_1,"/home/mylz4/lib/openssl/ssl/ct_log_list.cnf");
  return;
}


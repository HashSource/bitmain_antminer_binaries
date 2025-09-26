
void ERR_print_errors_cb(cb *cb,void *u)

{
  pthread_t pVar1;
  size_t len;
  int iVar2;
  ulong e;
  char *pcVar3;
  char *local_113c;
  char *local_1138;
  char *local_1134;
  int local_1130;
  int local_112c;
  char acStack_1128 [256];
  char acStack_1028 [4100];
  
  pVar1 = CRYPTO_THREAD_get_current_id();
  local_113c = "";
  do {
    e = ERR_get_error_line_data(&local_1138,&local_1130,&local_1134,&local_112c);
    if (e == 0) {
      return;
    }
    ERR_error_string_n(e,acStack_1128,0x100);
    pcVar3 = local_113c;
    if (local_112c << 0x1e < 0) {
      pcVar3 = local_1134;
    }
    BIO_snprintf(acStack_1028,0x1000,"%lu:%s:%s:%d:%s\n",pVar1,acStack_1128,local_1138,local_1130,
                 pcVar3);
    len = strlen(acStack_1028);
    iVar2 = (*cb)(acStack_1028,len,u);
  } while (0 < iVar2);
  return;
}


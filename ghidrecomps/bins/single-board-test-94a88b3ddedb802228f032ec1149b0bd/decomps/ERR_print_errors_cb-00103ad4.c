
void ERR_print_errors_cb(cb *cb,void *u)

{
  ulong uVar1;
  size_t len;
  int iVar2;
  ulong e;
  char *pcVar3;
  char *local_1138;
  char *pcStack_1134;
  int local_1130;
  int local_112c;
  CRYPTO_THREADID CStack_1128;
  char acStack_1120 [256];
  char acStack_1020 [4100];
  
  CRYPTO_THREADID_current(&CStack_1128);
  uVar1 = CRYPTO_THREADID_hash(&CStack_1128);
  do {
    e = ERR_get_error_line_data(&local_1138,&local_1130,&pcStack_1134,&local_112c);
    if (e == 0) {
      return;
    }
    ERR_error_string_n(e,acStack_1120,0x100);
    pcVar3 = DAT_00103b50;
    if (local_112c << 0x1e < 0) {
      pcVar3 = pcStack_1134;
    }
    BIO_snprintf(acStack_1020,0x1000,DAT_00103b54,uVar1,acStack_1120,local_1138,local_1130,pcVar3);
    len = strlen(acStack_1020);
    iVar2 = (*cb)(acStack_1020,len,u);
  } while (0 < iVar2);
  return;
}


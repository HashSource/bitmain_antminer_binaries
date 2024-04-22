
void ERR_print_errors_cb_constprop_0(BIO *param_1)

{
  ulong uVar1;
  size_t len;
  int iVar2;
  ulong e;
  char *pcVar3;
  char *local_1130;
  char *pcStack_112c;
  int local_1128;
  int local_1124;
  CRYPTO_THREADID CStack_1120;
  char acStack_1118 [256];
  char acStack_1018 [4096];
  
  CRYPTO_THREADID_current(&CStack_1120);
  uVar1 = CRYPTO_THREADID_hash(&CStack_1120);
  do {
    e = ERR_get_error_line_data(&local_1130,&local_1128,&pcStack_112c,&local_1124);
    if (e == 0) {
      return;
    }
    ERR_error_string_n(e,acStack_1118,0x100);
    pcVar3 = DAT_00103acc;
    if (local_1124 << 0x1e < 0) {
      pcVar3 = pcStack_112c;
    }
    BIO_snprintf(acStack_1018,0x1000,DAT_00103ad0,uVar1,acStack_1118,local_1130,local_1128,pcVar3);
    len = strlen(acStack_1018);
    iVar2 = BIO_write(param_1,acStack_1018,len);
  } while (0 < iVar2);
  return;
}


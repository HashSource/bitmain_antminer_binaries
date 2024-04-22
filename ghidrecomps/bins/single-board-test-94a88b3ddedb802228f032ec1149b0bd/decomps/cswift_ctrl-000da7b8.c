
char * cswift_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  char **ppcVar1;
  char *pcVar2;
  
  ppcVar1 = DAT_000da84c;
  if (param_2 == 200) {
    if (param_4 == (char *)0x0) {
      pcVar2 = DAT_000da84c[1];
      if (pcVar2 == (char *)0x0) {
        pcVar2 = (char *)ERR_get_next_error_library();
        ppcVar1[1] = pcVar2;
      }
      ERR_put_error((int)pcVar2,100,0x43,DAT_000da850,0x1d7);
      pcVar2 = (char *)0x0;
    }
    else if (DAT_000da84c[2] == (char *)0x0) {
      if (*DAT_000da84c != (char *)0x0) {
        CRYPTO_free(*DAT_000da84c);
      }
      *ppcVar1 = (char *)0x0;
      pcVar2 = BUF_strdup(param_4);
      *ppcVar1 = pcVar2;
      if (pcVar2 != (char *)0x0) {
        pcVar2 = (char *)0x1;
      }
    }
    else {
      pcVar2 = DAT_000da84c[1];
      if (pcVar2 == (char *)0x0) {
        pcVar2 = (char *)ERR_get_next_error_library();
        ppcVar1[1] = pcVar2;
      }
      ERR_put_error((int)pcVar2,100,100,DAT_000da850,0x1db);
      pcVar2 = (char *)0x0;
    }
  }
  else {
    pcVar2 = DAT_000da84c[1];
    if (pcVar2 == (char *)0x0) {
      pcVar2 = (char *)ERR_get_next_error_library();
      ppcVar1[1] = pcVar2;
    }
    ERR_put_error((int)pcVar2,100,0x68,DAT_000da850,0x1e2);
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}


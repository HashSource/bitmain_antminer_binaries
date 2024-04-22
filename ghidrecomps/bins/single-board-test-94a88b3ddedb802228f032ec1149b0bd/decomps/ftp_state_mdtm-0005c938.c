
void ftp_state_mdtm(int *param_1)

{
  int iVar1;
  
  if (((*(char *)(*param_1 + 0x2f9) != '\0') || (*(int *)(*param_1 + 0x270) != 0)) &&
     (param_1[0x102] != 0)) {
    iVar1 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005c970);
    if (iVar1 == 0) {
      param_1[0x10a] = 0x12;
      return;
    }
    return;
  }
  ftp_state_type(param_1);
  return;
}


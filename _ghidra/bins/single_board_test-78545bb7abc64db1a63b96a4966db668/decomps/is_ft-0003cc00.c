
_Bool is_ft(char *strft)

{
  _Bool _Var1;
  size_t sVar2;
  int iVar3;
  size_t sVar4;
  char *strft_local;
  char ft [64];
  int chip_bin;
  ft_bin_list_t *list;
  hashboard_qr_code *pq;
  
  memset(ft,0,0x40);
  _Var1 = check_is_multiple_ft_version(qr_code.chip_ftversion);
  if (_Var1) {
    snprintf(ft,0x40,"%s-%d-%d_%s-%d-%d",0x21bba02,(uint)qr_code.ft_bin_list.chip_bin[0],
             (uint)qr_code.ft_bin_list.chip_col[0],0x21bba12,(uint)qr_code.ft_bin_list.chip_bin[1],
             (uint)qr_code.ft_bin_list.chip_col[1]);
  }
  else {
    snprintf(ft,0x40,"%s-%d",0x21bb9b8,(byte)qr_code.chip_bin[3] - 0x30);
  }
  if (strft != (char *)0x0) {
    sVar2 = strlen(strft);
    iVar3 = strncmp(ft,strft,sVar2);
    if (iVar3 == 0) {
      sVar2 = strlen(ft);
      sVar4 = strlen(strft);
      if (sVar2 == sVar4) {
        return true;
      }
    }
  }
  return false;
}


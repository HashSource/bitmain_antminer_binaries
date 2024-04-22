
void jsonp_error_set_source(int param_1,char *param_2)

{
  size_t sVar1;
  
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    sVar1 = strlen(param_2);
    if (sVar1 < 0x50) {
      strcpy((char *)(param_1 + 0xc),param_2);
    }
    else {
      *(undefined4 *)(param_1 + 0xc) = DAT_0002d314;
      strcpy((char *)(param_1 + 0xf),param_2 + (sVar1 - 0x4c));
    }
  }
  return;
}


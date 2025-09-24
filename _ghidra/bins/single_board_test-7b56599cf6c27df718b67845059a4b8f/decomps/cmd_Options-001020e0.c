
int cmd_Options(void *param_1,char *param_2)

{
  int iVar1;
  
  if (param_2 != (char *)0x0) {
    *(undefined4 *)((int)param_1 + 0x50) = 0xf;
    *(undefined1 **)((int)param_1 + 0x4c) = ssl_option_list_25890;
    iVar1 = CONF_parse_list(param_2,0x2c,1,(list_cb *)0x1024c5,param_1);
    return iVar1;
  }
  return -3;
}


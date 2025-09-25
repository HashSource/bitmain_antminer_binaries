
void cmd_Protocol(void *param_1,char *param_2)

{
  *(undefined4 *)((int)param_1 + 0x50) = 9;
  *(undefined1 **)((int)param_1 + 0x4c) = ssl_protocol_list_25849;
  CONF_parse_list(param_2,0x2c,1,(list_cb *)0xfe275,param_1);
  return;
}


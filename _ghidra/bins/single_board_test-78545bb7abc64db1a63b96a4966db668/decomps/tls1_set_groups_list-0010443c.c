
int tls1_set_groups_list(int param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  undefined4 local_8c;
  undefined1 auStack_88 [120];
  
  local_8c = 0;
  iVar1 = CONF_parse_list(param_3,0x3a,1,(list_cb *)0x103f19,&local_8c);
  if ((iVar1 != 0) && (iVar1 = 1, param_1 != 0)) {
    iVar1 = tls1_set_groups(param_1,param_2,auStack_88,local_8c);
  }
  return iVar1;
}


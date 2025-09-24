
int tls1_set_sigalgs_list(int param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_7c;
  undefined1 auStack_78 [104];
  
  local_7c = 0;
  iVar1 = CONF_parse_list(param_2,0x3a,1,(list_cb *)0xfa225,&local_7c);
  if ((iVar1 != 0) && (iVar1 = 1, param_1 != 0)) {
    iVar1 = tls1_set_raw_sigalgs(param_1,auStack_78,local_7c,param_3);
  }
  return iVar1;
}


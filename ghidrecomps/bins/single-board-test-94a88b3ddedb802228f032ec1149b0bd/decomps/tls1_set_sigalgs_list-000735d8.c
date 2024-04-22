
int tls1_set_sigalgs_list(int param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_fc;
  undefined auStack_f8 [228];
  
  local_fc = 0;
  iVar1 = CONF_parse_list(param_2,0x3a,1,DAT_0007360c,&local_fc);
  if ((iVar1 != 0) && (iVar1 = 1, param_1 != 0)) {
    iVar1 = tls1_set_sigalgs(param_1,auStack_f8,local_fc,param_3);
  }
  return iVar1;
}


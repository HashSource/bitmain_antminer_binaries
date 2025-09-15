
void setconfig(undefined4 param_1,undefined4 param_2,char *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    message(param_1,0x55,0);
    return;
  }
  pcVar4 = strchr(param_3,0x2c);
  if (pcVar4 == (char *)0x0) {
    message(param_1,0x56,0,param_3);
    return;
  }
  *pcVar4 = '\0';
  uVar5 = strtol(pcVar4 + 1,(char **)0x0,10);
  if (9999 < uVar5) {
    message(param_1,0x54,uVar5,param_3);
    return;
  }
  iVar6 = strcasecmp(param_3,"queue");
  uVar1 = opt_scantime;
  uVar2 = opt_expiry;
  uVar3 = uVar5;
  if (((iVar6 != 0) &&
      (iVar6 = strcasecmp(param_3,"scantime"), uVar1 = uVar5, uVar2 = opt_expiry, uVar3 = opt_queue,
      iVar6 != 0)) &&
     (iVar6 = strcasecmp(param_3,"expiry"), uVar1 = opt_scantime, uVar2 = uVar5, uVar3 = opt_queue,
     iVar6 != 0)) {
    message(param_1,0x53,0,param_3);
    return;
  }
  opt_queue = uVar3;
  opt_expiry = uVar2;
  opt_scantime = uVar1;
  message(param_1,0x52,uVar5,param_3);
  return;
}


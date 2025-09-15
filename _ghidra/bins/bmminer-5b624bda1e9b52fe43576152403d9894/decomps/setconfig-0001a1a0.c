
/* WARNING: Unknown calling convention */

void setconfig(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  uint paramid;
  int iVar5;
  int value;
  
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x55,0,(char *)0x0,isjson);
    return;
  }
  pcVar4 = strchr(param,0x2c);
  if (pcVar4 == (char *)0x0) {
    message(io_data,0x56,0,param,isjson);
    return;
  }
  *pcVar4 = '\0';
  paramid = strtol(pcVar4 + 1,(char **)0x0,10);
  if (9999 < paramid) {
    message(io_data,0x54,paramid,param,isjson);
    return;
  }
  iVar5 = strcasecmp(param,"queue");
  uVar1 = opt_scantime;
  uVar2 = opt_expiry;
  uVar3 = paramid;
  if (((iVar5 != 0) &&
      (iVar5 = strcasecmp(param,"scantime"), uVar1 = paramid, uVar2 = opt_expiry, uVar3 = opt_queue,
      iVar5 != 0)) &&
     (iVar5 = strcasecmp(param,"expiry"), uVar1 = opt_scantime, uVar2 = paramid, uVar3 = opt_queue,
     iVar5 != 0)) {
    message(io_data,0x53,0,param,isjson);
    return;
  }
  opt_queue = uVar3;
  opt_expiry = uVar2;
  opt_scantime = uVar1;
  message(io_data,0x52,paramid,param,isjson);
  return;
}


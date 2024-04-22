
/* WARNING: Unknown calling convention */

void setconfig(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  char *pcVar1;
  char *comma;
  uint paramid;
  int iVar2;
  int value;
  
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x55,0,(char *)0x0,isjson);
    return;
  }
  pcVar1 = strchr(param,0x2c);
  if (pcVar1 == (char *)0x0) {
    message(io_data,0x56,0,param,isjson);
    return;
  }
  *pcVar1 = '\0';
  paramid = strtol(pcVar1 + 1,(char **)0x0,10);
  if (paramid < 10000) {
    iVar2 = strcasecmp(param,DAT_0001a268);
    if (iVar2 == 0) {
      *DAT_0001a26c = paramid;
    }
    else {
      iVar2 = strcasecmp(param,DAT_0001a270);
      if (iVar2 == 0) {
        *DAT_0001a27c = paramid;
      }
      else {
        iVar2 = strcasecmp(param,DAT_0001a274);
        if (iVar2 != 0) {
          message(io_data,0x53,0,param,isjson);
          return;
        }
        *DAT_0001a278 = paramid;
      }
    }
    message(io_data,0x52,paramid,param,isjson);
    return;
  }
  message(io_data,0x54,paramid,param,isjson);
  return;
}


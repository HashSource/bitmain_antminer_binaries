
void setconfig(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int iVar1;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  
  iVar1 = strcasecmp(param,"queue");
  if (((iVar1 == 0) || (iVar1 = strcasecmp(param,"scantime"), iVar1 == 0)) ||
     (iVar1 = strcasecmp(param,"expiry"), iVar1 == 0)) {
    message(io_data,0x7e,0,param,isjson);
  }
  message(io_data,0x53,0,param,isjson);
  return;
}



void ascdisable(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int iVar1;
  int ascid;
  cgpu_info *pcVar2;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  char tmp42 [2048];
  cgpu_info *cgpu;
  int dev;
  int id;
  int numasc;
  
  iVar1 = numascs();
  if (iVar1 == 0) {
    message(io_data,0x69,0,(char *)0x0,isjson);
  }
  else if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0xf,0,(char *)0x0,isjson);
  }
  else {
    ascid = atoi(param);
    if ((ascid < 0) || (iVar1 <= ascid)) {
      message(io_data,0x6b,ascid,(char *)0x0,isjson);
    }
    else {
      iVar1 = ascdevice(ascid);
      if (iVar1 < 0) {
        message(io_data,0x6b,ascid,(char *)0x0,isjson);
      }
      else {
        pcVar2 = get_devices(iVar1);
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"API: request to ascdisable ascid %d device %d %s%u",ascid,iVar1,
                   pcVar2->drv->name,pcVar2->device_id);
          _applog(7,tmp42,false);
        }
        if (pcVar2->deven == DEV_DISABLED) {
          message(io_data,0x6d,ascid,(char *)0x0,isjson);
        }
        else {
          pcVar2->deven = DEV_DISABLED;
          message(io_data,0x6f,ascid,(char *)0x0,isjson);
        }
      }
    }
  }
  return;
}


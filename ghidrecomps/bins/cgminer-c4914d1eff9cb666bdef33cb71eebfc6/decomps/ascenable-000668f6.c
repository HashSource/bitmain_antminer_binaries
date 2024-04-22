
void ascenable(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int iVar1;
  int ascid;
  cgpu_info *pcVar2;
  thr_info *ptVar3;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  char tmp42 [2048];
  int asc;
  thr_info *thr;
  cgpu_info *cgpu;
  int dev;
  int id;
  int numasc;
  int i;
  
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
          snprintf(tmp42,0x800,"API: request to ascenable ascid %d device %d %s%u",ascid,iVar1,
                   pcVar2->drv->name,pcVar2->device_id);
          _applog(7,tmp42,false);
        }
        if (pcVar2->deven == DEV_DISABLED) {
          for (i = 0; i < mining_threads; i = i + 1) {
            ptVar3 = get_thread(i);
            if (ptVar3->cgpu->cgminer_id == iVar1) {
              pcVar2->deven = DEV_ENABLED;
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,"API: Pushing sem post to thread %d",ptVar3->id);
                _applog(7,tmp42,false);
              }
              _cgsem_post(&ptVar3->sem,"api-btm.c","ascenable",0xfeb);
            }
          }
          message(io_data,0x6e,ascid,(char *)0x0,isjson);
        }
        else {
          message(io_data,0x6c,ascid,(char *)0x0,isjson);
        }
      }
    }
  }
  return;
}


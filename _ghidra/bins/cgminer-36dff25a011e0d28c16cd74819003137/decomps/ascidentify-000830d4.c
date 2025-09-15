
void ascidentify(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int iVar1;
  int ascid;
  cgpu_info *pcVar2;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  device_drv *drv;
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
        if (pcVar2->drv->identify_device == (_func_void_cgpu_info_ptr *)0x0) {
          message(io_data,0x72,ascid,(char *)0x0,isjson);
        }
        else {
          (*pcVar2->drv->identify_device)(pcVar2);
          message(io_data,0x71,ascid,(char *)0x0,isjson);
        }
      }
    }
  }
  return;
}


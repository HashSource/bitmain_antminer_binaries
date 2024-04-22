
void ascset(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int iVar1;
  char *pcVar2;
  int ascid;
  cgpu_info *pcVar3;
  device_drv *pdVar4;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  char buf [8192];
  char *ret;
  device_drv *drv;
  cgpu_info *cgpu;
  int dev;
  int id;
  int numasc;
  char *set;
  char *opt;
  
  iVar1 = numascs();
  if (iVar1 == 0) {
    message(io_data,0x69,0,(char *)0x0,isjson);
  }
  else if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0xf,0,(char *)0x0,isjson);
  }
  else {
    pcVar2 = strchr(param,0x2c);
    opt = pcVar2;
    if (pcVar2 != (char *)0x0) {
      opt = pcVar2 + 1;
      *pcVar2 = '\0';
    }
    if ((opt == (char *)0x0) || (*opt == '\0')) {
      message(io_data,0x74,0,(char *)0x0,isjson);
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
          pcVar3 = get_devices(iVar1);
          pdVar4 = pcVar3->drv;
          pcVar2 = strchr(opt,0x2c);
          set = pcVar2;
          if (pcVar2 != (char *)0x0) {
            set = pcVar2 + 1;
            *pcVar2 = '\0';
          }
          if (pdVar4->set_device == (_func_char_ptr_cgpu_info_ptr_char_ptr_char_ptr_char_ptr *)0x0)
          {
            message(io_data,0x75,ascid,(char *)0x0,isjson);
          }
          else {
            pcVar2 = (*pdVar4->set_device)(pcVar3,opt,set,buf);
            if (pcVar2 == (char *)0x0) {
              message(io_data,0x77,ascid,(char *)0x0,isjson);
            }
            else {
              iVar1 = strcasecmp(opt,"help");
              if (iVar1 == 0) {
                message(io_data,0x76,ascid,pcVar2,isjson);
              }
              else {
                message(io_data,0x78,ascid,pcVar2,isjson);
              }
            }
          }
        }
      }
    }
  }
  return;
}


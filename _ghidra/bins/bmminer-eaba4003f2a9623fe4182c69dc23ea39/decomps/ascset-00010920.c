
void ascset(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int iVar1;
  int ascid;
  cgpu_info *pcVar2;
  char *param2;
  device_drv *pdVar3;
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
    opt = strchr(param,0x2c);
    if (opt != (char *)0x0) {
      *opt = '\0';
      opt = opt + 1;
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
          pcVar2 = get_devices(iVar1);
          pdVar3 = pcVar2->drv;
          set = strchr(opt,0x2c);
          if (set != (char *)0x0) {
            *set = '\0';
            set = set + 1;
          }
          if (pdVar3->set_device == (_func_char_ptr_cgpu_info_ptr_char_ptr_char_ptr_char_ptr *)0x0)
          {
            message(io_data,0x75,ascid,(char *)0x0,isjson);
          }
          else {
            param2 = (*pdVar3->set_device)(pcVar2,opt,set,buf);
            if (param2 == (char *)0x0) {
              message(io_data,0x77,ascid,(char *)0x0,isjson);
            }
            else {
              iVar1 = strcasecmp(opt,"help");
              if (iVar1 == 0) {
                message(io_data,0x76,ascid,param2,isjson);
              }
              else {
                message(io_data,0x78,ascid,param2,isjson);
              }
            }
          }
        }
      }
    }
  }
  return;
}


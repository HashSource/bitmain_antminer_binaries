
void notify(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  cgpu_info *cgpu_00;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  cgpu_info *cgpu;
  int i;
  _Bool io_open;
  
  io_open = false;
  if (total_devices == 0) {
    message(io_data,10,0,(char *)0x0,isjson);
  }
  else {
    message(io_data,0x3c,0,(char *)0x0,isjson);
    if (isjson) {
      io_open = io_add(io_data,",\"NOTIFY\":[");
    }
    for (i = 0; i < total_devices; i = i + 1) {
      cgpu_00 = get_devices(i);
      notifystatus(io_data,i,cgpu_00,isjson,group);
    }
    if ((isjson) && (io_open != false)) {
      io_close(io_data);
    }
  }
  return;
}


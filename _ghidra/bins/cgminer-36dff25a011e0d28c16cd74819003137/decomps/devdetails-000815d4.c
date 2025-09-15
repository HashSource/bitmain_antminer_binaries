
void devdetails(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  char *pcVar1;
  _Bool precom;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  int i;
  cgpu_info *cgpu;
  _Bool io_open;
  api_data *root;
  
  root = (api_data *)0x0;
  io_open = false;
  if (total_devices == 0) {
    message(io_data,10,0,(char *)0x0,isjson);
  }
  else {
    message(io_data,0x45,0,(char *)0x0,isjson);
    if (isjson) {
      io_open = io_add(io_data,",\"DEVDETAILS\":[");
    }
    for (i = 0; i < total_devices; i = i + 1) {
      cgpu = get_devices(i);
      root = api_add_int(root,"DEVDETAILS",&i,false);
      root = api_add_string(root,"Name",cgpu->drv->name,false);
      root = api_add_int(root,"ID",&cgpu->device_id,false);
      root = api_add_string(root,"Driver",cgpu->drv->dname,false);
      pcVar1 = cgpu->kname;
      if (cgpu->kname == (char *)0x0) {
        pcVar1 = BLANK;
      }
      root = api_add_const(root,"Kernel",pcVar1,false);
      pcVar1 = BLANK;
      if (cgpu->name != (char *)0x0) {
        pcVar1 = cgpu->name;
      }
      root = api_add_const(root,"Model",pcVar1,false);
      pcVar1 = BLANK;
      if (cgpu->device_path != (char *)0x0) {
        pcVar1 = cgpu->device_path;
      }
      root = api_add_const(root,"Device Path",pcVar1,false);
      if ((isjson) && (0 < i)) {
        precom = true;
      }
      else {
        precom = false;
      }
      root = print_data(io_data,root,isjson,precom);
    }
    if ((isjson) && (io_open != false)) {
      io_close(io_data);
    }
  }
  return;
}


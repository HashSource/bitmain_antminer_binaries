
void minerstats(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  api_data *paVar1;
  cgpu_info *cgpu_00;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  char id [20];
  cgpu_info *cgpu;
  api_data *root;
  int j;
  int i;
  api_data *extra;
  _Bool io_open;
  
  io_open = false;
  message(io_data,0x46,0,(char *)0x0,isjson);
  if (isjson) {
    io_open = io_add(io_data,",\"STATS\":[");
  }
  paVar1 = api_add_string((api_data *)0x0,"BMMiner","2.0.0",false);
  paVar1 = api_add_string(paVar1,"Miner",g_miner_version,false);
  paVar1 = api_add_string(paVar1,"CompileTime",g_miner_compiletime,false);
  paVar1 = api_add_string(paVar1,"Type",g_miner_type,false);
  print_data(io_data,paVar1,isjson,false);
  i = 0;
  for (j = 0; j < total_devices; j = j + 1) {
    cgpu_00 = get_devices(j);
    if ((cgpu_00 != (cgpu_info *)0x0) && (cgpu_00->drv != (device_drv *)0x0)) {
      if (cgpu_00->drv->get_api_stats == (_func_api_data_ptr_cgpu_info_ptr *)0x0) {
        extra = (api_data *)0x0;
      }
      else {
        extra = (*cgpu_00->drv->get_api_stats)(cgpu_00);
      }
      sprintf(id,"%s%d",cgpu_00->drv->name,cgpu_00->device_id);
      i = itemstats(io_data,i,id,&cgpu_00->cgminer_stats,(cgminer_pool_stats *)0x0,extra,cgpu_00,
                    isjson);
    }
  }
  if ((isjson) && (io_open != false)) {
    io_close(io_data);
  }
  return;
}


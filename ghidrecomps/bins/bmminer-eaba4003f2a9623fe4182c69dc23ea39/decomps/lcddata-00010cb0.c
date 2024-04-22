
void lcddata(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  char *buf;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  time_t last_device_valid_work;
  time_t last_share_time;
  float temp;
  double last_share_diff;
  double ghs;
  cgpu_info *cgpu;
  _Bool io_open;
  pool *pool;
  api_data *root;
  int i;
  char *rpc_user;
  char *rpc_url;
  
  root = (api_data *)0x0;
  ghs = 0.0;
  last_share_diff._0_4_ = 0;
  last_share_diff._4_4_ = 0;
  temp = 0.0;
  last_share_time = 0;
  last_device_valid_work = 0;
  pool = (pool *)0x0;
  rpc_url = "none";
  rpc_user = "";
  message(io_data,0x7d,0,(char *)0x0,isjson);
  if (isjson) {
    buf = ",\"LCD\":[";
  }
  else {
    buf = "LCD,";
  }
  io_open = io_add(io_data,buf);
  _mutex_lock(&hash_lock,"api-btm.c","lcddata",0x10a9);
  root = api_add_elapsed(root,"Elapsed",&total_secs,true);
  ghs = getAVGhashrate();
  root = api_add_mhs(root,"GHS av",&ghs,true);
  ghs = rolling5 / DAT_00010ff8;
  root = api_add_mhs(root,"GHS 5m",&ghs,true);
  ghs = total_rolling / DAT_00010ff8;
  root = api_add_mhs(root,"GHS 5s",&ghs,true);
  _mutex_unlock(&hash_lock,"api-btm.c","lcddata",0x10b5);
  temp = 0.0;
  last_device_valid_work = 0;
  for (i = 0; i < total_devices; i = i + 1) {
    cgpu = get_devices(i);
    if ((last_device_valid_work == 0) || (last_device_valid_work < cgpu->last_device_valid_work)) {
      last_device_valid_work = cgpu->last_device_valid_work;
    }
    if ((int)((uint)((double)temp < cgpu->temp) << 0x1f) < 0) {
      temp = (float)cgpu->temp;
    }
  }
  last_share_time = 0;
  last_share_diff._0_4_ = 0;
  last_share_diff._4_4_ = 0;
  for (i = 0; i < total_pools; i = i + 1) {
    pool = pools[i];
    if ((pool->removed == false) &&
       ((last_share_time == 0 || (last_share_time < pool->last_share_time)))) {
      last_share_time = pool->last_share_time;
      last_share_diff._0_4_ = *(undefined4 *)&pool->last_share_diff;
      last_share_diff._4_4_ = *(undefined4 *)((int)&pool->last_share_diff + 4);
    }
  }
  pool = current_pool();
  if (pool != (pool *)0x0) {
    rpc_url = pool->rpc_url;
    rpc_user = pool->rpc_user;
  }
  root = api_add_temp(root,"Temperature",&temp,false);
  root = api_add_diff(root,"Last Share Difficulty",&last_share_diff,false);
  root = api_add_time(root,"Last Share Time",&last_share_time,false);
  root = api_add_uint64(root,"Best Share",&best_diff,true);
  root = api_add_time(root,"Last Valid Work",&last_device_valid_work,false);
  root = api_add_uint(root,"Found Blocks",&found_blocks,true);
  root = api_add_escape(root,"Current Pool",rpc_url,true);
  root = api_add_escape(root,"User",rpc_user,true);
  root = print_data(io_data,root,isjson,false);
  if ((isjson) && (io_open != false)) {
    io_close(io_data);
  }
  return;
}


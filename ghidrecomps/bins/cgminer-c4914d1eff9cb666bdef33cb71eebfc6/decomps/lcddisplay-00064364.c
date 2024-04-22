
void lcddisplay(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  char szuser [32];
  char szpool [32];
  char szindex [32];
  double ghs;
  pool *pool;
  _Bool io_open;
  api_data *root;
  
  root = (api_data *)0x0;
  io_open = false;
  memset(szindex,0,0x20);
  memset(szpool,0,0x20);
  memset(szuser,0,0x20);
  pool = current_pool();
  message(io_data,7,0,(char *)0x0,isjson);
  if (isjson) {
    io_open = io_add(io_data,",\"POOLS\":[");
  }
  ghs = getAVGhashrate();
  szindex[0] = '0';
  szindex[1] = '\0';
  root = api_add_string(root,"LCD",szindex,false);
  root = api_add_string(root,"GHS 5s",displayed_hash_rate,false);
  root = api_add_mhs(root,"GHSavg",&ghs,false);
  if (pool == (pool *)0x0) {
    szuser._0_2_ = (undefined2)DAT_00093270;
    szuser[2] = (char)((uint)DAT_00093270 >> 0x10);
    szpool._0_2_ = szuser._0_2_;
    szpool[2] = szuser[2];
    root = api_add_string(root,"pool",szpool,false);
    root = api_add_string(root,"user",szuser,false);
  }
  else {
    root = api_add_string(root,"pool",pool->rpc_url,false);
    root = api_add_string(root,"user",pool->rpc_user,false);
  }
  root = print_data(io_data,root,isjson,isjson);
  if ((isjson) && (io_open != false)) {
    io_close(io_data);
  }
  return;
}


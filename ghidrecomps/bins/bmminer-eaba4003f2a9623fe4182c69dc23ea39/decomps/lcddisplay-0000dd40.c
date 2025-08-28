
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
  szindex[0] = '\0';
  szindex[1] = '\0';
  szindex[2] = '\0';
  szindex[3] = '\0';
  szindex[4] = '\0';
  szindex[5] = '\0';
  szindex[6] = '\0';
  szindex[7] = '\0';
  szindex[8] = '\0';
  szindex[9] = '\0';
  szindex[10] = '\0';
  szindex[0xb] = '\0';
  szindex[0xc] = '\0';
  szindex[0xd] = '\0';
  szindex[0xe] = '\0';
  szindex[0xf] = '\0';
  szindex[0x10] = '\0';
  szindex[0x11] = '\0';
  szindex[0x12] = '\0';
  szindex[0x13] = '\0';
  szindex[0x14] = '\0';
  szindex[0x15] = '\0';
  szindex[0x16] = '\0';
  szindex[0x17] = '\0';
  szindex[0x18] = '\0';
  szindex[0x19] = '\0';
  szindex[0x1a] = '\0';
  szindex[0x1b] = '\0';
  szindex[0x1c] = '\0';
  szindex[0x1d] = '\0';
  szindex[0x1e] = '\0';
  szindex[0x1f] = '\0';
  szpool[0] = '\0';
  szpool[1] = '\0';
  szpool[2] = '\0';
  szpool[3] = '\0';
  szpool[4] = '\0';
  szpool[5] = '\0';
  szpool[6] = '\0';
  szpool[7] = '\0';
  szpool[8] = '\0';
  szpool[9] = '\0';
  szpool[10] = '\0';
  szpool[0xb] = '\0';
  szpool[0xc] = '\0';
  szpool[0xd] = '\0';
  szpool[0xe] = '\0';
  szpool[0xf] = '\0';
  szpool[0x10] = '\0';
  szpool[0x11] = '\0';
  szpool[0x12] = '\0';
  szpool[0x13] = '\0';
  szpool[0x14] = '\0';
  szpool[0x15] = '\0';
  szpool[0x16] = '\0';
  szpool[0x17] = '\0';
  szpool[0x18] = '\0';
  szpool[0x19] = '\0';
  szpool[0x1a] = '\0';
  szpool[0x1b] = '\0';
  szpool[0x1c] = '\0';
  szpool[0x1d] = '\0';
  szpool[0x1e] = '\0';
  szpool[0x1f] = '\0';
  szuser[0] = '\0';
  szuser[1] = '\0';
  szuser[2] = '\0';
  szuser[3] = '\0';
  szuser[4] = '\0';
  szuser[5] = '\0';
  szuser[6] = '\0';
  szuser[7] = '\0';
  szuser[8] = '\0';
  szuser[9] = '\0';
  szuser[10] = '\0';
  szuser[0xb] = '\0';
  szuser[0xc] = '\0';
  szuser[0xd] = '\0';
  szuser[0xe] = '\0';
  szuser[0xf] = '\0';
  szuser[0x10] = '\0';
  szuser[0x11] = '\0';
  szuser[0x12] = '\0';
  szuser[0x13] = '\0';
  szuser[0x14] = '\0';
  szuser[0x15] = '\0';
  szuser[0x16] = '\0';
  szuser[0x17] = '\0';
  szuser[0x18] = '\0';
  szuser[0x19] = '\0';
  szuser[0x1a] = '\0';
  szuser[0x1b] = '\0';
  szuser[0x1c] = '\0';
  szuser[0x1d] = '\0';
  szuser[0x1e] = '\0';
  szuser[0x1f] = '\0';
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
    szpool[0] = 'n';
    szpool[1] = 'o';
    szpool[2] = '\0';
    szuser[0] = 'n';
    szuser[1] = 'o';
    szuser[2] = '\0';
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


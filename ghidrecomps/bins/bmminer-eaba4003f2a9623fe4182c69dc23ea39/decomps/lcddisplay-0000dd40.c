
void lcddisplay(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  undefined4 uVar1;
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
  szindex[11] = '\0';
  szindex[12] = '\0';
  szindex[13] = '\0';
  szindex[14] = '\0';
  szindex[15] = '\0';
  szindex[16] = '\0';
  szindex[17] = '\0';
  szindex[18] = '\0';
  szindex[19] = '\0';
  szindex[20] = '\0';
  szindex[21] = '\0';
  szindex[22] = '\0';
  szindex[23] = '\0';
  szindex[24] = '\0';
  szindex[25] = '\0';
  szindex[26] = '\0';
  szindex[27] = '\0';
  szindex[28] = '\0';
  szindex[29] = '\0';
  szindex[30] = '\0';
  szindex[31] = '\0';
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
  szpool[11] = '\0';
  szpool[12] = '\0';
  szpool[13] = '\0';
  szpool[14] = '\0';
  szpool[15] = '\0';
  szpool[16] = '\0';
  szpool[17] = '\0';
  szpool[18] = '\0';
  szpool[19] = '\0';
  szpool[20] = '\0';
  szpool[21] = '\0';
  szpool[22] = '\0';
  szpool[23] = '\0';
  szpool[24] = '\0';
  szpool[25] = '\0';
  szpool[26] = '\0';
  szpool[27] = '\0';
  szpool[28] = '\0';
  szpool[29] = '\0';
  szpool[30] = '\0';
  szpool[31] = '\0';
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
  szuser[11] = '\0';
  szuser[12] = '\0';
  szuser[13] = '\0';
  szuser[14] = '\0';
  szuser[15] = '\0';
  szuser[16] = '\0';
  szuser[17] = '\0';
  szuser[18] = '\0';
  szuser[19] = '\0';
  szuser[20] = '\0';
  szuser[21] = '\0';
  szuser[22] = '\0';
  szuser[23] = '\0';
  szuser[24] = '\0';
  szuser[25] = '\0';
  szuser[26] = '\0';
  szuser[27] = '\0';
  szuser[28] = '\0';
  szuser[29] = '\0';
  szuser[30] = '\0';
  szuser[31] = '\0';
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
    szpool._0_3_ = (undefined3)DAT_0006d604;
    uVar1 = szpool._0_4_;
    szuser[0] = szpool[0];
    szuser[1] = szpool[1];
    szuser[2] = szpool[2];
    szpool._0_4_ = uVar1;
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


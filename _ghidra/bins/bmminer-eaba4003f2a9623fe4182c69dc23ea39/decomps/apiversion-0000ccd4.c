
void apiversion(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  api_data *paVar2;
  char *buf;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  _Bool io_open;
  api_data *root;
  
  message(io_data,0x16,0,(char *)0x0,isjson);
  if (isjson) {
    buf = ",\"VERSION\":[";
  }
  else {
    buf = "VERSION,";
  }
  _Var1 = io_add(io_data,buf);
  paVar2 = api_add_string((api_data *)0x0,"CGMiner","2.0.0",false);
  paVar2 = api_add_const(paVar2,"API",APIVERSION,false);
  paVar2 = api_add_string(paVar2,"Miner",g_miner_version,false);
  paVar2 = api_add_string(paVar2,"CompileTime",g_miner_compiletime,false);
  paVar2 = api_add_string(paVar2,"Type",g_miner_type,false);
  print_data(io_data,paVar2,isjson,false);
  if ((isjson) && (_Var1)) {
    io_close(io_data);
  }
  return;
}


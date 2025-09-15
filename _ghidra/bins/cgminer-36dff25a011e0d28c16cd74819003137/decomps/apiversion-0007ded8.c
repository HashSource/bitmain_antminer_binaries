
void apiversion(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  uint uVar1;
  _Bool _Var2;
  api_data *paVar3;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  _Bool io_open;
  api_data *root;
  
  message(io_data,0x16,0,(char *)0x0,isjson);
  if (isjson) {
    uVar1 = 0xdb7c;
  }
  else {
    uVar1 = 0xdb8c;
  }
  _Var2 = io_add(io_data,(char *)(uVar1 | 0xa0000));
  paVar3 = api_add_string((api_data *)0x0,"CGMiner","2.0.0",false);
  paVar3 = api_add_const(paVar3,"API",APIVERSION,false);
  paVar3 = api_add_string(paVar3,"Miner",g_miner_version,false);
  paVar3 = api_add_string(paVar3,"CompileTime",g_miner_compiletime,false);
  paVar3 = api_add_string(paVar3,"Type",g_miner_type,false);
  print_data(io_data,paVar3,isjson,false);
  if ((isjson) && (_Var2)) {
    io_close(io_data);
  }
  return;
}


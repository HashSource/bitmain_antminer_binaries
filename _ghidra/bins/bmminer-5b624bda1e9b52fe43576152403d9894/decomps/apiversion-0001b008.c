
/* WARNING: Unknown calling convention */

void apiversion(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  api_data *paVar2;
  
  message(io_data,0x16,0,(char *)0x0,isjson);
  if (isjson) {
    _Var1 = io_add(io_data,",\"VERSION\":[");
    paVar2 = api_add_string((api_data *)0x0,"BMMiner","2.0.0",false);
    paVar2 = api_add_const(paVar2,"API","3.1",false);
    paVar2 = api_add_string(paVar2,"Miner",g_miner_version,false);
    paVar2 = api_add_string(paVar2,"CompileTime",g_miner_compiletime,false);
    paVar2 = api_add_string(paVar2,"Type",g_miner_type,false);
    print_data(io_data,paVar2,true,false);
    if (_Var1) {
      io_data->close = true;
    }
    return;
  }
  io_add(io_data,"VERSION,");
  paVar2 = api_add_string((api_data *)0x0,"BMMiner","2.0.0",isjson);
  paVar2 = api_add_const(paVar2,"API","3.1",isjson);
  paVar2 = api_add_string(paVar2,"Miner",g_miner_version,isjson);
  paVar2 = api_add_string(paVar2,"CompileTime",g_miner_compiletime,isjson);
  paVar2 = api_add_string(paVar2,"Type",g_miner_type,isjson);
  print_data(io_data,paVar2,isjson,isjson);
  return;
}


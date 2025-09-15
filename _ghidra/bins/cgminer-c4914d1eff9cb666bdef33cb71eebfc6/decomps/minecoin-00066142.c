
void minecoin(io_data *io_data,long c,char *param,_Bool isjson,char group)

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
  
  message(io_data,0x4e,0,(char *)0x0,isjson);
  if (isjson) {
    buf = ",\"COIN\":[";
  }
  else {
    buf = "COIN,";
  }
  _Var1 = io_add(io_data,buf);
  paVar2 = api_add_const((api_data *)0x0,"Hash Method",SHA256STR,false);
  _cg_rlock(&ch_lock,"api-btm.c","minecoin",0xe5d);
  paVar2 = api_add_timeval(paVar2,"Current Block Time",&block_timeval,true);
  paVar2 = api_add_string(paVar2,"Current Block Hash",current_hash,true);
  _cg_runlock(&ch_lock,"api-btm.c","minecoin",0xe60);
  paVar2 = api_add_bool(paVar2,"LP",&have_longpoll,false);
  paVar2 = api_add_diff(paVar2,"Network Difficulty",&current_diff,true);
  print_data(io_data,paVar2,isjson,false);
  if ((isjson) && (_Var1)) {
    io_close(io_data);
  }
  return;
}


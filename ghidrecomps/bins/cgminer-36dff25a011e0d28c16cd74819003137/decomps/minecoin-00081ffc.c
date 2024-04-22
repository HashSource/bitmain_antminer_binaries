
void minecoin(io_data *io_data,long c,char *param,_Bool isjson,char group)

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
  
  message(io_data,0x4e,0,(char *)0x0,isjson);
  if (isjson) {
    uVar1 = 0xe240;
  }
  else {
    uVar1 = 0xe24c;
  }
  _Var2 = io_add(io_data,(char *)(uVar1 | 0xa0000));
  paVar3 = api_add_const((api_data *)0x0,"Hash Method",SHA256STR,false);
  _cg_rlock(&ch_lock,"api-btm.c","minecoin",0xe59);
  paVar3 = api_add_timeval(paVar3,"Current Block Time",&block_timeval,true);
  paVar3 = api_add_string(paVar3,"Current Block Hash",current_hash,true);
  _cg_runlock(&ch_lock,"api-btm.c","minecoin",0xe5c);
  paVar3 = api_add_bool(paVar3,"LP",&have_longpoll,false);
  paVar3 = api_add_diff(paVar3,"Network Difficulty",&current_diff,true);
  print_data(io_data,paVar3,isjson,false);
  if ((isjson) && (_Var2)) {
    io_close(io_data);
  }
  return;
}


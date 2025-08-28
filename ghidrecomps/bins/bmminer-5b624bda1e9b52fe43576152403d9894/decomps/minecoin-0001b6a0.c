
/* WARNING: Unknown calling convention */

void minecoin(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  api_data *paVar2;
  int iVar3;
  int iVar4;
  char *buf;
  char *func;
  char *func_00;
  char *func_01;
  undefined1 extraout_r3;
  undefined1 uVar5;
  int line;
  int line_00;
  int line_01;
  int extraout_r3_00;
  
  message(io_data,0x4e,0,(char *)0x0,isjson);
  buf = "COIN,";
  if (isjson) {
    buf = ",\"COIN\":[";
  }
  _Var1 = io_add(io_data,buf);
  paVar2 = api_add_const((api_data *)0x0,"Hash Method","sha256",false);
  iVar3 = pthread_mutex_lock((pthread_mutex_t *)&ch_lock);
  iVar4 = line;
  if (iVar3 != 0) {
    _mutex_lock((pthread_mutex_t *)"minecoin",(char *)0xe7c,func,line);
    iVar4 = extraout_r3_00;
  }
  _rd_lock(&ch_lock.rwlock,"minecoin",(char *)0xe7c,iVar4);
  iVar4 = pthread_mutex_unlock((pthread_mutex_t *)&ch_lock);
  if (iVar4 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"minecoin",(char *)0xe7c,func_00,line_00);
  }
  paVar2 = api_add_timeval(paVar2,"Current Block Time",&block_timeval,true);
  paVar2 = api_add_string(paVar2,"Current Block Hash",current_hash,true);
  iVar4 = pthread_rwlock_unlock((pthread_rwlock_t *)&ch_lock.rwlock);
  if (iVar4 != 0) {
    _rw_unlock((pthread_rwlock_t *)"minecoin",(char *)0xe7f,func_01,line_01);
  }
  (*selective_yield)();
  paVar2 = api_add_bool(paVar2,"LP",&have_longpoll,false);
  paVar2 = api_add_diff(paVar2,"Network Difficulty",&current_diff,true);
  print_data(io_data,paVar2,isjson,false);
  uVar5 = extraout_r3;
  if (_Var1 && isjson) {
    uVar5 = true;
  }
  if (_Var1 && isjson) {
    io_data->close = (_Bool)uVar5;
  }
  return;
}


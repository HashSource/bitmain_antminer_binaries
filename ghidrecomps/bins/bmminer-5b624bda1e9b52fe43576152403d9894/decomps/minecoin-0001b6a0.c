
/* WARNING: Unknown calling convention */

void minecoin(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  _Bool io_open;
  api_data *paVar2;
  int iVar3;
  char *pcVar4;
  undefined uVar5;
  int iVar6;
  
  message(io_data,0x4e,0,(char *)0x0,isjson);
  pcVar4 = DAT_0001b774;
  if (isjson) {
    pcVar4 = DAT_0001b770;
  }
  _Var1 = io_add(io_data,pcVar4);
  iVar6 = 0;
  pcVar4 = DAT_0001b77c;
  paVar2 = api_add_const((api_data *)0x0,DAT_0001b778,DAT_0001b77c,false);
  iVar3 = pthread_mutex_lock(DAT_0001b780);
  if (iVar3 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_0001b788,(char *)0xe7c,pcVar4,iVar6);
  }
  pcVar4 = (char *)0xe7c;
  _rd_lock(DAT_0001b784,DAT_0001b788->__size,(char *)0xe7c,iVar6);
  iVar3 = pthread_mutex_unlock(DAT_0001b780);
  if (iVar3 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_0001b788,(char *)0xe7c,pcVar4,iVar6);
  }
  paVar2 = api_add_timeval(paVar2,DAT_0001b78c,DAT_0001b790,true);
  iVar6 = 1;
  pcVar4 = DAT_0001b798;
  paVar2 = api_add_string(paVar2,DAT_0001b794,DAT_0001b798,true);
  iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)DAT_0001b784);
  if (iVar3 != 0) {
    _rw_unlock(DAT_0001b788,(char *)0xe7f,pcVar4,iVar6);
  }
  (**DAT_0001b79c)();
  paVar2 = api_add_bool(paVar2,DAT_0001b7a0,DAT_0001b7a4,false);
  paVar2 = api_add_diff(paVar2,DAT_0001b7a8,DAT_0001b7ac,true);
  uVar5 = 0;
  print_data(io_data,paVar2,isjson,false);
  if (_Var1 && isjson) {
    uVar5 = true;
  }
  if (_Var1 && isjson) {
    io_data->close = (_Bool)uVar5;
  }
  return;
}


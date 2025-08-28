
/* WARNING: Unknown calling convention */

void addpool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  char *pcVar2;
  pool *pool;
  char *local_24;
  char *local_20;
  char *local_1c;
  
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x34,0,(char *)0x0,isjson);
  }
  else {
    _Var1 = pooldetails(param,&local_24,&local_20,&local_1c);
    if (_Var1) {
      pool = add_pool();
      detect_stratum(pool,local_24);
      add_pool_details(pool,true,local_24,local_20,local_1c);
      pcVar2 = escape_string(local_24,isjson);
      message(io_data,0x37,pool->pool_no,pcVar2,isjson);
      if (pcVar2 != local_24) {
        free(pcVar2);
      }
    }
    else {
      pcVar2 = escape_string(param,isjson);
      message(io_data,0x35,0,pcVar2,isjson);
      if (pcVar2 != param) {
        free(pcVar2);
      }
    }
  }
  return;
}


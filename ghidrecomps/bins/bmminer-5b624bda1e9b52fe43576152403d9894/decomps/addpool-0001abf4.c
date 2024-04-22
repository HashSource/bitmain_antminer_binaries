
/* WARNING: Unknown calling convention */

void addpool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  char *pcVar2;
  char *ptr;
  pool *pool_00;
  pool *pool;
  char *url;
  char *user;
  char *pass;
  
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x34,0,(char *)0x0,isjson);
  }
  else {
    _Var1 = pooldetails(param,&url,&user,&pass);
    if (_Var1) {
      pool_00 = add_pool();
      detect_stratum(pool_00,url);
      add_pool_details(pool_00,true,url,user,pass);
      pcVar2 = escape_string(url,isjson);
      message(io_data,0x37,pool_00->pool_no,pcVar2,isjson);
      if (pcVar2 != url) {
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



void addpool(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool _Var1;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  char *pass;
  char *user;
  char *url;
  char *ptr;
  pool *pool;
  
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x34,0,(char *)0x0,isjson);
  }
  else {
    _Var1 = pooldetails(param,&url,&user,&pass);
    if (_Var1) {
      pool = add_pool();
      detect_stratum(pool,url);
      add_pool_details(pool,true,url,user,pass);
      ptr = escape_string(url,isjson);
      message(io_data,0x37,pool->pool_no,ptr,isjson);
      if (ptr != url) {
        free(ptr);
      }
    }
    else {
      ptr = escape_string(param,isjson);
      message(io_data,0x35,0,ptr,isjson);
      if (ptr != param) {
        free(ptr);
      }
    }
  }
  return;
}


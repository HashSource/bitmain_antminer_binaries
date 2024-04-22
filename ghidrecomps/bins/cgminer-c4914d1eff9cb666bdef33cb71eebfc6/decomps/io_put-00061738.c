
_Bool io_put(io_data *io_data,char *buf)

{
  _Bool _Var1;
  char *buf_local;
  io_data *io_data_local;
  
  io_reinit(io_data);
  _Var1 = io_add(io_data,buf);
  return _Var1;
}


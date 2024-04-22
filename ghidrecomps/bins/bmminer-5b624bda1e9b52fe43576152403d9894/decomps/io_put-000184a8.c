
/* WARNING: Unknown calling convention */

_Bool io_put(io_data *io_data,char *buf)

{
  _Bool _Var1;
  
  io_data->cur = io_data->ptr;
  *io_data->ptr = '\0';
  io_data->close = false;
  _Var1 = io_add(io_data,buf);
  return _Var1;
}


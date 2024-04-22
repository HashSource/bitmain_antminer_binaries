
void ascdev(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int iVar1;
  int paramid;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  int id;
  int numasc;
  _Bool io_open;
  
  io_open = false;
  iVar1 = numascs();
  if (iVar1 == 0) {
    message(io_data,0x69,0,(char *)0x0,isjson);
  }
  else if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0xf,0,(char *)0x0,isjson);
  }
  else {
    paramid = atoi(param);
    if ((paramid < 0) || (iVar1 <= paramid)) {
      message(io_data,0x6b,paramid,(char *)0x0,isjson);
    }
    else {
      message(io_data,0x6a,paramid,(char *)0x0,isjson);
      if (isjson) {
        io_open = io_add(io_data,",\"ASC\":[");
      }
      ascstatus(io_data,paramid,isjson,false);
      if ((isjson) && (io_open != false)) {
        io_close(io_data);
      }
    }
  }
  return;
}


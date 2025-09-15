
void edevstatus(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int iVar1;
  _Bool precom;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  int numpga;
  int numasc;
  int i;
  int devcount;
  _Bool io_open;
  
  io_open = false;
  devcount = 0;
  iVar1 = numascs();
  if (iVar1 == 0) {
    message(io_data,10,0,(char *)0x0,isjson);
  }
  else {
    message(io_data,9,0,(char *)0x0,isjson);
    if (isjson) {
      io_open = io_add(io_data,",\"DEVS\":[");
    }
    if (0 < iVar1) {
      for (i = 0; i < iVar1; i = i + 1) {
        if ((isjson) && (0 < devcount)) {
          precom = true;
        }
        else {
          precom = false;
        }
        ascstatus(io_data,i,isjson,precom);
        devcount = devcount + 1;
      }
    }
    if ((isjson) && (io_open != false)) {
      io_close(io_data);
    }
  }
  return;
}


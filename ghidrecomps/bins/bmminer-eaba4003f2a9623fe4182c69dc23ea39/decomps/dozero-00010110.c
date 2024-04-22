
void dozero(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  _Bool dosum;
  _Bool bs;
  _Bool all;
  char *sum;
  
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x5e,0,(char *)0x0,isjson);
  }
  else {
    sum = strchr(param,0x2c);
    if (sum != (char *)0x0) {
      *sum = '\0';
      sum = sum + 1;
    }
    if ((sum == (char *)0x0) || (*sum == '\0')) {
      message(io_data,0x4b,0,(char *)0x0,isjson);
    }
    else {
      bVar2 = false;
      bVar3 = false;
      iVar4 = strcasecmp(param,"all");
      if (iVar4 == 0) {
        bVar2 = true;
      }
      else {
        iVar4 = strcasecmp(param,"bestshare");
        if (iVar4 == 0) {
          bVar3 = true;
        }
      }
      if ((bVar2) || (bVar3)) {
        iVar4 = tolower((uint)(byte)*sum);
        *sum = (char)iVar4;
        if ((*sum == 't') || (*sum == 'f')) {
          cVar1 = *sum;
          if (cVar1 == 't') {
            print_summary();
          }
          if (bVar2) {
            zero_stats();
          }
          if (bVar3) {
            zero_bestshare();
          }
          if (cVar1 == 't') {
            if (bVar2) {
              pcVar5 = "All";
            }
            else {
              pcVar5 = "BestShare";
            }
            message(io_data,0x60,0,pcVar5,isjson);
          }
          else {
            if (bVar2) {
              pcVar5 = "All";
            }
            else {
              pcVar5 = "BestShare";
            }
            message(io_data,0x61,0,pcVar5,isjson);
          }
        }
        else {
          message(io_data,0x4c,0,(char *)0x0,isjson);
        }
      }
      else {
        message(io_data,0x5f,0,param,isjson);
      }
    }
  }
  return;
}


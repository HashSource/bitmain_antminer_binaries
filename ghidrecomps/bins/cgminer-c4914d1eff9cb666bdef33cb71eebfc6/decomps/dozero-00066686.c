
void dozero(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
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
    pcVar4 = strchr(param,0x2c);
    sum = pcVar4;
    if (pcVar4 != (char *)0x0) {
      sum = pcVar4 + 1;
      *pcVar4 = '\0';
    }
    if ((sum == (char *)0x0) || (*sum == '\0')) {
      message(io_data,0x4b,0,(char *)0x0,isjson);
    }
    else {
      bVar2 = false;
      bVar3 = false;
      iVar5 = strcasecmp(param,"all");
      if (iVar5 == 0) {
        bVar2 = true;
      }
      else {
        iVar5 = strcasecmp(param,"bestshare");
        if (iVar5 == 0) {
          bVar3 = true;
        }
      }
      if ((bVar2) || (bVar3)) {
        iVar5 = tolower((uint)(byte)*sum);
        *sum = (char)iVar5;
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
              pcVar4 = "All";
            }
            else {
              pcVar4 = "BestShare";
            }
            message(io_data,0x60,0,pcVar4,isjson);
          }
          else {
            if (bVar2) {
              pcVar4 = "All";
            }
            else {
              pcVar4 = "BestShare";
            }
            message(io_data,0x61,0,pcVar4,isjson);
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


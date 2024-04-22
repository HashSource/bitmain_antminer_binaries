
void dozero(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  char *pcVar5;
  int iVar6;
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
    pcVar5 = strchr(param,0x2c);
    sum = pcVar5;
    if (pcVar5 != (char *)0x0) {
      sum = pcVar5 + 1;
      *pcVar5 = '\0';
    }
    if ((sum == (char *)0x0) || (*sum == '\0')) {
      message(io_data,0x4b,0,(char *)0x0,isjson);
    }
    else {
      bVar3 = false;
      bVar4 = false;
      iVar6 = strcasecmp(param,"all");
      if (iVar6 == 0) {
        bVar3 = true;
      }
      else {
        iVar6 = strcasecmp(param,"bestshare");
        if (iVar6 == 0) {
          bVar4 = true;
        }
      }
      if ((bVar3) || (bVar4)) {
        iVar6 = tolower((uint)(byte)*sum);
        *sum = (char)iVar6;
        if ((*sum == 't') || (*sum == 'f')) {
          cVar1 = *sum;
          if (cVar1 == 't') {
            print_summary();
          }
          if (bVar3) {
            zero_stats();
          }
          if (bVar4) {
            zero_bestshare();
          }
          if (cVar1 == 't') {
            if (bVar3) {
              uVar2 = 0xe324;
            }
            else {
              uVar2 = 0xe328;
            }
            message(io_data,0x60,0,(char *)(uVar2 | 0xa0000),isjson);
          }
          else {
            if (bVar3) {
              uVar2 = 0xe324;
            }
            else {
              uVar2 = 0xe328;
            }
            message(io_data,0x61,0,(char *)(uVar2 | 0xa0000),isjson);
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



/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

void dozero(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  char *pcVar5;
  char *sum;
  int iVar6;
  __int32_t **pp_Var7;
  _Bool dosum;
  
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x5e,0,(char *)0x0,isjson);
    return;
  }
  pcVar5 = strchr(param,0x2c);
  if (((pcVar5 != (char *)0x0) && (*pcVar5 = '\0', pcVar5 != (char *)0xffffffff)) &&
     (bVar1 = pcVar5[1], bVar1 != 0)) {
    iVar6 = strcasecmp(param,DAT_0001a184);
    if (iVar6 == 0) {
      bVar3 = true;
      bVar4 = false;
    }
    else {
      iVar6 = strcasecmp(param,DAT_0001a188);
      if (iVar6 != 0) {
        message(io_data,0x5f,0,param,isjson);
        return;
      }
      bVar4 = true;
      bVar3 = false;
    }
    pp_Var7 = __ctype_tolower_loc();
    cVar2 = *(char *)(*pp_Var7 + bVar1);
    pcVar5[1] = cVar2;
    if (cVar2 != 'f' && cVar2 != 't') {
      message(io_data,0x4c,0,(char *)0x0,isjson);
      return;
    }
    if (cVar2 == 't') {
      print_summary();
    }
    if (bVar3) {
      zero_stats();
    }
    if (bVar4) {
      zero_bestshare();
    }
    if (cVar2 != 't') {
      pcVar5 = DAT_0001a190;
      if (!bVar3) {
        pcVar5 = DAT_0001a18c;
      }
      message(io_data,0x61,0,pcVar5,isjson);
      return;
    }
    pcVar5 = DAT_0001a190;
    if (!bVar3) {
      pcVar5 = DAT_0001a18c;
    }
    message(io_data,0x60,0,pcVar5,isjson);
    return;
  }
  message(io_data,0x4b,0,(char *)0x0,isjson);
  return;
}


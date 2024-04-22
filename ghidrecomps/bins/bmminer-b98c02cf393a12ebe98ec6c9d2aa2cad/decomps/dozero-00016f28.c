
void dozero(undefined4 param_1,undefined4 param_2,char *param_3)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  char *pcVar5;
  int iVar6;
  __int32_t **pp_Var7;
  
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    message(param_1,0x5e,0);
    return;
  }
  pcVar5 = strchr(param_3,0x2c);
  if (((pcVar5 != (char *)0x0) && (*pcVar5 = '\0', pcVar5 != (char *)0xffffffff)) &&
     (bVar1 = pcVar5[1], bVar1 != 0)) {
    iVar6 = strcasecmp(param_3,"all");
    if (iVar6 == 0) {
      bVar3 = true;
      bVar4 = false;
    }
    else {
      iVar6 = strcasecmp(param_3,"bestshare");
      if (iVar6 != 0) {
        message(param_1,0x5f,0,param_3);
        return;
      }
      bVar4 = true;
      bVar3 = false;
    }
    pp_Var7 = __ctype_tolower_loc();
    cVar2 = *(char *)(*pp_Var7 + bVar1);
    pcVar5[1] = cVar2;
    if (cVar2 != 't' && cVar2 != 'f') {
      message(param_1,0x4c,0);
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
    pcVar5 = "BestShare";
    if (bVar3) {
      pcVar5 = "All";
    }
    if (cVar2 == 't') {
      message(param_1,0x60,0,pcVar5);
      return;
    }
    message(param_1,0x61,0,pcVar5);
    return;
  }
  message(param_1,0x4b,0);
  return;
}


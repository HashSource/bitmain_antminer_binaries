
void checkcommand(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  bool bVar1;
  bool bVar2;
  _Bool _Var3;
  int iVar4;
  int iVar5;
  api_data *paVar6;
  char *pcVar7;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  char cmdbuf [100];
  _Bool io_open;
  api_data *root;
  int i;
  _Bool access;
  _Bool found;
  
  if ((param == (char *)0x0) || (*param == '\0')) {
    message(io_data,0x47,0,(char *)0x0,isjson);
  }
  else {
    bVar1 = false;
    bVar2 = false;
    for (i = 0; cmds[i].name != (char *)0x0; i = i + 1) {
      iVar4 = strcmp(cmds[i].name,param);
      if (iVar4 == 0) {
        bVar1 = true;
        sprintf(cmdbuf,"|%s|",param);
        iVar4 = toupper((uint)(byte)group);
        iVar5 = toupper(0x57);
        if (iVar4 != iVar5) {
          iVar4 = toupper((uint)(byte)group);
          iVar5 = toupper(0x41);
          pcVar7 = strstr(apigroups[iVar4 - iVar5].commands,cmdbuf);
          if (pcVar7 == (char *)0x0) break;
        }
        bVar2 = true;
        break;
      }
    }
    message(io_data,0x48,0,(char *)0x0,isjson);
    if (isjson) {
      pcVar7 = ",\"CHECK\":[";
    }
    else {
      pcVar7 = "CHECK,";
    }
    _Var3 = io_add(io_data,pcVar7);
    pcVar7 = NO;
    if (bVar1) {
      pcVar7 = YES;
    }
    paVar6 = api_add_const((api_data *)0x0,"Exists",pcVar7,false);
    pcVar7 = NO;
    if (bVar2) {
      pcVar7 = YES;
    }
    paVar6 = api_add_const(paVar6,"Access",pcVar7,false);
    print_data(io_data,paVar6,isjson,false);
    if ((isjson) && (_Var3)) {
      io_close(io_data);
    }
  }
  return;
}


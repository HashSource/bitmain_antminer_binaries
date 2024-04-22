
void checkcommand(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  _Bool _Var4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  api_data *paVar8;
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
    bVar2 = false;
    bVar3 = false;
    for (i = 0; cmds[i].name != (char *)0x0; i = i + 1) {
      iVar5 = strcmp(cmds[i].name,param);
      if (iVar5 == 0) {
        bVar2 = true;
        sprintf(cmdbuf,"|%s|",param);
        iVar5 = toupper((uint)(byte)group);
        iVar6 = toupper(0x57);
        if (iVar5 != iVar6) {
          iVar5 = toupper((uint)(byte)group);
          iVar6 = toupper(0x41);
          pcVar7 = strstr(apigroups[iVar5 - iVar6].commands,cmdbuf);
          if (pcVar7 == (char *)0x0) break;
        }
        bVar3 = true;
        break;
      }
    }
    message(io_data,0x48,0,(char *)0x0,isjson);
    if (isjson) {
      uVar1 = 0xe570;
    }
    else {
      uVar1 = 0xe57c;
    }
    _Var4 = io_add(io_data,(char *)(uVar1 | 0xa0000));
    pcVar7 = NO;
    if (bVar2) {
      pcVar7 = YES;
    }
    paVar8 = api_add_const((api_data *)0x0,"Exists",pcVar7,false);
    pcVar7 = NO;
    if (bVar3) {
      pcVar7 = YES;
    }
    paVar8 = api_add_const(paVar8,"Access",pcVar7,false);
    print_data(io_data,paVar8,isjson,false);
    if ((isjson) && (_Var4)) {
      io_close(io_data);
    }
  }
  return;
}


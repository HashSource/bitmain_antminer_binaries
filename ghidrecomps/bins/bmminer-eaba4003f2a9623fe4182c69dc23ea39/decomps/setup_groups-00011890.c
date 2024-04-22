
/* WARNING: Unknown calling convention */

void setup_groups(void)

{
  bool bVar1;
  bool bVar2;
  size_t sVar3;
  char *__dest;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char tmp42 [2048];
  char cmdbuf [100];
  char commands [8192];
  char group;
  char *buf;
  char *api_groups;
  int i;
  _Bool did;
  _Bool addstar;
  char *cmd;
  char *colon;
  char *next;
  char *ptr;
  
  pcVar9 = BLANK;
  if (opt_api_groups != (char *)0x0) {
    pcVar9 = opt_api_groups;
  }
  sVar3 = strlen(pcVar9);
  __dest = (char *)_cgmalloc(sVar3 + 1,"api-btm.c","setup_groups",0x11f1);
  strcpy(__dest,pcVar9);
  next = __dest;
  do {
    pcVar9 = next;
    if ((next == (char *)0x0) || (*next == '\0')) {
      commands[0] = SEPARATOR;
      cmd = commands + 1;
      commands[1] = '\0';
      for (i = 0; cmds[i].name != (char *)0x0; i = i + 1) {
        if (cmds[i].iswritemode != true) {
          strcpy(cmd,cmds[i].name);
          sVar3 = strlen(cmds[i].name);
          cmd[sVar3] = SEPARATOR;
          cmd = cmd + sVar3 + 1;
          *cmd = '\0';
        }
      }
      iVar7 = toupper(0x52);
      iVar7 = toupper(iVar7);
      iVar8 = toupper(0x41);
      sVar3 = strlen(commands);
      pcVar9 = (char *)_cgmalloc(sVar3 + 1,"api-btm.c","setup_groups",0x126b);
      apigroups[iVar7 - iVar8].commands = pcVar9;
      strcpy(apigroups[iVar7 - iVar8].commands,commands);
      free(__dest);
      return;
    }
    next = strchr(next,0x2c);
    if (next != (char *)0x0) {
      *next = '\0';
      next = next + 1;
    }
    if (pcVar9[1] != ':') {
      pcVar4 = strchr(pcVar9,0x3a);
      if (pcVar4 != (char *)0x0) {
        *pcVar4 = '\0';
      }
      snprintf(tmp42,0x800,"API invalid group name \'%s\'",pcVar9);
      _applog(3,tmp42,true);
      _quit(1);
    }
    uVar5 = toupper((uint)(byte)*pcVar9);
    iVar7 = toupper(uVar5 & 0xff);
    iVar8 = toupper(0x41);
    if (iVar7 < iVar8) {
LAB_00011a5a:
      snprintf(tmp42,0x800,"API invalid group name \'%c\'",(uint)(byte)*pcVar9);
      _applog(3,tmp42,true);
      _quit(1);
    }
    else {
      iVar7 = toupper(uVar5 & 0xff);
      iVar8 = toupper(0x5a);
      if (iVar8 < iVar7) goto LAB_00011a5a;
    }
    uVar6 = toupper(0x57);
    if ((uVar5 & 0xff) == uVar6) {
      iVar7 = toupper(0x57);
      snprintf(tmp42,0x800,"API group name can\'t be \'%c\'",iVar7);
      _applog(3,tmp42,true);
      _quit(1);
    }
    uVar6 = toupper(0x52);
    if ((uVar5 & 0xff) == uVar6) {
      iVar7 = toupper(0x52);
      snprintf(tmp42,0x800,"API group name can\'t be \'%c\'",iVar7);
      _applog(3,tmp42,true);
      _quit(1);
    }
    iVar7 = toupper(uVar5 & 0xff);
    iVar8 = toupper(0x41);
    if (apigroups[iVar7 - iVar8].commands != (char *)0x0) {
      snprintf(tmp42,0x800,"API duplicate group name \'%c\'",(uint)(byte)*pcVar9);
      _applog(3,tmp42,true);
      _quit(1);
    }
    commands[0] = SEPARATOR;
    cmd = commands + 1;
    commands[1] = '\0';
    bVar2 = false;
    ptr = pcVar9 + 2;
    while ((ptr != (char *)0x0 && (*ptr != '\0'))) {
      colon = strchr(ptr,0x3a);
      if (colon != (char *)0x0) {
        *colon = '\0';
        colon = colon + 1;
      }
      iVar7 = strcmp(ptr,"*");
      if (iVar7 == 0) {
        bVar2 = true;
      }
      else {
        bVar1 = false;
        for (i = 0; cmds[i].name != (char *)0x0; i = i + 1) {
          iVar7 = strcasecmp(ptr,cmds[i].name);
          if (iVar7 == 0) {
            bVar1 = true;
            break;
          }
        }
        if (bVar1) {
          sprintf(cmdbuf,"|%s|",cmds[i].name);
          pcVar9 = strstr(commands,cmdbuf);
          if (pcVar9 == (char *)0x0) {
            strcpy(cmd,cmds[i].name);
            sVar3 = strlen(cmds[i].name);
            cmd[sVar3] = SEPARATOR;
            cmd = cmd + sVar3 + 1;
            *cmd = '\0';
          }
        }
        else {
          snprintf(tmp42,0x800,"API unknown command \'%s\' in group \'%c\'",ptr,uVar5 & 0xff);
          _applog(3,tmp42,true);
          _quit(1);
        }
      }
      ptr = colon;
    }
    if (bVar2) {
      for (i = 0; cmds[i].name != (char *)0x0; i = i + 1) {
        if (cmds[i].iswritemode != true) {
          sprintf(cmdbuf,"|%s|",cmds[i].name);
          pcVar9 = strstr(commands,cmdbuf);
          if (pcVar9 == (char *)0x0) {
            strcpy(cmd,cmds[i].name);
            sVar3 = strlen(cmds[i].name);
            cmd[sVar3] = SEPARATOR;
            cmd = cmd + sVar3 + 1;
            *cmd = '\0';
          }
        }
      }
    }
    iVar7 = toupper(uVar5 & 0xff);
    iVar8 = toupper(0x41);
    sVar3 = strlen(commands);
    pcVar9 = (char *)_cgmalloc(sVar3 + 1,"api-btm.c","setup_groups",0x1257);
    apigroups[iVar7 - iVar8].commands = pcVar9;
    strcpy(apigroups[iVar7 - iVar8].commands,commands);
  } while( true );
}


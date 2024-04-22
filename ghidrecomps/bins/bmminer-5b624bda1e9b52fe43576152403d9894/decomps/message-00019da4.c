
/* WARNING: Unknown calling convention */

void message(io_data *io_data,int messageid,int paramid,char *param2,_Bool isjson)

{
  int *piVar1;
  api_data *paVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int local_202c;
  char severity [2];
  int id;
  char buf [8192];
  
  local_202c = messageid;
  if (isjson) {
    io_add(io_data,DAT_00019fb0);
  }
  iVar5 = *DAT_00019f84;
  if (iVar5 == 4) {
LAB_00019dea:
    paVar2 = api_add_string((api_data *)0x0,DAT_00019f88,DAT_00019f8c,false);
    paVar2 = api_add_time(paVar2,DAT_00019f90,DAT_00019f94,false);
    id = -1;
    paVar2 = api_add_int(paVar2,DAT_00019f98,&id,false);
    sprintf(buf,DAT_00019f9c,local_202c);
  }
  else {
    if (DAT_00019f84[1] == local_202c) {
      iVar6 = 0;
    }
    else {
      iVar6 = 0;
      piVar3 = DAT_00019f84;
      do {
        iVar5 = piVar3[4];
        iVar6 = iVar6 + 1;
        if (iVar5 == 4) goto LAB_00019dea;
        piVar1 = piVar3 + 5;
        piVar3 = piVar3 + 4;
      } while (*piVar1 != local_202c);
    }
    if (iVar5 == 2) {
      severity[0] = 'I';
    }
    else if (iVar5 == 3) {
      severity[0] = 'S';
    }
    else if (iVar5 == 1) {
      severity[0] = 'W';
    }
    else {
      severity[0] = 'E';
    }
    severity[1] = '\0';
    switch(DAT_00019f84[iVar6 * 4 + 2]) {
    case 0:
    case 1:
    case 2:
    case 0xe:
      sprintf(buf,(char *)DAT_00019f84[iVar6 * 4 + 3],paramid);
      break;
    default:
      strcpy(buf,(char *)DAT_00019f84[iVar6 * 4 + 3]);
      break;
    case 5:
      sprintf(buf,(char *)DAT_00019f84[iVar6 * 4 + 3],*DAT_00019fb4);
      break;
    case 6:
      sprintf(buf,(char *)DAT_00019f84[iVar6 * 4 + 3],paramid,*DAT_00019fb4 + -1);
      break;
    case 7:
      sprintf(buf,(char *)DAT_00019f84[iVar6 * 4 + 3]);
      break;
    case 8:
      sprintf(buf,(char *)DAT_00019f84[iVar6 * 4 + 3],DAT_00019fb8);
      break;
    case 9:
      sprintf(buf,(char *)DAT_00019f84[iVar6 * 4 + 3],paramid,
              *(undefined4 *)(*(int *)(*DAT_00019fbc + paramid * 4) + 0xa4));
      break;
    case 10:
      sprintf(buf,(char *)DAT_00019f84[iVar6 * 4 + 3],param2);
      break;
    case 0xb:
      sprintf(buf,(char *)DAT_00019f84[iVar6 * 4 + 3],paramid,param2);
      break;
    case 0xc:
      uVar4 = DAT_00019fc4;
      if (paramid != 0) {
        uVar4 = DAT_00019fc0;
      }
      sprintf(buf,(char *)DAT_00019f84[iVar6 * 4 + 3],uVar4);
      break;
    case 0xd:
      sprintf(buf,(char *)DAT_00019f84[iVar6 * 4 + 3],param2,paramid);
    }
    paVar2 = api_add_string((api_data *)0x0,DAT_00019f88,severity,false);
    paVar2 = api_add_time(paVar2,DAT_00019f90,DAT_00019f94,false);
    paVar2 = api_add_int(paVar2,DAT_00019f98,&local_202c,false);
  }
  paVar2 = api_add_escape(paVar2,DAT_00019fa0,buf,false);
  paVar2 = api_add_escape(paVar2,DAT_00019fa8,*DAT_00019fa4,false);
  print_data(io_data,paVar2,isjson,false);
  if (isjson) {
    io_add(io_data,DAT_00019fac);
  }
  return;
}


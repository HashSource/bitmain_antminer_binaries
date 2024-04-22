
/* WARNING: Unknown calling convention */

void poolstatus(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  int *piVar1;
  int *piVar2;
  _Bool _Var3;
  time_t tVar4;
  uint uVar5;
  char *pcVar6;
  undefined precom;
  int iVar7;
  pool *pool;
  int iVar8;
  api_data *paVar9;
  char *lp;
  double dVar10;
  double dVar11;
  char *status;
  int i;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined4 local_130;
  undefined4 uStack_12c;
  char lasttime [256];
  
  piVar1 = DAT_0001c004;
  memset(lasttime,0,0x100);
  if (*piVar1 == 0) {
    message(io_data,8,0,(char *)0x0,isjson);
  }
  else {
    message(io_data,7,0,(char *)0x0,isjson);
    if (isjson) {
      _Var3 = io_add(io_data,DAT_0001c028);
    }
    else {
      _Var3 = false;
    }
    piVar2 = DAT_0001c008;
    i = 0;
    if (0 < *piVar1) {
      paVar9 = (api_data *)0x0;
      do {
        iVar8 = *(int *)(*piVar2 + i * 4);
        if (*(char *)(iVar8 + 0x69) == '\0') {
          iVar7 = *(int *)(iVar8 + 100);
          if (iVar7 == 1) {
            status = DAT_0001bffc;
            if (*(char *)(iVar8 + 0x61) != '\0') {
              status = DAT_0001c000;
            }
          }
          else if (iVar7 == 0) {
            status = DAT_0001bf78;
          }
          else {
            status = DAT_0001bff4;
            if (iVar7 != 2) {
              status = DAT_0001bff8;
            }
          }
          pcVar6 = DAT_0001bf7c;
          if (*(int *)(iVar8 + 0x6c) != 0) {
            pcVar6 = DAT_0001bf80;
          }
          if (*(int *)(iVar8 + 0x160) < 1) {
            lasttime[0] = '0';
            lasttime[1] = '\0';
          }
          else {
            tVar4 = time((time_t *)0x0);
            uVar5 = tVar4 - *(int *)(iVar8 + 0x160);
            uVar5 = uVar5 & ~((int)uVar5 >> 0x1f);
            iVar7 = (int)uVar5 % 0xe10;
            sprintf(lasttime,DAT_0001bf84,(int)uVar5 / 0xe10,iVar7 / 0x3c,iVar7 % 0x3c);
          }
          paVar9 = api_add_int(paVar9,DAT_0001bf88,&i,false);
          paVar9 = api_add_escape(paVar9,DAT_0001bf8c,*(char **)(iVar8 + 0xa4),false);
          paVar9 = api_add_string(paVar9,DAT_0001bf90,status,false);
          paVar9 = api_add_int(paVar9,DAT_0001bf94,(int *)(iVar8 + 4),false);
          paVar9 = api_add_int(paVar9,DAT_0001bf98,(int *)(iVar8 + 0x38),false);
          paVar9 = api_add_string(paVar9,DAT_0001bf9c,pcVar6,false);
          paVar9 = api_add_uint(paVar9,DAT_0001bfa0,(uint *)(iVar8 + 0x74),false);
          paVar9 = api_add_int64(paVar9,DAT_0001bfa4,(int64_t *)(iVar8 + 8),false);
          paVar9 = api_add_int64(paVar9,DAT_0001bfa8,(int64_t *)(iVar8 + 0x10),false);
          paVar9 = api_add_uint(paVar9,DAT_0001bfac,(uint *)(iVar8 + 0x7c),false);
          paVar9 = api_add_uint(paVar9,DAT_0001bfb0,(uint *)(iVar8 + 0x78),false);
          paVar9 = api_add_uint(paVar9,DAT_0001bfb4,(uint *)(iVar8 + 0x80),false);
          paVar9 = api_add_uint(paVar9,DAT_0001bfb8,(uint *)(iVar8 + 0x84),false);
          paVar9 = api_add_escape(paVar9,DAT_0001bfbc,*(char **)(iVar8 + 0xac),false);
          paVar9 = api_add_string(paVar9,DAT_0001bfc0,lasttime,false);
          paVar9 = api_add_string(paVar9,DAT_0001bfc4,(char *)(iVar8 + 0x30),false);
          paVar9 = api_add_int64(paVar9,DAT_0001bfc8,(int64_t *)(iVar8 + 0x28),false);
          if (*(int *)(iVar8 + 0xb8) == 0) {
            paVar9 = api_add_const(paVar9,DAT_0001bfcc,DAT_0001bff0,false);
            paVar9 = api_add_const(paVar9,DAT_0001bfd0,DAT_0001bff0,false);
          }
          else {
            pcVar6 = proxytype(*(proxytypes_t *)(iVar8 + 0xb4));
            paVar9 = api_add_const(paVar9,DAT_0001bfcc,pcVar6,false);
            paVar9 = api_add_escape(paVar9,DAT_0001bfd0,*(char **)(iVar8 + 0xb8),false);
          }
          paVar9 = api_add_diff(paVar9,DAT_0001bfd4,(double *)(iVar8 + 0x48),false);
          paVar9 = api_add_diff(paVar9,DAT_0001bfd8,(double *)(iVar8 + 0x50),false);
          paVar9 = api_add_diff(paVar9,DAT_0001bfdc,(double *)(iVar8 + 0x58),false);
          paVar9 = api_add_diff(paVar9,DAT_0001bfe0,(double *)(iVar8 + 0x168),false);
          paVar9 = api_add_bool(paVar9,DAT_0001bfe4,(_Bool *)(iVar8 + 0x280),false);
          paVar9 = api_add_bool(paVar9,DAT_0001bfe8,(_Bool *)(iVar8 + 0x281),false);
          if (*(char *)(iVar8 + 0x281) == '\0') {
            paVar9 = api_add_const(paVar9,DAT_0001bfec,DAT_0001bff0,false);
          }
          else {
            paVar9 = api_add_escape(paVar9,DAT_0001bfec,*(char **)(iVar8 + 0x240),false);
          }
          paVar9 = api_add_bool(paVar9,DAT_0001bf68,(_Bool *)(iVar8 + 0x2e0),false);
          paVar9 = api_add_uint64(paVar9,DAT_0001bf6c,(uint64_t *)(iVar8 + 0x170),true);
          dVar10 = *(double *)(iVar8 + 0x50) + *(double *)(iVar8 + 0x48) + *(double *)(iVar8 + 0x58)
          ;
          dVar11 = DAT_0001bf60;
          if (dVar10 != 0.0) {
            dVar11 = *(double *)(iVar8 + 0x50) / dVar10;
          }
          uStack_134 = (undefined4)((ulonglong)dVar11 >> 0x20);
          local_138 = SUB84(dVar11,0);
          paVar9 = api_add_percent(paVar9,DAT_0001bf70,(double *)&local_138,false);
          dVar10 = *(double *)(iVar8 + 0x48) + *(double *)(iVar8 + 0x50) + *(double *)(iVar8 + 0x58)
          ;
          dVar11 = DAT_0001bf60;
          if (dVar10 != 0.0) {
            dVar11 = *(double *)(iVar8 + 0x58) / dVar10;
          }
          uStack_12c = (undefined4)((ulonglong)dVar11 >> 0x20);
          local_130 = SUB84(dVar11,0);
          paVar9 = api_add_percent(paVar9,DAT_0001bf74,(double *)&local_130,false);
          precom = isjson;
          if (isjson) {
            iVar8 = i;
            if (i < 1) {
              iVar8 = 0;
            }
            precom = (undefined)iVar8;
            if (0 < i) {
              precom = true;
            }
          }
          paVar9 = print_data(io_data,paVar9,isjson,(_Bool)precom);
        }
        i = i + 1;
      } while (i < *piVar1);
    }
    if (_Var3 != false) {
      io_data->close = true;
    }
  }
  return;
}


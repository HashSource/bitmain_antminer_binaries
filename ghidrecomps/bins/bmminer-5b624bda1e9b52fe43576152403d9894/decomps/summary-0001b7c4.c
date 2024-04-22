
/* WARNING: Unknown calling convention */

void summary(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  double *pdVar1;
  double *pdVar2;
  undefined8 *puVar3;
  int64_t *piVar4;
  double *pdVar5;
  uint *data;
  _Bool _Var6;
  int iVar7;
  api_data *paVar8;
  char *buf;
  uint uVar9;
  char *func;
  uint uVar10;
  time_t *func_00;
  char *line;
  uint uVar11;
  int line_00;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  undefined8 uVar16;
  _Bool io_open;
  double utility;
  double ghs;
  double work_utility;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  double dStack_38;
  
  func = (char *)0x0;
  message(io_data,0xb,0,(char *)0x0,isjson);
  buf = DAT_0001bac4;
  if (isjson) {
    buf = DAT_0001bac0;
  }
  line = DAT_0001bac0;
  _Var6 = io_add(io_data,buf);
  iVar7 = pthread_mutex_lock(DAT_0001bac8);
  if (iVar7 != 0) {
    _mutex_lock(DAT_0001bc18,(char *)0xaf2,func,(int)line);
  }
  pdVar5 = DAT_0001bb64;
  puVar3 = DAT_0001bad4;
  pdVar2 = DAT_0001bad0;
  pdVar1 = DAT_0001bacc;
  dVar12 = *DAT_0001bacc + *DAT_0001bad0 + *DAT_0001bb64;
  uVar16 = __aeabi_d2lz(SUB84(dVar12,0),(int)((ulonglong)dVar12 >> 0x20));
  piVar4 = DAT_0001bad8;
  *puVar3 = uVar16;
  dVar12 = (double)__aeabi_l2d(*(undefined4 *)piVar4,*(undefined4 *)((int)piVar4 + 4));
  data = DAT_0001bb8c;
  dVar15 = *DAT_0001badc;
  if (dVar15 == 0.0) {
    dVar14 = *DAT_0001bc14;
    utility = dVar12 * DAT_0001bc00;
    dVar13 = (*DAT_0001bc1c - *DAT_0001bc10) / DAT_0001bbf8;
    dVar12 = 1.0;
  }
  else {
    dVar14 = *DAT_0001bae4;
    dVar13 = (*DAT_0001bb50 - *DAT_0001bae0) / DAT_0001bab0;
    utility = (dVar12 / dVar15) * DAT_0001bab8;
    dVar12 = dVar15;
  }
  ghs = dVar13 / (dVar15 - dVar14);
  dVar15 = (double)__aeabi_l2d((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
  work_utility = (dVar15 / dVar12) * DAT_0001bab8;
  paVar8 = api_add_elapsed((api_data *)0x0,DAT_0001bae8,DAT_0001badc,true);
  paVar8 = api_add_string(paVar8,DAT_0001baec,DAT_0001baf0,false);
  paVar8 = api_add_mhs(paVar8,DAT_0001baf4,&ghs,false);
  paVar8 = api_add_uint(paVar8,DAT_0001baf8,DAT_0001bafc,true);
  paVar8 = api_add_int64(paVar8,DAT_0001bb00,DAT_0001bb04,true);
  paVar8 = api_add_int64(paVar8,DAT_0001bb08,DAT_0001bad8,true);
  paVar8 = api_add_int64(paVar8,DAT_0001bb0c,DAT_0001bb10,true);
  paVar8 = api_add_int(paVar8,DAT_0001bb14,(int *)data,true);
  paVar8 = api_add_utility(paVar8,DAT_0001bb18,&utility,false);
  paVar8 = api_add_int64(paVar8,DAT_0001bb1c,DAT_0001bb20,true);
  paVar8 = api_add_int64(paVar8,DAT_0001bb24,DAT_0001bb28,true);
  paVar8 = api_add_uint(paVar8,DAT_0001bb2c,DAT_0001bb30,true);
  paVar8 = api_add_uint(paVar8,DAT_0001bb34,DAT_0001bb38,true);
  paVar8 = api_add_uint(paVar8,DAT_0001bb3c,DAT_0001bb40,true);
  paVar8 = api_add_uint(paVar8,DAT_0001bb44,DAT_0001bb48,true);
  paVar8 = api_add_mhtotal(paVar8,DAT_0001bb4c,DAT_0001bb50,true);
  paVar8 = api_add_utility(paVar8,DAT_0001bb54,&work_utility,false);
  paVar8 = api_add_diff(paVar8,DAT_0001bb58,DAT_0001bacc,true);
  paVar8 = api_add_diff(paVar8,DAT_0001bb5c,DAT_0001bad0,true);
  paVar8 = api_add_diff(paVar8,DAT_0001bb60,DAT_0001bb64,true);
  paVar8 = api_add_uint64(paVar8,DAT_0001bb68,DAT_0001bb6c,true);
  uVar9 = *data;
  uVar10 = *(uint *)puVar3 + uVar9;
  uVar11 = *(uint *)((int)puVar3 + 4) + ((int)uVar9 >> 0x1f) + (uint)CARRY4(*(uint *)puVar3,uVar9);
  dVar12 = DAT_0001bc08;
  if ((uVar10 | uVar11) != 0) {
    dVar12 = (double)__aeabi_l2d(uVar10,uVar11);
    dVar12 = (double)(longlong)(int)uVar9 / dVar12;
  }
  uStack_4c = (undefined4)((ulonglong)dVar12 >> 0x20);
  local_50 = SUB84(dVar12,0);
  paVar8 = api_add_percent(paVar8,DAT_0001bb70,(double *)&local_50,false);
  dVar12 = DAT_0001bc08;
  if ((*(uint *)puVar3 | *(uint *)((int)puVar3 + 4)) != 0) {
    dVar12 = (double)__aeabi_l2d();
    dVar12 = *pdVar2 / dVar12;
  }
  uStack_44 = (undefined4)((ulonglong)dVar12 >> 0x20);
  local_48 = SUB84(dVar12,0);
  paVar8 = api_add_percent(paVar8,DAT_0001bb74,(double *)&local_48,false);
  dVar15 = *pdVar2 + *pdVar1 + *pdVar5;
  dVar12 = DAT_0001bc08;
  if (dVar15 != 0.0) {
    dVar12 = *pdVar2 / dVar15;
  }
  uStack_3c = (undefined4)((ulonglong)dVar12 >> 0x20);
  local_40 = SUB84(dVar12,0);
  paVar8 = api_add_percent(paVar8,DAT_0001bb78,(double *)&local_40,false);
  dVar12 = *pdVar5;
  dVar15 = *pdVar1 + *pdVar2 + dVar12;
  dStack_38 = DAT_0001bc08;
  if (dVar15 != 0.0) {
    dStack_38 = dVar12 / dVar15;
  }
  paVar8 = api_add_percent(paVar8,DAT_0001bb7c,&dStack_38,false);
  line_00 = 0;
  func_00 = DAT_0001bb84;
  paVar8 = api_add_time(paVar8,DAT_0001bb80,DAT_0001bb84,false);
  iVar7 = pthread_mutex_unlock(DAT_0001bac8);
  if (iVar7 != 0) {
    _mutex_unlock_noyield(DAT_0001bc18,(char *)0xb24,(char *)func_00,line_00);
  }
  (**DAT_0001bb88)();
  print_data(io_data,paVar8,isjson,false);
  if (_Var6 && isjson) {
    io_data->close = true;
  }
  return;
}


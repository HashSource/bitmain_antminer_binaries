
int get_work(int param_1,undefined4 param_2)

{
  time_t tVar1;
  time_t tVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  int local_82c;
  undefined4 local_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  undefined4 uStack_804;
  
  local_82c = 0;
  iVar9 = *(int *)(param_1 + 0x24);
  thread_reportout();
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    local_828._0_1_ = s_Popping_work_from_get_queue_to_g_0005d970[0];
    local_828._1_1_ = s_Popping_work_from_get_queue_to_g_0005d970[1];
    local_828._2_1_ = s_Popping_work_from_get_queue_to_g_0005d970[2];
    local_828._3_1_ = s_Popping_work_from_get_queue_to_g_0005d970[3];
    uStack_824._0_1_ = s_Popping_work_from_get_queue_to_g_0005d970[4];
    uStack_824._1_1_ = s_Popping_work_from_get_queue_to_g_0005d970[5];
    uStack_824._2_1_ = s_Popping_work_from_get_queue_to_g_0005d970[6];
    uStack_824._3_1_ = s_Popping_work_from_get_queue_to_g_0005d970[7];
    uStack_820._0_1_ = s_Popping_work_from_get_queue_to_g_0005d970[8];
    uStack_820._1_1_ = s_Popping_work_from_get_queue_to_g_0005d970[9];
    uStack_820._2_1_ = s_Popping_work_from_get_queue_to_g_0005d970[10];
    uStack_820._3_1_ = s_Popping_work_from_get_queue_to_g_0005d970[11];
    uStack_81c._0_1_ = s_Popping_work_from_get_queue_to_g_0005d970[12];
    uStack_81c._1_1_ = s_Popping_work_from_get_queue_to_g_0005d970[13];
    uStack_81c._2_1_ = s_Popping_work_from_get_queue_to_g_0005d970[14];
    uStack_81c._3_1_ = s_Popping_work_from_get_queue_to_g_0005d970[15];
    local_818._0_1_ = s_Popping_work_from_get_queue_to_g_0005d970[16];
    local_818._1_1_ = s_Popping_work_from_get_queue_to_g_0005d970[17];
    local_818._2_1_ = s_Popping_work_from_get_queue_to_g_0005d970[18];
    local_818._3_1_ = s_Popping_work_from_get_queue_to_g_0005d970[19];
    uStack_814._0_1_ = s_Popping_work_from_get_queue_to_g_0005d970[20];
    uStack_814._1_1_ = s_Popping_work_from_get_queue_to_g_0005d970[21];
    uStack_814._2_1_ = s_Popping_work_from_get_queue_to_g_0005d970[22];
    uStack_814._3_1_ = s_Popping_work_from_get_queue_to_g_0005d970[23];
    uStack_810._0_1_ = s_Popping_work_from_get_queue_to_g_0005d970[24];
    uStack_810._1_1_ = s_Popping_work_from_get_queue_to_g_0005d970[25];
    uStack_810._2_1_ = s_Popping_work_from_get_queue_to_g_0005d970[26];
    uStack_810._3_1_ = s_Popping_work_from_get_queue_to_g_0005d970[27];
    uStack_80c._0_1_ = s_Popping_work_from_get_queue_to_g_0005d970[28];
    uStack_80c._1_1_ = s_Popping_work_from_get_queue_to_g_0005d970[29];
    uStack_80c._2_1_ = s_Popping_work_from_get_queue_to_g_0005d970[30];
    uStack_80c._3_1_ = s_Popping_work_from_get_queue_to_g_0005d970[31];
    local_808._0_1_ = s_Popping_work_from_get_queue_to_g_0005d970[32];
    local_808._1_1_ = s_Popping_work_from_get_queue_to_g_0005d970[33];
    local_808._2_1_ = s_Popping_work_from_get_queue_to_g_0005d970[34];
    local_808._3_1_ = s_Popping_work_from_get_queue_to_g_0005d970[35];
    uStack_804._0_1_ = s_Popping_work_from_get_queue_to_g_0005d970[36];
    uStack_804._1_1_ = s_Popping_work_from_get_queue_to_g_0005d970[37];
    uStack_804._2_1_ = s_Popping_work_from_get_queue_to_g_0005d970[38];
    uStack_804._3_1_ = s_Popping_work_from_get_queue_to_g_0005d970[39];
    _applog(7,&local_828,0);
  }
  tVar1 = time((time_t *)0x0);
  uVar7 = DAT_00023d04;
  while (local_82c == 0) {
    local_82c = hash_pop(1);
    iVar8 = stale_work(local_82c,0);
    if (iVar8 != 0) {
      _discard_work(&local_82c,"cgminer.c",uVar7,0x2168);
      wake_gws();
    }
  }
  tVar2 = time((time_t *)0x0);
  iVar8 = tVar2 - tVar1;
  cVar5 = opt_debug;
  if (0 < iVar8) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf((char *)&local_828,0x800,"Get work blocked for %d seconds",iVar8);
      _applog(7,&local_828,0);
    }
    cVar5 = opt_debug;
    *(int *)(iVar9 + 0xe8) = iVar8 + *(int *)(iVar9 + 0xe8);
  }
  if ((cVar5 != '\0') && (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))
     ) {
    snprintf((char *)&local_828,0x800,"Got work from get queue to get work for thread %d",param_2);
    _applog(7,&local_828,0);
  }
  cVar5 = opt_benchmark;
  *(undefined4 *)(local_82c + 0x100) = param_2;
  if (cVar5 == '\0') goto LAB_00023be4;
  iVar3 = *(int *)(iVar9 + 0x17c);
  iVar8 = *(int *)(iVar9 + 0x180) + iVar3;
  *(int *)(iVar9 + 0x17c) = iVar8;
  if (iVar8 < 1) {
    iVar3 = 1;
  }
  if (iVar8 < 1) {
    *(int *)(iVar9 + 0x180) = iVar3;
LAB_00023ce8:
    uVar7 = 0x2155;
    iVar3 = DAT_00023d00;
  }
  else {
    if (iVar8 < 0x10) goto LAB_00023ce8;
    iVar4 = -1;
    *(undefined4 *)(iVar9 + 0x180) = 0xffffffff;
    iVar3 = DAT_00023cf8;
    iVar6 = *(int *)(iVar9 + 0x178) + 1;
    bVar10 = *(int *)(iVar9 + 0x178) + -0xe < 0;
    if (0xf < iVar6) {
      iVar4 = 0;
    }
    iVar8 = iVar4;
    if (iVar6 == 0xf || bVar10 != SBORROW4(iVar6,0xf)) {
      *(int *)(iVar9 + 0x178) = iVar6;
      iVar8 = iVar6;
    }
    if (iVar6 != 0xf && bVar10 == SBORROW4(iVar6,0xf)) {
      *(int *)(iVar9 + 0x178) = iVar4;
    }
    uVar7 = 0x2151;
  }
  _cg_memcpy(local_82c,iVar3 + iVar8 * 0xa0,0xa0,"cgminer.c",DAT_00023cfc,uVar7);
LAB_00023be4:
  *(undefined *)(param_1 + 0x3d) = 0;
  cgtime(param_1 + 0x2c);
  iVar8 = *(int *)(param_1 + 0x24);
  *(undefined4 *)(iVar8 + 0x60) = 0;
  tVar1 = time((time_t *)0x0);
  iVar9 = *(int *)(iVar9 + 4);
  *(time_t *)(iVar8 + 0xf0) = tVar1;
  dVar13 = *(double *)(iVar9 + 0x68);
  dVar11 = *(double *)(local_82c + 0x178);
  dVar12 = *(double *)(iVar9 + 0x70);
  *(undefined *)(local_82c + 0x110) = 1;
  if (dVar13 != dVar11 && dVar13 < dVar11 == (NAN(dVar13) || NAN(dVar11))) {
    dVar13 = dVar11;
  }
  if ((int)((uint)(dVar13 < dVar12) << 0x1f) < 0) {
    dVar13 = dVar12;
  }
  *(double *)(local_82c + 0xe0) = dVar13;
  return local_82c;
}


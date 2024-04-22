
/* WARNING: Unknown calling convention */

void __kill_work(void)

{
  char *pcVar1;
  int *piVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  thr_info *ptVar6;
  int iVar7;
  cgpu_info *cgpu;
  int thr_id;
  int iVar8;
  char tmp42 [2048];
  
  pcVar3 = DAT_00022964;
  if (((*DAT_00022964 != '\0') || (*DAT_00022938 != '\0')) || (5 < *DAT_00022960)) {
    tmp42._0_4_ = *DAT_0002293c;
    tmp42._4_4_ = DAT_0002293c[1];
    tmp42._8_4_ = DAT_0002293c[2];
    tmp42._12_4_ = DAT_0002293c[3];
    tmp42._16_4_ = DAT_0002293c[4];
    tmp42[20] = (char)(short)DAT_0002293c[5];
    tmp42[21] = (char)((ushort)(short)DAT_0002293c[5] >> 8);
    _applog(6,tmp42,true);
  }
  pcVar1 = DAT_00022940;
  if ((*DAT_00022940 != '\0') &&
     (((*pcVar3 != '\0' || (*DAT_00022938 != '\0')) || (6 < *DAT_00022960)))) {
    tmp42._0_4_ = *DAT_00022944;
    tmp42._4_4_ = DAT_00022944[1];
    tmp42._8_4_ = DAT_00022944[2];
    tmp42._12_4_ = DAT_00022944[3];
    tmp42._16_4_ = DAT_00022944[4];
    tmp42._20_4_ = DAT_00022944[5];
    tmp42._24_4_ = DAT_00022944[6];
    tmp42[28] = (char)DAT_00022944[7];
    _applog(7,tmp42,true);
  }
  iVar5 = DAT_0002296c;
  piVar4 = DAT_00022968;
  cg_completion_timeout
            (DAT_00022948,(void *)(*DAT_00022968 + *(int *)(DAT_0002296c + 0x4f8) * 0x40),1000);
  if ((*pcVar1 != '\0') && (((*pcVar3 != '\0' || (*DAT_00022938 != '\0')) || (6 < *DAT_00022960))))
  {
    tmp42._0_4_ = *DAT_0002294c;
    tmp42._4_4_ = DAT_0002294c[1];
    tmp42._8_4_ = DAT_0002294c[2];
    tmp42._12_4_ = DAT_0002294c[3];
    tmp42._16_4_ = DAT_0002294c[4];
    tmp42._20_4_ = DAT_0002294c[5];
    tmp42._24_4_ = DAT_0002294c[6];
    _applog(7,tmp42,true);
  }
  cg_completion_timeout(DAT_00022948,(void *)(*piVar4 + *(int *)(iVar5 + 0x4fc) * 0x40),1000);
  if ((*pcVar1 != '\0') && (((*pcVar3 != '\0' || (*DAT_00022938 != '\0')) || (6 < *DAT_00022960))))
  {
    tmp42._0_4_ = *DAT_00022950;
    tmp42._4_4_ = DAT_00022950[1];
    tmp42._8_4_ = DAT_00022950[2];
    tmp42._12_4_ = DAT_00022950[3];
    tmp42._16_4_ = DAT_00022950[4];
    tmp42._20_4_ = DAT_00022950[5];
    tmp42._24_4_ = DAT_00022950[6];
    tmp42[28] = (char)DAT_00022950[7];
    _applog(7,tmp42,true);
  }
  piVar2 = DAT_00022954;
  if (0 < *DAT_00022954) {
    thr_id = 0;
    do {
      iVar8 = thr_id + 1;
      ptVar6 = get_thread(thr_id);
      iVar7 = *piVar2;
      if ((ptVar6 != (thr_info *)0x0) && (ptVar6->cgpu != (cgpu_info *)0x0)) {
        ptVar6->cgpu->shutdown = true;
      }
      thr_id = iVar8;
    } while (iVar8 < iVar7);
  }
  sleep(1);
  cg_completion_timeout(DAT_00022958,(void *)0x0,3000);
  if ((*pcVar1 != '\0') && (((*pcVar3 != '\0' || (*DAT_00022938 != '\0')) || (6 < *DAT_00022960))))
  {
    tmp42._0_4_ = *DAT_0002295c;
    tmp42._4_4_ = DAT_0002295c[1];
    tmp42._8_4_ = DAT_0002295c[2];
    tmp42._12_4_ = DAT_0002295c[3];
    tmp42._16_4_ = DAT_0002295c[4];
    tmp42._20_3_ = (undefined3)DAT_0002295c[5];
    _applog(7,tmp42,true);
  }
  cg_completion_timeout(DAT_00022948,(void *)(*piVar4 + *(int *)(iVar5 + 0x418) * 0x40),1000);
  return;
}


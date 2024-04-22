
/* WARNING: Unknown calling convention */

void mt_disable(thr_info *mythr,int thr_id,device_drv *drv)

{
  char cVar1;
  char *pcVar2;
  char tmp42 [2048];
  
  pcVar2 = DAT_0001e2dc;
  if (((*DAT_0001e2dc != '\0') || (*DAT_0001e2e0 != '\0')) || (3 < *DAT_0001e2fc)) {
    snprintf(tmp42,0x800,DAT_0001e2e4,thr_id);
    _applog(4,tmp42,false);
  }
  cVar1 = *DAT_0001e2e8;
  mythr->cgpu->rolling = 0.0;
  if ((cVar1 != '\0') && (((*pcVar2 != '\0' || (*DAT_0001e2e0 != '\0')) || (6 < *DAT_0001e2fc)))) {
    tmp42._0_4_ = *DAT_0001e2ec;
    tmp42._4_4_ = DAT_0001e2ec[1];
    tmp42._8_4_ = DAT_0001e2ec[2];
    tmp42._12_4_ = DAT_0001e2ec[3];
    tmp42._16_4_ = DAT_0001e2ec[4];
    tmp42._20_4_ = DAT_0001e2ec[5];
    tmp42._24_4_ = DAT_0001e2ec[6];
    tmp42._28_2_ = (undefined2)DAT_0001e2ec[7];
    tmp42[30] = (char)((uint)DAT_0001e2ec[7] >> 0x10);
    _applog(7,tmp42,false);
  }
  _cgsem_wait(&mythr->sem,DAT_0001e2f0,DAT_0001e2f4,0x2338);
  if (((*pcVar2 != '\0') || (*DAT_0001e2e0 != '\0')) || (3 < *DAT_0001e2fc)) {
    snprintf(tmp42,0x800,DAT_0001e2f8,thr_id);
    _applog(4,tmp42,false);
  }
  (*drv->thread_enable)(mythr);
  return;
}


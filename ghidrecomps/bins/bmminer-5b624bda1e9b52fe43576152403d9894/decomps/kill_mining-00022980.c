
/* WARNING: Unknown calling convention */

void kill_mining(void)

{
  int *piVar1;
  thr_info *thr;
  thr_info *thr_00;
  int thr_id;
  char tmp42 [2048];
  
  if ((*DAT_00022a0c != '\0') &&
     (((*DAT_00022a10 != '\0' || (*DAT_00022a14 != '\0')) || (6 < *DAT_00022a20)))) {
    tmp42._0_4_ = *DAT_00022a18;
    tmp42._4_4_ = DAT_00022a18[1];
    tmp42._8_4_ = DAT_00022a18[2];
    tmp42._12_4_ = DAT_00022a18[3];
    tmp42._16_4_ = DAT_00022a18[4];
    tmp42._20_4_ = DAT_00022a18[5];
    tmp42._24_2_ = (undefined2)DAT_00022a18[6];
    tmp42[26] = (char)((uint)DAT_00022a18[6] >> 0x10);
    _applog(7,tmp42,true);
  }
  piVar1 = DAT_00022a1c;
  if (0 < *DAT_00022a1c) {
    thr_id = 0;
    do {
      while ((thr_00 = get_thread(thr_id), thr_00 != (thr_info *)0x0 && (thr_00->pth != 0))) {
        thr_info_cancel(thr_00);
        if (thr_00->pth != 0) {
          pthread_join(thr_00->pth,(void **)0x0);
        }
        thr_id = thr_id + 1;
        if (*piVar1 <= thr_id) {
          return;
        }
      }
      thr_id = thr_id + 1;
      thr_info_cancel(thr_00);
    } while (thr_id < *piVar1);
  }
  return;
}



/* WARNING: Unknown calling convention */

void sharelog(char *disposition,work *work)

{
  thr_info *ptVar1;
  thr_info *thr;
  char *__ptr;
  char *target;
  char *__ptr_00;
  char *hash;
  char *__ptr_01;
  char *data;
  size_t sVar2;
  int rv;
  size_t ret;
  int iVar3;
  pool *ppVar4;
  pool *pool;
  char *pcVar5;
  __time_t line;
  ulong t;
  FILE *__s;
  undefined4 *puVar6;
  int iVar7;
  int thr_id;
  cgpu_info *cgpu;
  cgpu_info *pcVar8;
  char s [1024];
  char tmp42 [2048];
  
  iVar3 = DAT_00022b84;
  if (*(int *)(DAT_00022b84 + 0x11c) == 0) {
    return;
  }
  iVar7 = work->thr_id;
  ptVar1 = get_thread(iVar7);
  ppVar4 = work->pool;
  line = (work->tv_work_found).tv_sec;
  pcVar8 = ptVar1->cgpu;
  __ptr = bin2hex(work->target,0x20);
  target = (char *)work->hash;
  __ptr_00 = bin2hex((uchar *)target,0x20);
  __ptr_01 = bin2hex(work->data,0x80);
  pcVar5 = DAT_00022b88;
  sVar2 = snprintf(s,0x400,DAT_00022b88,line,disposition,__ptr,ppVar4->rpc_url,pcVar8->drv->name,
                   pcVar8->device_id,iVar7,__ptr_00,__ptr_01);
  free(__ptr);
  free(__ptr_00);
  free(__ptr_01);
  if ((int)sVar2 < 0x400) {
    if (-1 < (int)sVar2) goto LAB_00022ad8;
    puVar6 = DAT_00022ba0;
    if ((*DAT_00022b94 != '\0') || (*DAT_00022b98 != '\0')) goto LAB_00022b1c;
    iVar3 = *DAT_00022ba4;
  }
  else {
    line = 0;
    s[1023] = '\0';
LAB_00022ad8:
    iVar7 = pthread_mutex_lock(DAT_00022b8c);
    if (iVar7 != 0) {
      _mutex_lock(DAT_00022ba8,(char *)0x282,pcVar5,line);
    }
    pcVar5 = (char *)0x1;
    __s = *(FILE **)(iVar3 + 0x11c);
    sVar2 = fwrite(s,sVar2,1,__s);
    ret = *(size_t *)(iVar3 + 0x11c);
    fflush((FILE *)ret);
    iVar3 = pthread_mutex_unlock(DAT_00022b8c);
    if (iVar3 != 0) {
      _mutex_unlock_noyield(DAT_00022ba8,(char *)0x285,pcVar5,(int)__s);
    }
    (**DAT_00022b90)();
    if (sVar2 == 1) {
      return;
    }
    puVar6 = DAT_00022b9c;
    if ((*DAT_00022b94 != '\0') || (*DAT_00022b98 != '\0')) goto LAB_00022b1c;
    iVar3 = *DAT_00022ba4;
  }
  if (iVar3 < 3) {
    return;
  }
LAB_00022b1c:
  tmp42._0_4_ = *puVar6;
  tmp42._4_4_ = puVar6[1];
  tmp42._8_4_ = puVar6[2];
  tmp42._12_4_ = puVar6[3];
  tmp42._16_4_ = puVar6[4];
  tmp42._20_2_ = (undefined2)puVar6[5];
  _applog(3,tmp42,false);
  return;
}


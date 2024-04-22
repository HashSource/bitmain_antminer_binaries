
void set_target(uchar *dest_target,double diff)

{
  char *pcVar1;
  char *__ptr;
  char *htarget;
  double in_d0;
  double dVar2;
  double dVar3;
  uchar target [32];
  char tmp42 [2048];
  
  if (in_d0 == 0.0) {
    if (((*DAT_0001f74c == '\0') && (*DAT_0001f750 == '\0')) && (*DAT_0001f754 < 3)) {
      in_d0 = 1.0;
    }
    else {
      tmp42._0_4_ = *DAT_0001f75c;
      tmp42._4_4_ = DAT_0001f75c[1];
      tmp42._8_4_ = DAT_0001f75c[2];
      tmp42._12_4_ = DAT_0001f75c[3];
      tmp42._16_4_ = DAT_0001f75c[4];
      tmp42._20_4_ = DAT_0001f75c[5];
      tmp42._24_4_ = DAT_0001f75c[6];
      tmp42._28_2_ = (undefined2)DAT_0001f75c[7];
      tmp42[30] = (char)((uint)DAT_0001f75c[7] >> 0x10);
      _applog(3,tmp42,false);
      in_d0 = 1.0;
    }
  }
  pcVar1 = DAT_0001f740;
  dVar3 = DAT_0001f708 / in_d0;
  dVar2 = dVar3 * DAT_0001f710;
  target._24_8_ = __fixunsdfdi(SUB84(dVar2,0),(int)((ulonglong)dVar2 >> 0x20));
  dVar2 = (double)__aeabi_ul2d();
  dVar3 = dVar3 - dVar2 * DAT_0001f718;
  dVar2 = dVar3 * DAT_0001f720;
  target._16_8_ = __fixunsdfdi(SUB84(dVar2,0),(int)((ulonglong)dVar2 >> 0x20));
  dVar2 = (double)__aeabi_ul2d();
  dVar3 = dVar3 - dVar2 * DAT_0001f728;
  dVar2 = dVar3 * DAT_0001f730;
  target._8_8_ = __fixunsdfdi(SUB84(dVar2,0),(int)((ulonglong)dVar2 >> 0x20));
  dVar2 = (double)__aeabi_ul2d();
  dVar3 = dVar3 - dVar2 * DAT_0001f738;
  target._0_8_ = __fixunsdfdi(SUB84(dVar3,0),(int)((ulonglong)dVar3 >> 0x20));
  if (*pcVar1 != '\0') {
    __ptr = bin2hex(target,0x20);
    if ((*pcVar1 != '\0') &&
       (((*DAT_0001f74c != '\0' || (*DAT_0001f750 != '\0')) || (6 < *DAT_0001f754)))) {
      snprintf(tmp42,0x800,DAT_0001f758,__ptr);
      _applog(7,tmp42,false);
    }
    free(__ptr);
  }
  _cg_memcpy(dest_target,target,0x20,DAT_0001f748,DAT_0001f744,0x1ffe);
  return;
}


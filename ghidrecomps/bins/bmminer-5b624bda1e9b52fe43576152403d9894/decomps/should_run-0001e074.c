
/* WARNING: Unknown calling convention */

_Bool should_run(void)

{
  char *pcVar1;
  char *pcVar2;
  _Bool _Var3;
  tm *ptVar4;
  tm *tm;
  int iVar5;
  int iVar6;
  int iVar7;
  __time_t local_24;
  timeval tv;
  
  pcVar2 = DAT_0001e138;
  pcVar1 = DAT_0001e134;
  if ((*DAT_0001e134 == '\0') && (*DAT_0001e138 == '\0')) {
LAB_0001e0c8:
    _Var3 = true;
  }
  else {
    cgtime(&tv);
    local_24 = tv.tv_sec;
    ptVar4 = localtime(&local_24);
    if (*pcVar1 == '\0') {
      if ((ptVar4->tm_hour < *(int *)(pcVar2 + 0xc)) ||
         ((ptVar4->tm_hour == *(int *)(pcVar2 + 0xc) &&
          (ptVar4->tm_min < *(int *)(DAT_0001e138 + 8))))) goto LAB_0001e0c8;
    }
    else if (*pcVar2 == '\0') {
      if ((*(int *)(DAT_0001e134 + 0xc) <= ptVar4->tm_hour) &&
         ((ptVar4->tm_hour != *(int *)(DAT_0001e134 + 0xc) ||
          (*(int *)(DAT_0001e134 + 8) <= ptVar4->tm_min)))) {
        *pcVar1 = '\0';
        return true;
      }
    }
    else {
      iVar7 = *(int *)(DAT_0001e134 + 0xc);
      iVar6 = *(int *)(DAT_0001e138 + 0xc);
      if ((iVar6 <= iVar7) &&
         ((iVar7 != iVar6 || (*(int *)(DAT_0001e138 + 8) <= *(int *)(DAT_0001e134 + 8))))) {
        iVar5 = ptVar4->tm_hour;
        if (iVar5 < iVar7) {
          if (iVar6 <= iVar5) {
LAB_0001e11a:
            if ((iVar6 != iVar5) || (*(int *)(pcVar2 + 8) <= ptVar4->tm_min)) goto LAB_0001e0da;
          }
        }
        else if ((iVar7 == iVar5) && (ptVar4->tm_min < *(int *)(pcVar1 + 8))) goto LAB_0001e11a;
        goto LAB_0001e0c8;
      }
      iVar5 = ptVar4->tm_hour;
      if ((((iVar5 < iVar6) || ((iVar6 == iVar5 && (ptVar4->tm_min < *(int *)(pcVar2 + 8))))) &&
          (iVar7 <= iVar5)) && ((iVar7 != iVar5 || (*(int *)(pcVar1 + 8) <= ptVar4->tm_min))))
      goto LAB_0001e0c8;
    }
LAB_0001e0da:
    _Var3 = false;
  }
  return _Var3;
}


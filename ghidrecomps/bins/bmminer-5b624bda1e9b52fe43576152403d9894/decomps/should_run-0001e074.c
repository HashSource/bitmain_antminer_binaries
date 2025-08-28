
/* WARNING: Unknown calling convention */

_Bool should_run(void)

{
  _Bool _Var1;
  tm *ptVar2;
  int iVar3;
  __time_t local_24;
  timeval tv;
  
  if ((schedstart.enable) || (schedstop.enable)) {
    cgtime(&tv);
    local_24 = tv.tv_sec;
    ptVar2 = localtime(&local_24);
    if (schedstart.enable == false) {
      if ((ptVar2->tm_hour < schedstop.tm.tm_hour) ||
         ((ptVar2->tm_hour == schedstop.tm.tm_hour && (ptVar2->tm_min < schedstop.tm.tm_min))))
      goto LAB_0001e0c8;
    }
    else if (schedstop.enable == false) {
      if ((schedstart.tm.tm_hour <= ptVar2->tm_hour) &&
         ((ptVar2->tm_hour != schedstart.tm.tm_hour || (schedstart.tm.tm_min <= ptVar2->tm_min)))) {
        schedstart.enable = false;
        return true;
      }
    }
    else {
      if ((schedstop.tm.tm_hour <= schedstart.tm.tm_hour) &&
         ((schedstart.tm.tm_hour != schedstop.tm.tm_hour ||
          (schedstop.tm.tm_min <= schedstart.tm.tm_min)))) {
        iVar3 = ptVar2->tm_hour;
        if (iVar3 < schedstart.tm.tm_hour) {
          if (schedstop.tm.tm_hour <= iVar3) {
LAB_0001e11a:
            if ((schedstop.tm.tm_hour != iVar3) || (schedstop.tm.tm_min <= ptVar2->tm_min))
            goto LAB_0001e0da;
          }
        }
        else if ((schedstart.tm.tm_hour == iVar3) && (ptVar2->tm_min < schedstart.tm.tm_min))
        goto LAB_0001e11a;
        goto LAB_0001e0c8;
      }
      iVar3 = ptVar2->tm_hour;
      if ((((iVar3 < schedstop.tm.tm_hour) ||
           ((schedstop.tm.tm_hour == iVar3 && (ptVar2->tm_min < schedstop.tm.tm_min)))) &&
          (schedstart.tm.tm_hour <= iVar3)) &&
         ((schedstart.tm.tm_hour != iVar3 || (schedstart.tm.tm_min <= ptVar2->tm_min))))
      goto LAB_0001e0c8;
    }
LAB_0001e0da:
    _Var1 = false;
  }
  else {
LAB_0001e0c8:
    _Var1 = true;
  }
  return _Var1;
}


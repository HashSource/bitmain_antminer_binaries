
bool should_run(void)

{
  char cVar1;
  tm *ptVar2;
  int iVar3;
  int iVar4;
  time_t local_1c;
  time_t local_18 [2];
  
  if ((schedstart[0] != '\0') || (schedstop[0] != '\0')) {
    cgtime(local_18);
    local_1c = local_18[0];
    ptVar2 = localtime(&local_1c);
    if (schedstart[0] == '\0') {
      if ((int)schedstop._12_4_ <= ptVar2->tm_hour) {
        return ptVar2->tm_hour == schedstop._12_4_ && ptVar2->tm_min < (int)schedstop._8_4_;
      }
    }
    else {
      if (schedstop[0] == '\0') {
        if (ptVar2->tm_hour < (int)schedstart._12_4_) {
          return false;
        }
        if (ptVar2->tm_hour == schedstart._12_4_ && ptVar2->tm_min < (int)schedstart._8_4_) {
          return false;
        }
        cVar1 = schedstart[0];
        schedstart[0] = schedstop[0];
        return (bool)cVar1;
      }
      if (((int)schedstart._12_4_ < (int)schedstop._12_4_) ||
         (schedstart._12_4_ == schedstop._12_4_ && (int)schedstart._8_4_ < (int)schedstop._8_4_)) {
        iVar4 = ptVar2->tm_hour;
        iVar3 = ptVar2->tm_min;
        if (((int)schedstop._12_4_ <= iVar4) &&
           (iVar3 >= (int)schedstop._8_4_ || schedstop._12_4_ != iVar4)) {
          return iVar3 < (int)schedstop._8_4_ && schedstop._12_4_ == iVar4;
        }
        if ((int)schedstart._12_4_ <= iVar4) {
          return schedstart._12_4_ != iVar4 || (int)schedstart._8_4_ <= iVar3;
        }
        return false;
      }
      iVar3 = ptVar2->tm_hour;
      if (((iVar3 < (int)schedstart._12_4_) ||
          (schedstart._12_4_ == iVar3 && ptVar2->tm_min < (int)schedstart._8_4_)) &&
         ((int)schedstop._12_4_ <= iVar3)) {
        return ptVar2->tm_min < (int)schedstop._8_4_ && schedstop._12_4_ == iVar3;
      }
    }
  }
  return true;
}


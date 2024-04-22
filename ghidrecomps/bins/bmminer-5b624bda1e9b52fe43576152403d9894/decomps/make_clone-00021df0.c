
/* WARNING: Unknown calling convention */

work * make_clone(work *work)

{
  work *pwVar1;
  work *work_clone;
  int iVar2;
  
  pwVar1 = copy_work_noffset(work,0);
  pwVar1->clone = true;
  cgtime(&pwVar1->tv_cloned);
  iVar2 = (pwVar1->tv_staged).tv_sec;
  pwVar1->longpoll = false;
  pwVar1->mandatory = false;
  (pwVar1->tv_staged).tv_sec = iVar2 + -1;
  return pwVar1;
}


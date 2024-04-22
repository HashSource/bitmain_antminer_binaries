
_Bool work_rollable(work *work)

{
  _Bool _Var1;
  work *work_local;
  
  if ((work->clone == true) || (work->rolltime == 0)) {
    _Var1 = false;
  }
  else {
    _Var1 = true;
  }
  return _Var1;
}


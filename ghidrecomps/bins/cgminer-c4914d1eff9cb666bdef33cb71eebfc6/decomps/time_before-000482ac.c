
_Bool time_before(tm *tm1,tm *tm2)

{
  _Bool _Var1;
  tm *tm2_local;
  tm *tm1_local;
  
  if (tm1->tm_hour < tm2->tm_hour) {
    _Var1 = true;
  }
  else if ((tm1->tm_hour == tm2->tm_hour) && (tm1->tm_min < tm2->tm_min)) {
    _Var1 = true;
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}


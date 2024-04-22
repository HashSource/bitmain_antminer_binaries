
/* WARNING: Unknown calling convention */

_Bool should_run(void)

{
  _Bool _Var1;
  tm *tm1;
  time_t tmp_time;
  timeval tv;
  tm *tm;
  
  if ((schedstart.enable) || (schedstop.enable)) {
    cgtime(&tv);
    tmp_time = tv.tv_sec;
    tm1 = localtime(&tmp_time);
    if (schedstart.enable == false) {
      _Var1 = time_before((tm *)tm1,DAT_000479d8);
      if (_Var1) {
        _Var1 = true;
      }
      else {
        _Var1 = false;
      }
    }
    else if (schedstop.enable == true) {
      _Var1 = time_before(DAT_000479d4,DAT_000479d8);
      if (_Var1) {
        _Var1 = time_before((tm *)tm1,DAT_000479d8);
        if ((!_Var1) || (_Var1 = time_before((tm *)tm1,DAT_000479d4), _Var1)) {
          _Var1 = false;
        }
        else {
          _Var1 = true;
        }
      }
      else {
        _Var1 = time_before((tm *)tm1,DAT_000479d4);
        if (_Var1) {
          _Var1 = time_before((tm *)tm1,DAT_000479d8);
          if (_Var1) {
            _Var1 = true;
          }
          else {
            _Var1 = false;
          }
        }
        else {
          _Var1 = true;
        }
      }
    }
    else {
      _Var1 = time_before((tm *)tm1,DAT_000479d4);
      if (_Var1) {
        _Var1 = false;
      }
      else {
        schedstart.enable = false;
        _Var1 = true;
      }
    }
  }
  else {
    _Var1 = true;
  }
  return _Var1;
}


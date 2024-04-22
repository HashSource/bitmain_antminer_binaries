
int get_target_airout_pcb_temp(int airin_pcb_temp)

{
  _Bool _Var1;
  int airin_pcb_temp_local;
  float rate;
  int target_airout_pcb_temp;
  int i;
  target_temp_args_t *ptarget_temp_arg;
  
  _Var1 = is_T15();
  if (_Var1) {
    if (opt_bitmain_economic_mode == false) {
      ptarget_temp_arg = DAT_0001e2e4;
    }
    else {
      ptarget_temp_arg = target_temp_arg[0];
    }
    if (ptarget_temp_arg->target_airin_pcb_temp < airin_pcb_temp) {
      target_airout_pcb_temp = 0x44;
      for (i = 0; i < 3; i = i + 1) {
        if ((ptarget_temp_arg[i].target_airin_pcb_temp < airin_pcb_temp) &&
           (airin_pcb_temp <= ptarget_temp_arg[i + 1].target_airin_pcb_temp)) {
          return (int)((float)(longlong)(airin_pcb_temp - ptarget_temp_arg[i].target_airin_pcb_temp)
                       * ((float)(longlong)
                                 (ptarget_temp_arg[i + 1].target_airout_pcb_temp -
                                 ptarget_temp_arg[i].target_airout_pcb_temp) /
                         (float)(longlong)
                                (ptarget_temp_arg[i + 1].target_airin_pcb_temp -
                                ptarget_temp_arg[i].target_airin_pcb_temp)) +
                      (float)(longlong)ptarget_temp_arg[i].target_airout_pcb_temp);
        }
      }
    }
    else {
      target_airout_pcb_temp = ptarget_temp_arg->target_airout_pcb_temp;
    }
  }
  else {
    target_airout_pcb_temp = 0x44;
  }
  return target_airout_pcb_temp;
}


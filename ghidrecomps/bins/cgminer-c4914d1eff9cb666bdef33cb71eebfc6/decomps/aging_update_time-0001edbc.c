
void aging_update_time(int aging_time_increase)

{
  double dVar1;
  uint32_t uVar2;
  int aging_time_increase_local;
  uint32_t total_seconds;
  
  dVar1 = get_total_secs();
  uVar2 = (uint)(0.0 < dVar1) * (int)(longlong)dVar1;
  aging_info.aging_seconds =
       aging_info.aging_seconds + (uVar2 - aging_update_time::last_total_seconds);
  aging_update_time::last_total_seconds = uVar2;
  aging_save_info();
  return;
}


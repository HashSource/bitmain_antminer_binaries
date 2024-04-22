
/* WARNING: Unknown calling convention */

void shutdown_read_temp_thread_in_force(void)

{
  if (read_temp_id_in_force != (thr_info *)0x0) {
    thr_info_cancel(read_temp_id_in_force);
    read_temp_id_in_force = (thr_info *)0x0;
  }
  return;
}


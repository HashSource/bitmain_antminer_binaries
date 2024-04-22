
void re_send_last_job(void)

{
  if (last_job_buffer[0] != '\x17') {
    re_send_last_job_part_15();
    return;
  }
  return;
}


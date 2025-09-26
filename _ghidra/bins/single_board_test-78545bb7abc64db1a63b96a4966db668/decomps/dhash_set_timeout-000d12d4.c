
void dhash_set_timeout(uint32_t timeout)

{
  if (0x1fffe < timeout) {
    timeout = 0x1ffff;
  }
  _set_time_out_control(timeout | 0x80000000);
  return;
}


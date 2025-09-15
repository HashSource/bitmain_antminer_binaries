
void bm1744_hashboard_init(void)

{
  set_baud(0);
  usleep(50000);
  set_core_timeout(app_conf._364_4_);
  usleep(10000);
  set_ticket_mask(app_conf._360_4_);
  usleep(10000);
  set_frequency(app_conf._412_4_);
  usleep(10000);
  set_nonce_shift(0);
  usleep(10000);
  return;
}


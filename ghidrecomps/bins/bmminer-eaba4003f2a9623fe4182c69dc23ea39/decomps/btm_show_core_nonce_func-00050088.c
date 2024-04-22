
/* WARNING: Unknown calling convention */

void * btm_show_core_nonce_func(void)

{
  time_num = 0;
  do {
    btm_show_core_nonce();
    sleep(10);
  } while( true );
}


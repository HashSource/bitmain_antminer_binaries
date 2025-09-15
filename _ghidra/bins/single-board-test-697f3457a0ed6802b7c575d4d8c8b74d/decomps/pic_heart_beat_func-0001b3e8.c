
void * pic_heart_beat_func(void *arg)

{
  byte bVar1;
  uchar which_i2c_00;
  void *arg_local;
  uchar which_i2c;
  uchar which_chain;
  chain_info *chain_i;
  
                    /* WARNING: Load size is inaccurate */
  bVar1 = *arg;
  which_i2c_00 = *(uchar *)((int)arg + 1);
  do {
    heart_beat_PIC16F1704((uint)bVar1,which_i2c_00);
    sleep(10);
  } while( true );
}


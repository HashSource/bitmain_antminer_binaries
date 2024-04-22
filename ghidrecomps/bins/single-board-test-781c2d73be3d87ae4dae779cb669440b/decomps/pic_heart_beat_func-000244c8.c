
/* WARNING: Unknown calling convention */
/* Local variable chain_info:chain_info *[r0:4] conflicts with parameter, skipped. */

void * pic_heart_beat_func(void *arg)

{
  byte bVar1;
  uchar which_i2c_00;
  undefined4 uVar2;
  uchar which_i2c;
  uchar which_chain;
  
  uVar2 = DAT_00024534;
                    /* WARNING: Load size is inaccurate */
  bVar1 = *arg;
  which_i2c_00 = *(uchar *)((int)arg + 1);
  do {
    if (gHashBoard_V9 == false) {
      if (((gHashBoard_BHB91601P == false) && (gHashBoard_BHB91601S == false)) &&
         (gHashBoard_BHB07601 == false)) {
        printf("\n!!! %s Please check Hashboard type!\n\n",uVar2);
      }
      else {
        heart_beat_dsPIC33EP16GS202((uint)bVar1,which_i2c_00);
      }
    }
    else {
      heart_beat_PIC16F1704((uint)bVar1,which_i2c_00);
    }
    sleep(10);
  } while( true );
}


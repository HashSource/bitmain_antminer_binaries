
void bm1740_get_reg(void)

{
  undefined4 uVar1;
  int *piVar2;
  char *pcVar3;
  pthread_t __th;
  char acStack_130 [259];
  undefined local_2d;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_24;
  undefined auStack_20 [2];
  byte local_1e;
  byte local_1d;
  byte local_1c;
  byte local_1b;
  byte local_1a;
  byte local_19;
  FILE *local_14;
  
  local_14 = fopen("freg.txt","a+");
  if (local_14 == (FILE *)0x0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(acStack_130,0x100,"open freg failed %s\n",pcVar3);
      _applog(0,acStack_130,0);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  __th = pthread_self();
  pthread_detach(__th);
  do {
    midd_recv_regdata(auStack_20,9);
    midd_recv_regdata(&local_2d,1);
    uVar1 = local_2c;
    local_24 = 3;
    local_28 = (uint)local_1a |
               (uint)local_1d << 0x18 | (uint)local_1c << 0x10 | (uint)local_1b << 8;
    add_reg_item(local_2c,local_28,3);
    fprintf(local_14,"addr:%02x data=%02x%02x%02x%02x chip=%02x\n",(uint)local_1e,(uint)local_1d,
            (uint)local_1c,(uint)local_1b,(uint)local_1a,(uint)local_19);
    fflush(local_14);
  } while( true );
}


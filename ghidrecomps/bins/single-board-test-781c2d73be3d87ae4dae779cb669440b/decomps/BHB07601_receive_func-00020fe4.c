
/* WARNING: Unknown calling convention */

void * BHB07601_receive_func(void *arg)

{
  byte bVar1;
  byte which_chain_00;
  chain_info *chain_info;
  int iVar2;
  int priority;
  pthread_t __target_thread;
  int iVar3;
  uint uVar4;
  uchar which_i2c;
  uint uVar5;
  uchar which_chain;
  sched_param sp;
  uint buf [2];
  
                    /* WARNING: Load size is inaccurate */
  which_chain_00 = *arg;
  bVar1 = *(byte *)((int)arg + 1);
  buf[0] = 0;
  buf[1] = 0;
  sp.__sched_priority = 0;
  iVar2 = sched_get_priority_max(1);
  sp.__sched_priority = iVar2;
  __target_thread = pthread_self();
  iVar3 = pthread_setschedparam(__target_thread,1,(sched_param *)&sp);
  if (iVar3 == 0) {
    printf("\n--- %s: IO Thread #%lx using %d priority scheduler! ",DAT_000210ac,__target_thread,
           iVar2);
  }
  printf("\n--- %s: which_chain = %d, which_i2c = %d\n\n",DAT_000210ac,(uint)which_chain_00,
         (uint)bVar1);
  while (start_receive != false) {
    usleep(1000);
    uVar4 = read_axi_fpga(6);
    if ((uVar4 & 0x1ff) != 0) {
      uVar5 = 0;
      do {
        get_return_nonce(buf);
        iVar2 = BM1397_is_nonce_or_reg_value(buf[0]);
        if (iVar2 == 0) {
          BHB07601_check_register_value(which_chain_00,buf);
        }
        else if ((gBegin_Get_Nonce != false) &&
                (iVar2 = BM1397_check_nonce_flag(buf[0]), iVar2 != 0)) {
          BHB07601_check_nonce(which_chain_00,buf);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uVar4 & 0x1ff));
    }
  }
  return (void *)0x0;
}


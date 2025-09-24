
int32_t sw_pt_send_work(uint32_t chain,void *args)

{
  _Bool _Var1;
  uchar uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  void *args_local;
  uint32_t chain_local;
  char time_stamp [48];
  char tmp1 [256];
  work_cxt work_buf;
  pattern_work *works;
  uint32_t send_counter;
  uint32_t position;
  uint32_t count;
  uint32_t received_nonce_num;
  uint32_t *work_ptr;
  uint32_t pattern_num;
  uint32_t small_core_in_big_core;
  uint32_t core_num;
  uint32_t asic_num;
  pattern_runtime_ctx *runtime;
  uint32_t j;
  uint32_t i;
  pattern_work *work;
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t which_asic;
  
  uVar5 = *(uint *)(*(int *)((int)args + 0x23628) + 4);
  uVar6 = (g_rt.config)->big_core * (g_rt.config)->samll_core_num_in_big_core;
  uVar7 = *(uint *)(*(int *)((int)args + 0x23628) + 0x1c);
  uVar8 = *(uint *)(*(int *)((int)args + 0x23628) + 0x20);
  err_sweep_nonce_resp = 0;
  _Var1 = read_temp_from_asic_once(false);
  if (!_Var1) {
    err_exit("asic temp outof range");
  }
  _Var1 = read_chain_domain_voltage(false);
  if (!_Var1) {
    err_exit("asic vol outof range");
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : asic_num:%d,core_num:%d,small_core_in_big_core:%d,pattern:%d.\n","sw_pt_send_work",
         uVar5,uVar6,uVar7,uVar8);
  snprintf(tmp1,0x100,"asic_num:%d,core_num:%d,small_core_in_big_core:%d,pattern:%d.",uVar5,uVar6,
           uVar7,uVar8);
  log_to_file(tmp1,time_stamp);
  for (which_asic = 0; which_asic < uVar5; which_asic = which_asic + 1) {
    iVar9 = *(int *)((int)args + (which_asic + 0x8d1e) * 4);
    for (which_core = 0; which_core < uVar6; which_core = uVar7 + which_core) {
      for (which_pattern = 0; which_pattern < uVar8; which_pattern = which_pattern + 1) {
        while (uVar2 = is_work_fifo_ready(**(uint32_t **)((int)args + 0x23628)), uVar2 == '\0') {
          usleep(100);
        }
        memset(&work_buf,0,0x214);
        work_buf.work_type = '\x01';
        work_buf.chain_id = (byte)**(undefined4 **)((int)args + 0x23628) | 0x80;
        work_buf.reserved1[0] = '\0';
        work_buf.reserved1[1] = '\0';
        uVar4 = which_pattern << 7;
        work_buf.work_count =
             uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | which_pattern << 0x1f
        ;
        work = (pattern_work *)((which_pattern + uVar8 * which_core) * 0x10 + iVar9);
        for (i = 0; i < uVar7; i = i + 1) {
          uVar4 = *(int *)(*(int *)((int)args + 0x23628) + 0x1c) *
                  *(int *)(*(int *)((int)args + 0x23628) + 0x24);
          if ((uVar4 < which_core || uVar4 - which_core == 0) && (i < 4)) {
            for (j = 0; j < 0x20; j = j + 1) {
              if (j < 0x18) {
                work_buf.midstate[i][j] = '\0';
              }
              else {
                work_buf.midstate[i][j] = (char)i + *(char *)((int)(&work->pattern + -2) + j);
              }
            }
          }
          else {
            iVar3 = __aeabi_uidiv(which_core,*(undefined4 *)(*(int *)((int)args + 0x23628) + 0x1c));
            work = (pattern_work *)
                   ((which_pattern +
                    uVar8 * (i + *(int *)(*(int *)((int)args + 0x23628) + 0x1c) * iVar3)) * 0x10 +
                   iVar9);
            for (j = 0; j < 0x20; j = j + 1) {
              if (j < 0x18) {
                work_buf.midstate[i][j] = '\0';
              }
              else {
                work_buf.midstate[i][j] = *(uint8_t *)((int)(&work->pattern + -2) + j);
              }
            }
            *(int *)((int)args + 0x2365c) = *(int *)((int)args + 0x2365c) + 1;
          }
        }
        for (i = 0; i < 0x85; i = i + 1) {
          *(uint *)(work_buf.reserved1 + i * 4 + -2) =
               *(int *)(work_buf.reserved1 + i * 4 + -2) << 0x18 |
               *(uint *)(work_buf.reserved1 + i * 4 + -2) >> 0x18 |
               (*(uint *)(work_buf.reserved1 + i * 4 + -2) & 0xff0000) >> 8 |
               (*(uint *)(work_buf.reserved1 + i * 4 + -2) & 0xff00) << 8;
        }
        set_TW_write_command((uint32_t *)&work_buf,0x214);
      }
    }
  }
  if (*(uint *)((int)args + 0x2365c) < uVar5 * uVar8 * (g_rt.config)->asic_small_cores) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Send work num : %d, less than %d\n","sw_pt_send_work",
           *(undefined4 *)((int)args + 0x2365c),uVar5 * uVar6 * uVar8);
    snprintf(tmp1,0x100,"Send work num : %d, less than %d",*(undefined4 *)((int)args + 0x2365c),
             uVar5 * uVar6 * uVar8);
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Send test %d pattern done\n","sw_pt_send_work",*(undefined4 *)((int)args + 0x2365c)
          );
    snprintf(tmp1,0x100,"Send test %d pattern done",*(undefined4 *)((int)args + 0x2365c));
    log_to_file(tmp1,time_stamp);
  }
  uVar10 = *(undefined4 *)((int)args + 0x2334c);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : send work thread eixt,send:%d,recv:%d\n","sw_pt_send_work",
         *(undefined4 *)((int)args + 0x2365c),uVar10);
  snprintf(tmp1,0x100,"send work thread eixt,send:%d,recv:%d",*(undefined4 *)((int)args + 0x2365c),
           uVar10);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : err_sweep_nonce_resp:%d\n","sw_pt_send_work",err_sweep_nonce_resp);
  snprintf(tmp1,0x100,"err_sweep_nonce_resp:%d",err_sweep_nonce_resp);
  log_to_file(tmp1,time_stamp);
  _Var1 = read_temp_from_asic_once(false);
  if (!_Var1) {
    err_exit("asic temp outof range");
  }
  _Var1 = read_chain_domain_voltage(false);
  if (!_Var1) {
    err_exit("asic vol outof range");
  }
  return 0;
}


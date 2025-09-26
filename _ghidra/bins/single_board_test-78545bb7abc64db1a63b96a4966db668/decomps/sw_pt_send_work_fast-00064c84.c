
int32_t sw_pt_send_work_fast(uint32_t chain,void *args)

{
  uchar uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  void *args_local;
  uint32_t chain_local;
  char time_stamp [48];
  char tmp1 [256];
  work_cxt work_buf;
  pattern_work_new *works;
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
  pattern_work_new *work;
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t which_asic;
  
  uVar4 = *(uint *)(*(int *)((int)args + 0x84690) + 4);
  uVar5 = (g_rt.config)->big_core * (g_rt.config)->samll_core_num_in_big_core;
  uVar6 = *(uint *)(*(int *)((int)args + 0x84690) + 0x1c);
  uVar7 = *(uint *)(*(int *)((int)args + 0x84690) + 0x20);
  err_sweep_nonce_resp = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : asic_num:%d,core_num:%d,small_core_in_big_core:%d,pattern:%d.\n",
         "sw_pt_send_work_fast",uVar4,uVar5,uVar6,uVar7);
  snprintf(tmp1,0x100,"asic_num:%d,core_num:%d,small_core_in_big_core:%d,pattern:%d.",uVar4,uVar5,
           uVar6,uVar7);
  log_to_file(tmp1,time_stamp);
  for (which_asic = 0; which_asic < uVar4; which_asic = which_asic + 1) {
    iVar8 = *(int *)((int)args + (which_asic + 0x210a4) * 4);
    for (which_core = 0; which_core < uVar5; which_core = uVar6 + which_core) {
      for (which_pattern = 0; which_pattern < uVar7; which_pattern = which_pattern + 1) {
        while (uVar1 = is_work_fifo_ready(**(uint32_t **)((int)args + 0x84690)), uVar1 == '\0') {
          usleep(100);
        }
        memset(&work_buf,0,0x214);
        work_buf.work_type = '\x01';
        work_buf.chain_id = (byte)**(undefined4 **)((int)args + 0x84690) | 0x80;
        work_buf.reserved1[0] = '\0';
        work_buf.reserved1[1] = '\0';
        uVar3 = which_pattern << 7;
        work_buf.work_count =
             uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | which_pattern << 0x1f
        ;
        work = (pattern_work_new *)((which_pattern + uVar7 * which_core) * 0x10 + iVar8);
        for (i = 0; i < uVar6; i = i + 1) {
          if (((uVar6 * 0x4f == which_core) || (uVar6 * 0x7f == which_core)) && (uVar6 - 3 <= i)) {
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
            iVar2 = __aeabi_uidiv(which_core,*(undefined4 *)(*(int *)((int)args + 0x84690) + 0x1c));
            work = (pattern_work_new *)
                   ((which_pattern +
                    uVar7 * (i + *(int *)(*(int *)((int)args + 0x84690) + 0x1c) * iVar2)) * 0x10 +
                   iVar8);
            for (j = 0; j < 0x20; j = j + 1) {
              if (j < 0x18) {
                work_buf.midstate[i][j] = '\0';
              }
              else {
                work_buf.midstate[i][j] = *(uint8_t *)((int)(&work->pattern + -2) + j);
              }
            }
            *(int *)((int)args + 0x846c8) = *(int *)((int)args + 0x846c8) + 1;
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
  if (*(uint *)((int)args + 0x846c8) < uVar4 * uVar7 * (g_rt.config)->asic_small_cores) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Send work num : %d, less than %d\n","sw_pt_send_work_fast",
           *(undefined4 *)((int)args + 0x846c8),uVar4 * uVar5 * uVar7);
    snprintf(tmp1,0x100,"Send work num : %d, less than %d",*(undefined4 *)((int)args + 0x846c8),
             uVar4 * uVar5 * uVar7);
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Send test %d pattern done\n","sw_pt_send_work_fast",
           *(undefined4 *)((int)args + 0x846c8));
    snprintf(tmp1,0x100,"Send test %d pattern done",*(undefined4 *)((int)args + 0x846c8));
    log_to_file(tmp1,time_stamp);
  }
  uVar9 = *(undefined4 *)((int)args + 0x83c38);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : send work thread eixt,send:%d,recv:%d, repeat:%d\n","sw_pt_send_work_fast",
         *(undefined4 *)((int)args + 0x846c8),uVar9,*(undefined4 *)((int)args + 0x2a0c));
  snprintf(tmp1,0x100,"send work thread eixt,send:%d,recv:%d, repeat:%d",
           *(undefined4 *)((int)args + 0x846c8),uVar9,*(undefined4 *)((int)args + 0x2a0c));
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : err_sweep_nonce_resp:%d\n","sw_pt_send_work_fast",err_sweep_nonce_resp);
  snprintf(tmp1,0x100,"err_sweep_nonce_resp:%d",err_sweep_nonce_resp);
  log_to_file(tmp1,time_stamp);
  return 0;
}


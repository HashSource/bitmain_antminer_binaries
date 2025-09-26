
int32_t sw_pt_send_work_fast(uint32_t chain,void *args)

{
  uchar uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  void *args_local;
  uint32_t chain_local;
  char time_stamp [48];
  char tmp1 [2048];
  work_cxt work_buf;
  pattern_work_new *works;
  uint32_t send_counter;
  uint32_t position;
  uint32_t *work_ptr;
  uint32_t pattern_num;
  uint32_t small_core_in_big_core;
  uint32_t big_core_num;
  uint32_t core_num;
  uint32_t asic_num;
  pattern_runtime_ctx *runtime;
  uint32_t send_nonce;
  uint32_t count;
  uint32_t received_nonce_num;
  uint32_t j;
  uint32_t i;
  pattern_work_new *work;
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t which_asic;
  
  uVar3 = *(uint *)(*(int *)((int)args + 0x55708) + 4);
  uVar4 = *(uint *)(*(int *)((int)args + 0x55708) + 0x18);
  iVar5 = *(int *)(*(int *)((int)args + 0x55708) + 0x14);
  uVar6 = *(uint *)(*(int *)((int)args + 0x55708) + 0x1c);
  uVar7 = *(uint *)(*(int *)((int)args + 0x55708) + 0x20);
  count = 0;
  send_nonce = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: start to send work\n","sw_pt_send_work_fast");
  builtin_strncpy(tmp1,"start to send wo",0x10);
  tmp1[0x10] = 'r';
  tmp1[0x11] = 'k';
  tmp1[0x12] = '\0';
  log_to_file(tmp1,time_stamp);
  for (which_asic = 0; which_asic < uVar3; which_asic = which_asic + 1) {
    iVar8 = *(int *)((int)args + (which_asic + 0x154c2) * 4);
    for (which_core = 0; which_core < uVar4; which_core = uVar6 + which_core) {
      for (which_pattern = 0; which_pattern < uVar7; which_pattern = which_pattern + 1) {
        while (uVar1 = is_work_fifo_ready(**(uint32_t **)((int)args + 0x55708)), uVar1 == '\0') {
          usleep(100);
        }
        memset(&work_buf,0,0x214);
        work_buf.work_type = '\x01';
        work_buf.chain_id = (byte)**(undefined4 **)((int)args + 0x55708) | 0x80;
        work_buf.reserved1[0] = '\0';
        work_buf.reserved1[1] = '\0';
        uVar2 = which_pattern << 7;
        work_buf.work_count =
             uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | which_pattern << 0x1f
        ;
        work = (pattern_work_new *)((which_pattern + uVar7 * which_core) * 0x10 + iVar8);
        for (i = 0; i < 0xc; i = i + 1) {
          work_buf.data[i] = '\0';
        }
        for (i = 0; i < uVar6; i = i + 1) {
          uVar2 = *(int *)(*(int *)((int)args + 0x55708) + 0x1c) *
                  *(int *)(*(int *)((int)args + 0x55708) + 0x24);
          if ((uVar2 < which_core || uVar2 - which_core == 0) && (i < uVar6 * iVar5 - uVar4)) {
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
            work = (pattern_work_new *)((which_pattern + uVar7 * (i + which_core)) * 0x10 + iVar8);
            for (j = 0; j < 0x20; j = j + 1) {
              if (j < 0x18) {
                work_buf.midstate[i][j] = '\0';
              }
              else {
                work_buf.midstate[i][j] = *(uint8_t *)((int)(&work->pattern + -2) + j);
              }
            }
            send_nonce = send_nonce + 1;
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
  uVar6 = uVar3 * uVar4 * uVar7;
  if (uVar6 < send_nonce || uVar6 - send_nonce == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Send test %d pattern done\n\n","sw_pt_send_work_fast",send_nonce);
    snprintf(tmp1,0x800,"Send test %d pattern done\n",send_nonce);
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Send work num : %d, less than %d\n","sw_pt_send_work_fast",send_nonce,
           uVar3 * uVar4 * uVar7);
    snprintf(tmp1,0x800,"Send work num : %d, less than %d",send_nonce,uVar3 * uVar4 * uVar7);
    log_to_file(tmp1,time_stamp);
  }
  received_nonce_num = *(uint32_t *)((int)args + 0x54c34);
  while( true ) {
    while (*(uint32_t *)((int)args + 0x54c34) != received_nonce_num) {
      count = 0;
      received_nonce_num = *(uint32_t *)((int)args + 0x54c34);
      usleep(200000);
    }
    count = count + 1;
    if (2 < count) break;
    usleep(200000);
  }
  builtin_strncpy(tmp1,"send work thread eix",0x14);
  tmp1[0x14] = 't';
  tmp1[0x15] = '\0';
  puts(tmp1);
  usleep(10000000);
  return 0;
}


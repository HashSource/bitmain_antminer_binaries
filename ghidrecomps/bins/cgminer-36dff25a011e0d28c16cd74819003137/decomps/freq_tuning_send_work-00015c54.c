
void freq_tuning_send_work(freq_tuning_info *freq_info)

{
  FILE *pFVar1;
  freq_tuning_info *freq_info_local;
  send_work_parameter param [16];
  pthread_t thread_id [16];
  timeval diff;
  timeval end;
  timeval start;
  FILE *pFile_1;
  FILE *pFile;
  int chain_count;
  int done_count;
  int waiting;
  int chain;
  
  waiting = 1;
  done_count = 0;
  chain_count = 0;
  cgtime(&start);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: Frequency tuning: send work start.\n","freq_tuning.c",0x3e4,
              "freq_tuning_send_work");
    }
    fclose(pFVar1);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    thread_id[chain] = 0;
    if (((dev->chain_exist[chain] != 0) && (freq_info->test_done[chain] == false)) &&
       (freq_info->fake_done[chain] == false)) {
      chain_count = chain_count + 1;
      param[chain].chain = chain;
      param[chain].done = 0;
      pthread_create(thread_id + chain,(pthread_attr_t *)0x0,freq_tuning_send_work_one_chain,
                     param + chain);
      pthread_detach(thread_id[chain]);
    }
  }
  while (waiting != 0) {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if ((thread_id[chain] != 0) && (param[chain].done != 0)) {
        done_count = done_count + 1;
        thread_id[chain] = 0;
      }
    }
    if (done_count == chain_count) {
      waiting = 0;
    }
    else {
      sleep(1);
    }
  }
  cgtime(&end);
  diff.tv_sec = end.tv_sec - start.tv_sec;
  if (end.tv_usec - start.tv_usec < 0) {
    diff.tv_sec = diff.tv_sec + -1;
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: Frequency tuning: send work done, time cost %lds\n","freq_tuning.c",
              0x416,"freq_tuning_send_work",diff.tv_sec);
    }
    fclose(pFVar1);
  }
  return;
}


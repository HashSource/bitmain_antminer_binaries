
void PrintElapsedTime(undefined4 param_1)

{
  gettimeofday((timeval *)&end_time,(__timezone_ptr_t)0x0);
  diff_time._0_4_ = (int)end_time - (int)start_time;
  diff_time._4_4_ = end_time._4_4_ - start_time._4_4_;
  if (diff_time._4_4_ < 0) {
    diff_time._0_4_ = (int)diff_time + -1;
    diff_time._4_4_ = diff_time._4_4_ + 1000000;
  }
  printf("Timestamp %s : %d sec\n",param_1,(int)diff_time);
  return;
}


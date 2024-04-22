
/* WARNING: Unknown calling convention */

void scan_freq_prepare_log(void)

{
  char *logfile;
  
  set_privite_log_file("/tmp/freqscanlog",&scanfreq_log_bak);
  return;
}


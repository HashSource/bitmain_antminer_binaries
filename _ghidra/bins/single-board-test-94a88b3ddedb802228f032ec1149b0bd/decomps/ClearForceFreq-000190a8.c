
void ClearForceFreq(void)

{
  char acStack_108 [256];
  
  sprintf(acStack_108,"rm %s -f","/etc/config/forcefreq.txt");
  system(acStack_108);
  scan_freq_done_mark();
  return;
}


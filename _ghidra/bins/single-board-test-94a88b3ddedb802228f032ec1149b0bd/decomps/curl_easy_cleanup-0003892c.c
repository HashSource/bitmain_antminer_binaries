
void curl_easy_cleanup(int param_1)

{
  sigaction *__oact;
  sigaction sStack_98;
  byte local_c;
  
  if (param_1 != 0) {
    local_c = *(byte *)(param_1 + 0x324);
    if (local_c == 0) {
      sigpipe_ignore_isra_1_part_2(&sStack_98);
      Curl_close(param_1);
      if (local_c != 0) {
        return;
      }
      __oact = (sigaction *)0x0;
    }
    else {
      Curl_close(param_1);
      __oact = (sigaction *)(uint)local_c;
      if (__oact != (sigaction *)0x0) {
        return;
      }
    }
    sigaction(0xd,&sStack_98,__oact);
  }
  return;
}


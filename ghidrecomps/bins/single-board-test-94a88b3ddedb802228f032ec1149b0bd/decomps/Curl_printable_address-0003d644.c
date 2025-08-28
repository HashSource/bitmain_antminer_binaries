
char * Curl_printable_address(int param_1,char *param_2,socklen_t param_3)

{
  char *pcVar1;
  void *__cp;
  int __af;
  
  __af = *(int *)(param_1 + 4);
  if (__af == 2) {
    __cp = (void *)(*(int *)(param_1 + 0x18) + 4);
  }
  else {
    if (__af != 10) {
      return (char *)0x0;
    }
    __cp = (void *)(*(int *)(param_1 + 0x18) + 8);
  }
  pcVar1 = inet_ntop(__af,__cp,param_2,param_3);
  return pcVar1;
}


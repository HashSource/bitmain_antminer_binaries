
char * Curl_memrchr(uint param_1,char param_2,int param_3)

{
  uint uVar1;
  char *pcVar2;
  
  uVar1 = param_3 - 1;
  pcVar2 = (char *)(param_1 + uVar1);
  if (CARRY4(param_1,uVar1) == false) {
    if (*(char *)(param_1 + uVar1) != param_2) {
      do {
        pcVar2 = pcVar2 + -1;
        if (pcVar2 == (char *)(param_1 - 1)) goto LAB_0004f914;
      } while (*pcVar2 != param_2);
    }
  }
  else {
LAB_0004f914:
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}


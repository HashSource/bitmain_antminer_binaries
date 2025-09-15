
void printoption(int param_1,undefined4 param_2,int param_3,int param_4)

{
  char *pcVar1;
  undefined *puVar2;
  
  if (*(char *)(param_1 + 0x310) == '\0') {
    return;
  }
  if (param_3 == 0xff) {
    if (0x13 < param_4 - 0xecU) {
      Curl_infof(param_1,"%s IAC %d\n",param_2);
      return;
    }
    Curl_infof(param_1,"%s IAC %s\n",param_2,*(undefined4 *)(telnetcmds + (param_4 - 0xecU) * 4));
    return;
  }
  if (param_3 == 0xfb) {
    puVar2 = &DAT_00137588;
  }
  else if (param_3 == 0xfc) {
    puVar2 = &DAT_00137580;
  }
  else if (param_3 == 0xfd) {
    puVar2 = &DAT_0013757c;
  }
  else {
    if (param_3 != 0xfe) {
      Curl_infof(param_1,"%s %d %d\n",param_2,param_3,param_4);
      return;
    }
    puVar2 = &DAT_00137574;
  }
  if (param_4 < 0x28) {
    pcVar1 = (&telnetoptions)[param_4];
    if (pcVar1 == (char *)0x0) {
LAB_00049c4c:
      Curl_infof(param_1,"%s %s %d\n",param_2,puVar2,param_4);
      return;
    }
  }
  else {
    if (param_4 != 0xff) goto LAB_00049c4c;
    pcVar1 = "EXOPL";
  }
  Curl_infof(param_1,"%s %s %s\n",param_2,puVar2,pcVar1);
  return;
}

